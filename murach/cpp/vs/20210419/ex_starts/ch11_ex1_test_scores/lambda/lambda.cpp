// lambda.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
	map<string, double> products = {
		{ "guitar", 199.99 },
		{ "piano", 799.99 },
		{ "drums", 249.99 },
		{ "violin", 489.99 }
	};
	
	int limit = 500;     // external variable
	auto under = [&](pair<string, double> p) -> bool { return p.second < limit; };
	auto num_low = count_if(products.begin(), products.end(), under);
	cout << num_low << "\n";
	                     // num_low is 3
	limit = 200;         // change the value of the external variable
	num_low = count_if(products.begin(), products.end(), under);
	cout << num_low << "\n";
	                     // num_low is 1 

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
