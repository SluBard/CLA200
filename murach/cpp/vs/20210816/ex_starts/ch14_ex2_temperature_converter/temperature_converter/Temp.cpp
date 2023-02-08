#include <cmath>
#include "Temp.h"

Temp::Temp() {
	f = 32;
	c = 0;
}
double Temp::get_f() {
	return round(f * 10) / 10;
}
double Temp::get_c() {
	return round(c * 10) / 10;
}
void Temp::set_c(double val) {
	c = val;
	f = val * 9.0 / 5.0 + 32.0;
}
void Temp::set_f(double val) {
	f = val;
	c = (val - 32.0) * 5.0 / 9.0;
}