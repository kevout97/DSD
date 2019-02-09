#include "Fecha.h"
#include <iostream>

using namespace std;

int main(){
	Fecha a, b, c(21,9,1973);
	
	b.inicializaFecha(17, 6, 2000);
	a.muestraFecha();
	b.muestraFecha();
	c.muestraFecha();
    a.convierte();
    b.convierte();
    c.convierte();
    cout << "El año a es bisiesto?: " << a.leapyr() << "\n";
    cout << "El año b es bisiesto?: " << b.leapyr() << "\n";
    cout << "El año c es bisiesto?: " << c.leapyr() << "\n";
}