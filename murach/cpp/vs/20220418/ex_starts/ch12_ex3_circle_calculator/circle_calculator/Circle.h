#pragma once
class Circle
{
private:
	double r;
	double pi = 3.14159;
public:
	Circle(double v=0) {
		r = v;
	}
	void set_radius(double v) {
		r = v;
	}
	double get_radius() {
		return r;
	}
	double get_diameter();
	double get_circumference();
	double get_area();
};

