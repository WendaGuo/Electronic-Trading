//
// Created by Wenda Guo on 12/8/19.
//

#include "TradingStrategy.h"

void Signal::insert_bookupdate(BookUpdate &bu)
{
    if (PriceUpdate.size()<long_window)
    {
        PriceUpdate[bu.get_epoch()] = bu.get_price();
    }else{
        PriceUpdate.erase(PriceUpdate.begin()->first);
        PriceUpdate[bu.get_epoch()] = bu.get_price();
    }
    if (PriceUpdate.size()>=short_window)
    {
        double sum=0;
        auto get_bu=PriceUpdate.rbegin();
        while (std::distance(PriceUpdate.rbegin(),get_bu)<short_window)
        {
            sum += get_bu->second;
            get_bu++;
        }
        last_short = short_MA;
        short_MA = sum/short_window;
    }
    if (PriceUpdate.size()==long_window)
    {
        double sum=0;
        auto get_bu=PriceUpdate.rbegin();
        while (std::distance(PriceUpdate.rbegin(),get_bu)<long_window)
        {
            sum += get_bu->second;
            get_bu++;
        }
        last_long = long_MA;
        long_MA = sum/long_window;
    }
}

//double Signal::compute_short_MA()
//{
//    if (PriceUpdate.size()<short_window)
//        return -1;
//    else{
//        double sum=0;
//        auto start = PriceUpdate.rbegin();
//        for (int i=0;i<short_window;i++)
//        {
//            sum += start->second;
//            start++;
//        }
//        short_MA=sum/short_window;
//        return sum/short_window;
//    }
//}

//double Signal::compute_long_MA()
//{
//    if (PriceUpdate.size()<long_window)
//        return -1;
//    else{
//        double sum=0;
//        auto start = PriceUpdate.rbegin();
//        for (int i=0;i<long_window;i++)
//        {
//            sum += start->second;
//            start++;
//        }
//        long_MA=sum/long_window;
//        return sum/long_window;
//    }
//}

bool Signal::is_tradable(BookUpdate &bu) {return true;}

double Signal::get_price_level()
{
    return PriceUpdate.rbegin()->second;
}

bool Signal::go_long()
{
    if (short_MA>0 && long_MA>0 && last_long>0 && last_short>0)
    {
        if (short_MA>long_MA && last_short<last_long)
            return true;
    }
    return false;
}

bool Signal::go_short()
{
    if (short_MA>0 && long_MA>0 && last_long>0 && last_short>0)
    {
        if (short_MA<long_MA && last_short>last_long)
            return true;
    }
    return false;
}

bool TradingStrategy::process_book_update(BookUpdate &bu)
{
    if (!is_working)
        return false;
    if (signal.is_tradable(bu))
    {
        execution.insert_order(bu.get_epoch(),
                               bu.get_price(),
                               bu.get_quantity(),
                               bu.get_venue(),
                               bu.get_symbol(),
                               order_id++);
        signal.insert_bookupdate(bu);
        execution.set_tradable(true);
    }
    return process_execution();
}

bool TradingStrategy::process_book_update()
{
    if (!is_working)
        return false;
    if (orderbook_to_strategy->empty())
        return true;
    BookUpdate& bu = orderbook_to_strategy->front();
    orderbook_to_strategy->pop();
    return process_book_update(bu);
}

bool TradingStrategy::process_execution()
{
    if (!is_working)
        return false;
    bool go_long = signal.go_long();
    bool go_short = signal.go_short();

    if (go_long || go_short)
    {

        Order o;
        o.setType(execution.get_order().getOrderType());
        o.setVenue(execution.get_order().getVenue());
        o.setQuantity(execution.get_order().getQuantity());
        o.setPrice(execution.get_order().getPrice());
        o.setOrderID(execution.get_order().getID());
        o.setSymbol(execution.get_order().getSymbol());
        o.setTimestamp(execution.get_order().getTimeStamp());
        execution.set_tradable(false);
        o.setSide(go_long);
        strategy_to_ordermanager->push(o);
        return true;
    }
    return false;
}

bool TradingStrategy::process_market_response()
{
    if (ordermanager_to_strategy->empty())
        return true;
    ExecutionOrder& exe = ordermanager_to_strategy->front();
    ordermanager_to_strategy->pop();
    if (exe.getState()==orderstate::REJECTED)
        rejected.push(exe);
    return true;
}