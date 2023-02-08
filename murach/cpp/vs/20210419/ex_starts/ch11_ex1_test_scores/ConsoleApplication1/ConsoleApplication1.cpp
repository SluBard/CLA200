// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	vector<int> times{ 1800, 1845, 0, 2000, 0, 1745, 1600, 0, 1530 };
	cout << "Original vector\n";
	for (auto i : times) {
		cout << i << " ";
	}
	cout << "\n\n";
	auto iter = remove(times.begin(), times.end(), 0);
	cout << "Modified vector prior to erasing elements\n";
	for (auto i : times) {
		cout << i << " ";
	}
	cout << "\n\n";
	cout << "The iterator returned by the remove is pointing to the last 1600\n";
	cout << "Then we call erase to remove from that point to the end\n";
	cout << "\n\n";
	times.erase(iter, times.end());
	cout << "Modified vector after erasing elements\n";
	for (auto i : times) {
		cout << i << " ";
	}
	cout << "\n";
}
