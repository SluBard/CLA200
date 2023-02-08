#include <iostream>
#include <cmath>
#include "Circle.h"

using std::cout;
using std::cin;
using std::endl;
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
	Circle c(radius);
	
	double diameter = c.get_d();
	double circumference = c.get_c();
	double area = c.get_a();
	

	// round to 1 decimal place
	diameter = round(diameter * 10) / 10;
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