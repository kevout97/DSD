/*
Se desea calcular la raíz cuadrada de un número entero n utilizando al algoritmo babilónico. 
Investigue en Internet el algoritmo y prográmelo, haciendo n del tipo double y el resultado con cuatro decimales.
*/
#include <iostream>
#include <iomanip>
using namespace std;

double getRaiz(double numero);

double getRaiz(double numero){
    double resultado = numero;
    double tmp = 0;

    while(tmp != resultado){
        tmp = resultado;
        resultado = 0.5*((numero/resultado)+resultado);
    }
    return resultado;
}

int main(){
    cout << "Ingresa el numero: ";
    double numero;
    cin >> numero;
    setprecision(4);
    cout << "La raiz cuadrada es: " << getRaiz(numero) << "\n";
}