#ifndef COURSE_PROJECT_BOOKUPDATE_H
#define COURSE_PROJECT_BOOKUPDATE_H

#include <cstring>

class BookUpdate{
    unsigned int level;
    double price;
    unsigned int quantity;
    char venue[20];
    char symbol[20];
    bool is_buy;
    unsigned int epoch_time;
public:
    BookUpdate(){}
    BookUpdate(unsigned int level_,
               double price_,
               unsigned int quantity_,
               const char *venue_,
               bool is_buy_,
               const char *symbol_,
               unsigned int epoch_time_):
               level(level_),
               price(price_),
               quantity(quantity_),
               is_buy(is_buy_),
               epoch_time(epoch_time_)
    {
        strcpy(venue,venue_);
        strcpy(symbol,symbol_);
    }
    BookUpdate(const BookUpdate& bu):level(bu.get_level()),
                                     price(bu.get_price()),
                                     quantity(bu.get_quantity()),
                                     is_buy(bu.get_is_buy()),
                                     epoch_time(bu.get_epoch())
    {
        strcpy(venue,bu.get_venue());
        strcpy(symbol,bu.get_symbol());
    }
    double get_price() const {return price;}
    unsigned int get_quantity() const {return quantity;}
    unsigned int get_level() const {return level;}
    const char * get_venue() const {return venue;}
    bool get_is_buy() const {return is_buy;}
    const char * get_symbol() const {return symbol;}
    unsigned int get_epoch() const {return epoch_time;}
};

#endif //COURSE_PROJECT_BOOKUPDATE_H