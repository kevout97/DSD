#include<iostream>
using namespace std;

int main(){
	double c = 20;
	double f;
	f = (static_cast<double>(9)/static_cast<double>(5))*c + 32.0;
	cout << "!!!Hola!!!.\n" << "20�C Son "<< f << " grados Farenheit";
	return 0;
}
