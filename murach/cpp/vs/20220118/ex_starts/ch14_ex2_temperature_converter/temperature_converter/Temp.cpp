#include "Temp.h"
#include <cmath>

double Temp::f_getter() const {
	return round(f * 10) / 10;
}
double Temp::c_getter() const {
	return round(c * 10) / 10;
}
void Temp::f_setter(double v) {
	f = v;
	c = (f - 32.0) * 5.0 / 9.0;
}
void Temp::c_setter(double v) {
	c = v;
	f = c * 9.0 / 5.0 + 32.0;
}