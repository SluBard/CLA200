#pragma once
class Temp
{
private:
	double f;
	double c;
public:
	Temp() {
		f = 32;
		c = 0;
	}
	void f_setter(double);
	void c_setter(double);
	double f_getter() const;
	double c_getter() const;
};

