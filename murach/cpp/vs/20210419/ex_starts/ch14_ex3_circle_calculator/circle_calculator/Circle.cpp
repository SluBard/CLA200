#include "Circle.h"

double Circle::get_d() {
	return 2 * r;
}

double Circle::get_c() {
	return get_d() * pi;
}

double Circle::get_a() {
	return pi * r * r;
}