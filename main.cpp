#include <iostream>
#include "AppBase.h"
#include "DataReader.h"
#include "OrderBook.h"
#include "TradingStrategy.h"
#include "OrderManager.h"
#include "MarketSimulator.h"

std::unique_ptr<std::queue<Order>> AppBase::strategy_to_ordermanager=std::make_unique<std::queue<Order>>();
std::unique_ptr<std::queue<ExecutionOrder>> AppBase::ordermanager_to_strategy=std::make_unique<std::queue<ExecutionOrder>>();
std::unique_ptr<std::queue<Order>> AppBase::ordermanager_to_simulator=std::make_unique<std::queue<Order>>();
std::unique_ptr<std::queue<ExecutionOrder>> AppBase::simulator_to_ordermanager=std::make_unique<std::queue<ExecutionOrder>>();
std::unique_ptr<std::queue<BookUpdate>> AppBase::orderbook_to_strategy=std::make_unique<std::queue<BookUpdate>>();

int main() {
    char filename1[100] = "/Users/wen/Desktop/CPP/Course Project/Trading Data/amzn_1224.csv";
    char filename2[100] = "/Users/wen/Desktop/CPP/Course Project/Trading Data/amzn_1226.csv";
    char filename3[100] = "/Users/wen/Desktop/CPP/Course Project/Trading Data/amzn_1227.csv";
    char filename4[100] = "/Users/wen/Desktop/CPP/Course Project/Trading Data/amzn_1228.csv";
    char filename5[100] = "/Users/wen/Desktop/CPP/Course Project/Trading Data/amzn_1231.csv";

    TradingStrategy ts(20,30);
    OrderManager om;
    MarketSimulator ms;


    std::cout<<"Backtest for 2018-12-24"<<std::endl;
    OrderBook MyOrderBook1(filename1,2018,12,24);
    MyOrderBook1.start();
    ts.start();
    om.start();
    ms.start();
    while (!MyOrderBook1.is_empty())
    {
        if (ts.process_book_update())
        {
            om.handle_order();
            ms.handle_order();
            om.handle_execution_order();
            om.handle_execution_order();
            ts.process_market_response();
            ts.process_market_response();
        }
    }
    om.present_positions();
    MyOrderBook1.clear();
    ts.stop();
    om.stop();
    ms.stop();
    std::cout<<"\n\n";

    std::cout<<"Backtest for 2018-12-26"<<std::endl;
    OrderBook MyOrderBook2(filename2,2018,12,26);
    MyOrderBook2.start();
    ts.start();
    om.start();
    ms.start();
    while (!MyOrderBook2.is_empty())
    {
        if (ts.process_book_update())
        {
            om.handle_order();
            ms.handle_order();
            om.handle_execution_order();
            om.handle_execution_order();
            ts.process_market_response();
            ts.process_market_response();
        }
    }
    om.present_positions();
    MyOrderBook2.clear();
    ts.stop();
    om.stop();
    ms.stop();
    std::cout<<"\n\n";


    std::cout<<"Backtest for 2018-12-27"<<std::endl;
    OrderBook MyOrderBook3(filename3,2018,12,27);
    MyOrderBook3.start();
    ts.start();
    om.start();
    ms.start();
    while (!MyOrderBook3.is_empty())
    {
        if (ts.process_book_update())
        {
            om.handle_order();
            ms.handle_order();
            om.handle_execution_order();
            om.handle_execution_order();
            ts.process_market_response();
            ts.process_market_response();
        }
    }
    om.present_positions();
    MyOrderBook3.clear();
    ts.stop();
    om.stop();
    ms.stop();
    std::cout<<"\n\n";


    std::cout<<"Backtest for 2018-12-28"<<std::endl;
    OrderBook MyOrderBook4(filename4,2018,12,28);
    MyOrderBook4.start();
    ts.start();
    om.start();
    ms.start();
    while (!MyOrderBook4.is_empty())
    {
        if (ts.process_book_update())
        {
            om.handle_order();
            ms.handle_order();
            om.handle_execution_order();
            om.handle_execution_order();
            ts.process_market_response();
            ts.process_market_response();
        }
    }
    om.present_positions();
    MyOrderBook4.clear();
    ts.stop();
    om.stop();
    ms.stop();
    std::cout<<"\n\n";


    std::cout<<"Backtest for 2018-12-31"<<std::endl;
    OrderBook MyOrderBook5(filename5,2018,12,31);
    MyOrderBook5.start();
    ts.start();
    om.start();
    ms.start();
    while (!MyOrderBook5.is_empty())
    {
        if (ts.process_book_update())
        {
            om.handle_order();
            ms.handle_order();
            om.handle_execution_order();
            om.handle_execution_order();
            ts.process_market_response();
            ts.process_market_response();
        }
    }
    om.present_positions();
    MyOrderBook5.clear();
    ts.stop();
    om.stop();
    ms.stop();
    std::cout<<"\n\n";
    return 0;
}