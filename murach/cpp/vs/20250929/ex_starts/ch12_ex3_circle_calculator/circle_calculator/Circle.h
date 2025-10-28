#pragma once
class Circle
{
private:
	double r;
	const double pi = 3.14159; //aslo M_PI in <cmath>
public:
	Circle();
	Circle(double);
	void set_r(double p_r) { r = p_r; }
	double get_r() { return r; }
	double get_diameter();
	double get_circumference();
	double get_area();
};

