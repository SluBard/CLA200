#include <iostream>
#include <cmath>
#include "Circle.h"

using std::cout;
using std::cin;
using std::endl;
/*
void display(Circle circle) {
	cout << "radius=" << circle.get_radius()
		<< "|diameter=" << circle.get_diameter()
		<< "|circumference=" << circle.get_circumference()
		<< "|area=" << circle.get_area() << endl;
}
*/

int main() {
	// print name of program
	cout << "Circle Tester" << endl << endl;

	// create and display Circle object
	Circle circle1(20);
	cout << "CIRCLE 1:\n" << circle1;
	//display(circle1);
	cout << endl;

	Circle circle2(10);
	cout << "CIRCLE 2:\n"<< circle2;
	//display(circle2);
	cout << endl;

	// test the addition and subtraction operators
	Circle circle3 = circle1 + circle2;
	cout << "CIRCLE 3:\n" << circle3;
	//display(circle3);
	cout << endl;

	Circle circle4 = circle1 - circle2;
	cout << "CIRCLE 4:\n" << circle4;
	//display(circle4);
	cout << endl;

	// test the increment operator
	++circle4;
	cout << "CIRCLE 4 after ++:\n" << circle4;
	//display(circle4);
	cout << endl;
}