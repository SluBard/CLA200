#pragma once
class Circle
{
private:
	double r;
	const double pi = 3.14159;
public:
	Circle(double v=0) {
		r = v;
	}
	double get_r() {
		return r;
	}
	void set_r(double v) {
		r = v;
	}
	double get_diameter();
	double get_circumference();
	double get_area();
};

