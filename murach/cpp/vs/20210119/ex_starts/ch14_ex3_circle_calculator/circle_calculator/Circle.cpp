#include "Circle.h"

#include <cmath>

double Circle::get_c() const {
	return  get_d() * pi;

}
double Circle::get_d() const {
	return 2 * radius;

}
double Circle::get_a() const {
	return pi* pow(radius, 2.0);
}
