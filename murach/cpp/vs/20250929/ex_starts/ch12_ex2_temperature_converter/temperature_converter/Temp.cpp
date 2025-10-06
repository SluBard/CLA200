#include <cmath>
#include "Temp.h"

double to_celsius(double fahrenheit);
double to_fahrenheit(double celsius);

Temp::Temp() {
	c = 0;
	f = 32;
}

void Temp::set_c(double p_c) {
	c = p_c;
	f = to_fahrenheit(p_c);
}

void Temp::set_f(double p_f) {
	f = p_f;
	c = to_celsius(p_f);
}

double Temp::get_c() const {
	return round(c * 10) / 10;
}

double Temp::get_f() const {
	return round(f * 10) / 10;
}

double to_celsius(double fahrenheit) {
	double celsius = (fahrenheit - 32.0) * 5.0 / 9.0;
	return celsius;
}

double to_fahrenheit(double celsius) {
	double fahrenheit = celsius * 9.0 / 5.0 + 32.0;
	return fahrenheit;
}