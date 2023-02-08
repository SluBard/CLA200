#include "Circle.h"

double Circle::c_getter() const {
	return  d_getter() * pi;
}
double Circle::d_getter() const {
	return 2 * r;
}
double Circle::a_getter() const {
	return pi * r * r;
}