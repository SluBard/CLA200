#include "Circle.h"

double Circle::get_diameter() {
	return 2 * r;
}
double Circle::get_circumference() {
	return get_diameter() * pi;
}
double Circle::get_area() {
	return pi * r * r;
}
