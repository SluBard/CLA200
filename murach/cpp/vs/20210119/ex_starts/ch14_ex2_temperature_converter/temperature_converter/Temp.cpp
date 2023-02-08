#include "Temp.h"
#include <cmath>

Temp::Temp() {
	Fahrenheit = 32;
	Celsius = 0;
}
void Temp::set_f(double t) {
	Fahrenheit = t;
	Celsius = (Fahrenheit - 32.0) * 5.0 / 9.0;
}
double Temp::get_f() const {
	return round(Fahrenheit * 10) / 10;
}
void Temp::set_c(double t) {
	Celsius = t;
	Fahrenheit = Celsius * 9.0 / 5.0 + 32.0;
}
double Temp::get_c() const {
	return round(Celsius * 10) / 10;
}
