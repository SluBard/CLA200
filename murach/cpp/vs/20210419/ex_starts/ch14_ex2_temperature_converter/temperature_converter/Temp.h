#pragma once
class Temp
{
private:
	double f;
	double c;
public:
	Temp();
    void set_c(double val);
    double get_c() const;
    void set_f(double val);
    double get_f() const;
};

