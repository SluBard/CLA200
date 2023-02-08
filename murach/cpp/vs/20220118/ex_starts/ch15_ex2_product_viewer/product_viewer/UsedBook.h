#pragma once
#include <string>
#include "Book.h"
class UsedBook : public Book {
public:
    UsedBook(std::string name = "", double price = 0.0,
        int disc_pct = 0, std::string author = "") :
        Book(name, price, disc_pct, author) {
    }
    std::string get_description() const override  {
        return name + " by " + Book::get_author() + " (USED)";
    }
};

