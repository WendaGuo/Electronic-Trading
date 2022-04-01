#ifndef COURSE_PROJECT_APPBASE_H
#define COURSE_PROJECT_APPBASE_H

#include <memory>
#include <queue>
#include "Order.h"
#include "BookUpdate.h"

class AppBase{
protected:
    bool is_working=false;
    static std::unique_ptr<std::queue<Order>> strategy_to_ordermanager;
    static std::unique_ptr<std::queue<ExecutionOrder>> ordermanager_to_strategy;
    static std::unique_ptr<std::queue<Order>> ordermanager_to_simulator;
    static std::unique_ptr<std::queue<ExecutionOrder>> simulator_to_ordermanager;
    static std::unique_ptr<std::queue<BookUpdate>> orderbook_to_strategy;
public:
    AppBase()= default;
    ~AppBase()= default;
    virtual void start()=0;
    virtual void stop()=0;
    void clear()
    {
        if (is_working)
        {
            while (!strategy_to_ordermanager->empty()) {strategy_to_ordermanager->pop();}
            while (!ordermanager_to_strategy->empty()) {ordermanager_to_strategy->pop();}
            while (!ordermanager_to_simulator->empty()) {ordermanager_to_simulator->pop();}
            while (!simulator_to_ordermanager->empty()) {simulator_to_ordermanager->pop();}
            while (!orderbook_to_strategy->empty()) {orderbook_to_strategy->pop();}
        }
    }
};

#endif //COURSE_PROJECT_APPBASE_H