#ifndef _TEMP_H
#define _TEMP_H

class Temp
{
private:
	double Fahrenheit;
	double Celsius;
public:
	Temp();
	void set_f(double);
	double get_f() const;
	void set_c(double);
	double get_c() const;
};

#endif

