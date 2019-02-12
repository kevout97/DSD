#include "Fecha.h"
#include<iostream>

using namespace std;

Fecha::Fecha(int dd, int mm, int aaaa): dia(dd), mes(mm), anio(aaaa){
	if((mes < 1)|| (mes > 12)){cout << "Valor ilegal para el mes!\n";exit(1);}
	if((dia < 1)|| (dia > 31)){cout << "Valor ilegal para el dia!\n";exit(1);}
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

int Fecha::convierte(){
    int conversion = (anio * 10000) + (mes * 100) + dia;
    cout << "La conversion es: " << conversion << endl;
    return conversion;
}

bool Fecha::leapyr(){
    return (((anio%4 == 0) || (anio%400 == 0))?true:false);
}

int Fecha::masVieja(Fecha* fecha1,Fecha* fecha2){
    return (fecha1->convierte() == fecha2->convierte())?0:(fecha1->convierte() > fecha2->convierte())?1:-1;
}

int Fecha::masVieja(Fecha fecha1,Fecha fecha2){
    return (fecha1.convierte() == fecha2.convierte())?0:(fecha1.convierte() > fecha2.convierte())?1:-1;
}