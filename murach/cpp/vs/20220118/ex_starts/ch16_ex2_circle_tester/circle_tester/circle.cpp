#include <iostream>
#include <cmath>
#include "Circle.h"

using std::pow;
using std::ostream;
using std::endl;

// function definitions
double Circle::get_diameter() const {
	return 2 * radius;
}

double Circle::get_circumference() const {
	return get_diameter() * pi;
}

double Circle::get_area() const {
	return pi * pow(radius, 2.0);
}

// operator definitions go here
Circle Circle::operator+(const Circle& rhs) {
	Circle c(radius + rhs.get_radius());
	return c;
}
Circle Circle::operator-(const Circle& rhs) {
	Circle c(radius - rhs.get_radius());
	return c;
}
Circle& Circle::operator++() {
	++radius;
	return *this;
}
std::ostream& operator<<(std::ostream& s, const Circle& c) {
		s << "radius=" << c.get_radius()
		<< "|diameter=" << c.get_diameter()
		<< "|circumference=" << c.get_circumference()
		<< "|area=" << c.get_area() << endl;
	return s;
}