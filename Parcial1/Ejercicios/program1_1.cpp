#include<iostream>
#include<iomanip>
using namespace std;


int main()
{
	int n = 2;

	cout << (n + (++n) )<< endl;

	double precio = 78.7;

	cout << precio << endl;

	cout << fixed << precio << endl;

	cout << showpoint << precio << endl;

	cout << setprecision(2) << precio << endl;

	return 0;
}