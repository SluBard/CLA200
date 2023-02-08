#include <cmath>
#include "Temp.h"

double Temp::get_C() {
	return round(C * 10) / 10;
}
void Temp::set_C(double v) {
	C = v;
	F = v * 9.0 / 5.0 + 32.0;
}
double Temp::get_F() {
	return round(F * 10) / 10;
}
void Temp::set_F(double v) {
	F = v;
	C = (v - 32.0) * 5.0 / 9.0;
}