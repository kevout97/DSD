#include "Fraccion.h"
#include <iostream>
using namespace std;
Fraccion::Fraccion(int num, int deno){
    numerador = num;
    denominador = deno;
}

void Fraccion::inicializarFraccion(int num, int deno){
    numerador = num;
    denominador = deno;
}

double Fraccion::division(){
    return ((double)numerador)/((double)denominador);
}

void Fraccion::simplificacion(){
    int i = 2;
        do{
            if((numerador%i == 0) && (denominador%i == 0)){
                numerador = numerador/i;
                denominador = denominador/i;
                i = 2;
            }else{
                i++;
            }
        }while((i < denominador) && (i < numerador));
    return;
}

void Fraccion::imprimeFraccion(){
    cout << "La Fraccion es: " << numerador << "/" << denominador << "\n";
    return;
}