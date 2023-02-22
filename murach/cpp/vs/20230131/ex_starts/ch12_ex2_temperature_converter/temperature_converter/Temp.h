#pragma once

class Temp {
private:
	double f;
	double c;

 public:
	Temp() { 
		c = 0;
		f = 32;
	}
	double get_f();
	void set_f(double);
	double get_c();
	void set_c(double);
	};
