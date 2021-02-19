#ifndef MURACH_FINANCE_H
#define MURACH_FINANCE_H

class Finance
{
public:
	// declare program-specific function
	static double calculate_future_value(double monthly_investment,
		double yearly_interest_rate, int years);

};

#endif