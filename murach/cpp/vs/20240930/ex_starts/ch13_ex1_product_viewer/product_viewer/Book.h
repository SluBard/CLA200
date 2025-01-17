#ifndef MURACH_BOOK_H
#define MURACH_BOOK_H

#include <string>
//#include "Product.h"
#include "Media.h"

class Book : public Media {
private:
    std::string author;
    //std::string format;
public:
    Book(std::string name = "", double price = 0.0, 
         int disc_pct = 0, std::string author_param = "", std::string format_param="") : Media(name, price, disc_pct,format_param) {
        author = author_param;
        //format = format_param;
    }

    void set_author(std::string author_param) {
        author = author_param;
    }
    std::string get_author() const {
        return author;
    }

    std::string get_description() const {
        return name + " by " + author + " " + format;
    }
};
#endif // MURACH_BOOK_H