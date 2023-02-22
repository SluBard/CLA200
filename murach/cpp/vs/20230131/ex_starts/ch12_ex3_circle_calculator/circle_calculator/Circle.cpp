#include "Circle.h"
#include <cmath>

double Circle::get_area() {
	return pi * pow(r, 2.0);
}
double Circle::get_circumference() {
	return get_diameter() * pi;

}
double Circle::get_diameter() {
	return 2 * r;

}