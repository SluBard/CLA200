#ifndef MURACH_DIE_H
#define MURACH_DIE_H

#include <string>

class Die {
private:
    int value;

public:
    Die();
    void roll();
    int get_value() const;
    std::string get_image() const;
    void set_value(int);
};

#endif // MURACH_DIE_H