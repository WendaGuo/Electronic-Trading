#include <gtest/gtest.h>
#include <memory>
#include <queue>
#include "OrderBook.h"
#include "OrderManager.h"
#include "TradingStrategy.h"
#include "MarketSimulator.h"

std::unique_ptr<std::queue<Order>> AppBase::strategy_to_ordermanager=std::make_unique<std::queue<Order>>();
std::unique_ptr<std::queue<ExecutionOrder>> AppBase::ordermanager_to_strategy=std::make_unique<std::queue<ExecutionOrder>>();
std::unique_ptr<std::queue<Order>> AppBase::ordermanager_to_simulator=std::make_unique<std::queue<Order>>();
std::unique_ptr<std::queue<ExecutionOrder>> AppBase::simulator_to_ordermanager=std::make_unique<std::queue<ExecutionOrder>>();
std::unique_ptr<std::queue<BookUpdate>> AppBase::orderbook_to_strategy=std::make_unique<std::queue<BookUpdate>>();


TEST(OrderBookTests, OrderBookEmptyByDefault)
{
    OrderBook book("",2018,1,1);
    EXPECT_TRUE(book.is_empty());
}

TEST(StrategyTests, SignalWorks)
{
    Signal signal(5,10);
    BookUpdate bu1(0,1.23,10,"SEB",true,"C++",0);
    BookUpdate bu2(0,3.21,10,"SEB",false,"C++",10);
    signal.insert_bookupdate(bu1);
    signal.insert_bookupdate(bu2);
    EXPECT_EQ(1.23,signal.get_price(0));
    EXPECT_EQ(3.21,signal.get_price(10));
    EXPECT_EQ(-1,signal.get_price(100));
    EXPECT_FALSE(signal.go_long());
}




TEST(StrategyTests, StrategyWorks)
{
    TradingStrategy ts(2,4);
    ts.start();
    double prices[10]={5,2,1,2,3,4,6,7,8,9};
    unsigned int epoch=0;
    for (double pr:prices)
    {
        BookUpdate bu(0,pr,10,"",true,"",epoch++);
        ts.process_book_update(bu);
    }
    Order& o = ts.get_recent_exe();
    EXPECT_EQ(3,o.getPrice());
    EXPECT_EQ(4,o.getTimeStamp());
    ts.stop();
}


TEST(SimulatorTests, SimulatorWorks)
{
    TradingStrategy ts(2,4);
    OrderManager om;
    MarketSimulator ms;
    ts.start();
    om.start();
    ms.start();
    double prices[10]={5,2,1,2,3,4,6,7,8,9};
    unsigned int epoch=0;
    for (double pr:prices)
    {
        BookUpdate bu(0,pr,0,"",true,"",epoch++);
        ts.process_book_update(bu);
        om.handle_order();
        ms.handle_order();
        om.handle_execution_order();
        ts.process_market_response();
    }
    ExecutionOrder& exe = ts.recent_reject();
    EXPECT_EQ(orderstate::REJECTED,exe.getState());
    EXPECT_EQ(0,exe.getQuantity());
}

TEST(ManagerTest, ProfitCalculates)
{
    TradingStrategy ts(2,4);
    OrderManager om;
    MarketSimulator ms;
    ts.start();
    om.start();
    ms.start();
    double prices[15]={5,2,1,2,3,4,6,7,8,6,5,4,2};
    unsigned int epoch=0;
    for (double pr:prices)
    {
        BookUpdate bu(0,pr,1,"",true,"",epoch++);
        if (ts.process_book_update(bu))
        {
            om.handle_order();
            ms.handle_order();
            om.handle_execution_order();
            om.handle_execution_order();
            ts.process_market_response();
            ts.process_market_response();
        }
    }
    EXPECT_EQ(2,om.comput_p_l());
    ts.stop();
    om.stop();
    ms.stop();
}