#pragma once
class Temp
{
private:
	double F;
	double C;
public:
	Temp() {
		F = 32;
		C = 0;
	}
	double get_F();
	void set_F(double);
	double get_C();
	void set_C(double);
};

