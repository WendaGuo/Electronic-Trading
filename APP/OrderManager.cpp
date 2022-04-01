//
// Created by Wenda Guo on 12/8/19.
//

#include "OrderManager.h"

bool OrderManager::handle_order()
{
    if(!is_working)
        return false;
    if (strategy_to_ordermanager->empty())
        {return true;}
    const Order &o = strategy_to_ordermanager->front();
    strategy_to_ordermanager->pop();
    number_of_open_orders++;
    ordermanager_to_simulator->push(o);
    return true;
}

bool OrderManager::handle_execution_order()
{
    if(!is_working)
        return false;
    if (simulator_to_ordermanager->empty())
        return true;

    const ExecutionOrder &e = simulator_to_ordermanager->front();
    if (e.isBuy() && e.getState()==orderstate::FILLED)
        long_positions[e.getTimeStamp()] = e;
    else if ((!e.isBuy()) && e.getState()==orderstate::FILLED)
        short_positions[e.getTimeStamp()] = e;
    simulator_to_ordermanager->pop();
    ordermanager_to_strategy->push(e);
    return true;
}

double OrderManager::comput_p_l()
{
    double Profit_Loss=0;
    auto long_p = long_positions.begin(),short_p=short_positions.begin();
    while (long_p!=long_positions.end()&& short_p!=short_positions.end())
    {
        Profit_Loss += (short_p->second.getPrice()-long_p->second.getPrice());
        long_p++;
        short_p++;
    }
    return Profit_Loss;
}