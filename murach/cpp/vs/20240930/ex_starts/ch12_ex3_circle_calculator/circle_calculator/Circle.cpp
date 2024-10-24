#include <cmath>
#include "Circle.h"

Circle::Circle() {
	r = 0;
}
Circle::Circle(double p_r) {
	r = p_r;
}

double Circle::get_diameter() {
	return 2 * r;
}
double Circle::get_circumference() {
	return get_diameter() * pi;
}
double Circle::get_area() {
	return pi * pow(r, 2.0);
}
