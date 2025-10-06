#pragma once
class Temp
{
private:
	double f;
	double c;

public:
	Temp();
	void set_c(double);
	void set_f(double);
	double get_c() const;
	double get_f() const;
};

