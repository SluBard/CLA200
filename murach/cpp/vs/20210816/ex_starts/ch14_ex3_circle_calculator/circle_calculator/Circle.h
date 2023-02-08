#pragma once
class Circle
{
private:
	double r;
	double pi = 3.14159;

public:
	Circle(double val = 0) {
		r = val;
	}
	double get_r() {
		return r;
	}
	void set_r(double val) {
		r = val;
	}
	double get_d();
	double get_c();
	double get_a();
};

