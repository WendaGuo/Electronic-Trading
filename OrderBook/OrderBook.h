//
// Created by Wenda Guo on 12/4/19.
//

#ifndef COURSE_PROJECT_ORDERBOOK_H
#define COURSE_PROJECT_ORDERBOOK_H

#include "AppBase.h"
#include "DataReader.h"
#include "BookUpdate.h"

class OrderBook : public AppBase{
    std::string filename;
    int year;
    int month;
    int day;
public:
    OrderBook(const char* filename_,
              int year_,
              int month_,
              int day_):AppBase(),
                        filename(filename_),
                        year(year_),
                        month(month_),
                        day(day_){}
    void start() override{
        is_working=true;
        CSVReader MyReader(filename,year,month,day,",",775);
        std::vector<BookUpdate> datalist = MyReader.getData();
        for (const BookUpdate& bu : datalist)
        {
            orderbook_to_strategy->push(bu);
        }
    }

    void stop() override {
        is_working=false;
    }

    void ReadBook()
    {
        while (!(*orderbook_to_strategy).empty())
        {
            const BookUpdate& bu = orderbook_to_strategy->front();
            orderbook_to_strategy->pop();
            std::cout<<"update time: "<<bu.get_epoch();
            std::cout<<", price = "<<bu.get_price()<<std::endl;
        }
    }
    bool is_empty(){return orderbook_to_strategy->empty();}
};



#endif //COURSE_PROJECT_ORDERBOOK_H
