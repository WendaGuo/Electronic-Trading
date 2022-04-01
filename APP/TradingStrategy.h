//
// Created by Wenda Guo on 12/8/19.
//

#ifndef COURSE_PROJECT_TRADINGSTRATEGY_H
#define COURSE_PROJECT_TRADINGSTRATEGY_H

#include <iostream>
#include "AppBase.h"
#include "BookUpdate.h"
#include <stack>
#include "Order.h"
#include <map>
#include <unordered_map>
#include <string>

class Signal{
    int short_window;
    int long_window;
    double last_short=-1;
    double last_long=-1;
    double short_MA=-1;
    double long_MA=-1;
    std::map<unsigned int, double> PriceUpdate;
public:
    Signal(int short_,int long_):short_window(short_),long_window(long_){}
    void insert_bookupdate(BookUpdate& bu);
    bool is_tradable(BookUpdate& bu);
//    double compute_short_MA();
//    double compute_long_MA();
    double get_price_level();
    bool go_long();
    bool go_short();
    double get_price(unsigned int epoch)
    {
        /*This func is only used for unit test*/
        if (PriceUpdate.find(epoch)!=PriceUpdate.end())
            return PriceUpdate[epoch];
        return -1;
    }
    void clear()
    {
        double last_short=-1;
        double last_long=-1;
        double short_MA=-1;
        double long_MA=-1;
        PriceUpdate.clear();
    }
};

class Execution{
    Order order;
    bool tradable;
public:
    Execution():tradable(false){}
    bool insert_order(unsigned int timestamp_,
                      double price_,
                      unsigned int quantity_,
                      const char* venue_,
                      const char* symbol_,
                      unsigned int id_)
    {
        order.setPrice(price_);
        order.setTimestamp(timestamp_);
        order.setVenue(venue_);
        order.setSymbol(symbol_);
        order.setOrderID(id_);
        order.setQuantity(quantity_);
        return true;
    }
    bool is_tradable(){return tradable;}
    void set_tradable(bool tradable_){tradable=tradable_;}
    Order& get_order(){return order;}
};

class TradingStrategy : public AppBase{
    Signal signal;
    Execution execution;
    int order_id;
    std::stack<ExecutionOrder> rejected;
public:
    TradingStrategy(int short_window_,
                    int long_window):AppBase(),
                                     signal(short_window_,long_window),
                                     execution(),
                                     order_id(1){}
    void start() override{is_working=true;}
    void stop() override{is_working=false;signal.clear();}

    bool process_book_update(BookUpdate &bu);
    bool process_book_update();
    bool process_execution();
    bool process_market_response();
    Order& get_recent_exe()
    {
        /*for unit test*/
        if (!strategy_to_ordermanager->empty())
        {
            Order& o = strategy_to_ordermanager->front();
            strategy_to_ordermanager->pop();
            return o;
        }
        Order * o = new Order;
        return *o;
    }
    ExecutionOrder& recent_reject()
    {
        ExecutionOrder& exe = rejected.top();
        rejected.pop();
        return exe;
    }
};

#endif //COURSE_PROJECT_TRADINGSTRATEGY_H
