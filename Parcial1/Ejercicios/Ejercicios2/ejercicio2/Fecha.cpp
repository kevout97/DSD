#include "Fecha.h"
#include<iostream>

using namespace std;

Fecha::Fecha(int dd, int mm, int aaaa){
	mes = mm;
	dia = dd;
	anio = aaaa;
}

void Fecha::inicializaFecha(int dd, int mm, int aaaa){
	anio = aaaa;
	dia = dd;
	mes = mm;
	return;
}

void Fecha::muestraFecha(){
	cout << "La fecha es (dia-mes-a�o): " << dia << "-" << mes << "-" << anio << endl;
	return;
}

void Fecha::convierte(){
    int conversion = (anio * 10000) + (mes * 100) + dia;
    cout << "La conversion es: " << conversion << endl;
    return;
}

bool Fecha::leapyr(){
    return (((anio%4 == 0) || (anio%400 == 0))?true:false);
}
