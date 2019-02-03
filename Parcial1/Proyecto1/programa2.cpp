/*
Escriba un programa que imprima la altura de un edificio, si se conoce el tiempo que tardó una pelota de tenis desde que se dejó 
caer en la parte más alta del edificio y hasta llegar al piso
*/

#include <iostream>
using namespace std;

float getAltura(int tiempo);

float getAltura(int tiempo){
    return (float)(0.5*9.81*tiempo*tiempo);
}

int main(){
    int tiempo;
    cout << "Ingresa el tiempo: ";
    cin >> tiempo;
    cout << "La altura del edificio es: " << getAltura(tiempo) << "\n";
}