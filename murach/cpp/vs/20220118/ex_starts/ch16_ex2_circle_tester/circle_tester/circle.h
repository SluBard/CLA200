#ifndef MURACH_CIRCLE_H
#define MURACH_CIRCLE_H
#include <iostream>

class Circle
{
private:
	const double pi = 3.14159;
	double radius;

public:
	// inline function definitions
	Circle(double radius_param = 0.0) {
		radius = radius_param;
	}

	double get_radius() const {
		return radius;
	}

	void set_radius(double radius_param) {
		radius = radius_param;
	}

	// function declarations
	double get_diameter() const;
	double get_circumference() const;
	double get_area() const;

	// operator declarations go here
	Circle operator+(const Circle &rhs);
	Circle operator-(const Circle &rhs);
	Circle &operator++();
	friend std::ostream& operator<<(std::ostream& s, const Circle& c);
};

#endif MURACH_CIRCLE_H