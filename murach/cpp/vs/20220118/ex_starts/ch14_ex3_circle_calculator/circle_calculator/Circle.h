#pragma once
class Circle
{
private:
	double r;
	const double pi = 3.14159;
public:
	Circle(double v=0) { r = v; }
	void r_setter(double v) { r = v; }
	double r_getter() const { return r;  }
	double d_getter() const;
	double c_getter() const;
	double a_getter() const;
};

