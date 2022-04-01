#ifndef COURSE_PROJECT_DATAREADER_H
#define COURSE_PROJECT_DATAREADER_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include "boost/date_time/gregorian/gregorian.hpp"
#include "BookUpdate.h"

using namespace boost::posix_time;

class CSVReader{
    const std::string filename;
    const std::string delimeter;
    const unsigned int number_of_line;
    int year;
    int month;
    int day;
public:
    CSVReader(std::string filename_,
              int year_,
              int month_,
              int day_,
              std::string delm=",",
              unsigned int number_of_line_=10):
              filename(std::move(filename_)),
              year(year_),
              month(month_),
              day(day_),
              delimeter(std::move(delm)),
              number_of_line(number_of_line_){}
    std::vector<BookUpdate> getData()
    {
        std::vector<BookUpdate> DataList;
        unsigned int current_num_of_line=0;
        std::ifstream file(filename);
        std::string line;
        while (getline(file,line))
        {
            line.erase(std::remove(line.begin(), line.end(), '\r'), line.end());
            std::vector<std::string> vec;
            boost::algorithm::split(vec,line,boost::is_any_of(","));
            int hour,minute;
            if (vec[1].length()==3)
            {
                hour = std::stoi(vec[1].substr(0,1));
                minute = std::stoi(vec[1].substr(1,2));
            }else{
                hour = std::stoi(vec[1].substr(0,2));
                minute = std::stoi(vec[1].substr(2,2));
            }
            ptime time(boost::gregorian::date(year,month,day),time_duration(hour,minute,0));
            ptime start_date(boost::gregorian::date(1970,1,1));
            time_duration td = time-start_date;
            unsigned int epoch = td.total_seconds();

            BookUpdate bu(0,std::stod(vec[5]),1,"JPM",false,"AMZN",epoch);

            DataList.push_back(bu);

            if(number_of_line!=0 and current_num_of_line++>=number_of_line)
            {
                break;
            }
        }
        return DataList;
    }
};

#endif //COURSE_PROJECT_DATAREADER_H
