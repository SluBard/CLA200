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
	Circle c;
	c.set_radius(get_radius() + rhs.get_radius());
	return c;
}
Circle Circle::operator-(const Circle& rhs) {
	Circle c;
	c.set_radius(get_radius() - rhs.get_radius());
	return c;
}
Circle& Circle::operator++() {
	++radius;
	return *this;
}
ostream& operator<<(std::ostream& out, const Circle& rhs) {
	out << "radius=" << rhs.get_radius()
		<< "|diameter=" << rhs.get_diameter()
		<< "|circumference=" << rhs.get_circumference()
		<< "|area=" << rhs.get_area() << endl;
	return out;
}
