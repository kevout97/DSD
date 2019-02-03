/*
Escriba un programa que reciba del usuario un valor entero de tiempo en segundos, y que imprima su equivalente en horas, minutos y segundos. 
Por ejemplo si el usuario introduce 50381, entonces el programa debe imprimir:13 horas, 59 minutos y 41 segundos.
*/

#include <iostream>
using namespace std;

int getHoras(int tiempo);
int getMinutos(int tiempo);
int getSegundos(int tiempo);

int getHoras(int tiempo){
    return (tiempo/60)/60;
}

int getMinutos(int tiempo){
    return (tiempo/60)%60;
}

int getSegundos(int tiempo){
    return tiempo%60;
}

int main(){
    int tiempo;
    cout << "Ingresa los segundos: ";
    cin >> tiempo;
    cout << getHoras(tiempo) << " horas, " << getMinutos(tiempo) << " minutos y " << getSegundos(tiempo) << " segundos.\n";
}