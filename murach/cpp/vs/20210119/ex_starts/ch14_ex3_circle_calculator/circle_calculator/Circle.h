#ifndef _CIRCLE_H
#define _CIRCLE_H

class Circle
{
private:
	double radius;
	const double pi = 3.14159;
public:
	Circle() { set_r(0); }
	void set_r(double r) { radius = r; }
	double get_r() const { return radius; }
	double get_c() const;
	double get_d() const;
	double get_a() const;
};

#endif

