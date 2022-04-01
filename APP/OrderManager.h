//
// Created by Wenda Guo on 12/8/19.
//

#ifndef COURSE_PROJECT_ORDERMANAGER_H
#define COURSE_PROJECT_ORDERMANAGER_H

#include <unordered_map>
#include "AppBase.h"
#include "Order.h"
#include <iostream>

class OrderManager : public AppBase{
    unsigned number_of_open_orders=0;
    unsigned number_of_non_acknowledged_orders=0;
    unsigned int order_id;
    Order order;
    ExecutionOrder execution_order;
    std::unordered_map<unsigned int, ExecutionOrder> long_positions;
    std::unordered_map<unsigned int,ExecutionOrder> short_positions;
public:
    OrderManager():AppBase(),order_id(0){}
    void start() override {is_working=true;}
    void stop() override
    {
        number_of_non_acknowledged_orders=0;
        number_of_open_orders=0;
        long_positions.clear();
        short_positions.clear();
        is_working=false;
    }
    bool handle_order();
    bool handle_execution_order();
    double comput_p_l();
    void present_positions()
    {
        double Profit_Loss=0;
        std::cout<<"long positions size:"<<long_positions.size();
        std::cout<<", short positions size:"<<short_positions.size()<<std::endl;
            auto long_p = long_positions.begin(),short_p=short_positions.begin();
            while (long_p!=long_positions.end()&& short_p!=short_positions.end())
            {
                Profit_Loss += (short_p->second.getPrice()-long_p->second.getPrice());
                std::cout<<"Buy at "<<long_p->second.getPrice();
                std::cout<<", Sell at "<<short_p->second.getPrice()<<std::endl;
                long_p++;
                short_p++;
            }
        std::cout<<"The total P&L is "<<Profit_Loss<<std::endl;
    }
};

#endif //COURSE_PROJECT_ORDERMANAGER_H
