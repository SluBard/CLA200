#pragma once
#include "Product.h"
#include <string>

class Media : public Product
{
protected:
	std::string format;
public:
	Media(std::string name = "", double price = 0.0,
            int disc_pct = 0, std::string format_param = "") : Product(name, price, disc_pct) {
         format = format_param;
    }
};

