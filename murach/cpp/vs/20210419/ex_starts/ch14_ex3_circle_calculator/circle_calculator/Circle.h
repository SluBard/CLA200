#pragma once
class Circle
{
private:
	const double pi = 3.14159;
	double r;

public:
	//inline
	Circle(double val = 0.0) {
		r = val;
	}

	double get_r() const {
		return r;
	}

	void set_r(double val) {
		r = val;
	}

	// not inline
	double get_d();
	double get_c();
	double get_a();

};


