#include "Temp.h"
#include <cmath>

void Temp::set_f(double v) { 
	f = v;
	c = (v - 32.0) * 5.0 / 9.0;
}
void Temp::set_c(double v) {
	c = v;
	f = v * 9.0 / 5.0 + 32.0;
}
double Temp::get_f() { 
	return round(f * 10) / 10; 
}
double Temp::get_c() {
	return round(c * 10) / 10;
}