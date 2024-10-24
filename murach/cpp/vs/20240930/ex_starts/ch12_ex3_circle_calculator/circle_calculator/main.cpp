#include <iostream>
#include <cmath>
#include "Circle.h"

using std::cout;
using std::cin;
using std::endl;
using std::pow;
using std::round;

int main()
{
	// print name of program
	cout << "Circle Calculator" << endl << endl;

	// get radius from user
	double radius;
	cout << "Enter radius:  ";
	cin >> radius;

	// make calculations
	Circle circle(radius);
	//circle.set_r(radius);
	double diameter = circle.get_diameter();
	double circumference = circle.get_circumference();
	double area = circle.get_area();
	//double pi = 3.14159;
	//double diameter = 2 * radius;
	//double circumference = diameter * pi;
	//double area = pi * pow(radius, 2.0);

	// round to 1 decimal place
	circumference = round(circumference * 10) / 10;
	area = round(area * 10) / 10;

	// write output to console
	cout << "Diameter:      " << diameter << endl
		<< "Circumference: " << circumference << endl
		<< "Area:          " << area << endl << endl
		<< "Bye!" << endl << endl;

	// return value that indicates normal program exit
    return 0;
}