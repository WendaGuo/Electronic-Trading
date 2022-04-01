//
// Created by Wenda Guo on 12/8/19.
//

#ifndef COURSE_PROJECT_MARKETSIMULATOR_H
#define COURSE_PROJECT_MARKETSIMULATOR_H

#include <AppBase.h>
#include <Order.h>
#include <map>

class MarketSimulator : public AppBase{
    unsigned int execution_id;
public:
    MarketSimulator():AppBase(),execution_id(0){}
    bool handle_order()
    {
        if (!is_working)
            return false;
        if(ordermanager_to_simulator->empty())
            {return true;}
        const Order &o = ordermanager_to_simulator->front();
        ordermanager_to_simulator->pop();

        ExecutionOrder new_execution(o);

        if (o.getQuantity()>0)
        {
            new_execution.setState(orderstate::ACKNOWLEDGED);
            new_execution.setExecutionID(execution_id++);
            simulator_to_ordermanager->push(new_execution);
            new_execution.setState(orderstate::FILLED);
            simulator_to_ordermanager->push(new_execution);
        }else{
            new_execution.setState(orderstate::REJECTED);
            new_execution.setExecutionID(execution_id++);
            simulator_to_ordermanager->push(new_execution);
        }
        return true;
    }
    void start() override {is_working=true;}
    void stop() override {is_working=false;}
};

#endif //COURSE_PROJECT_MARKETSIMULATOR_H
