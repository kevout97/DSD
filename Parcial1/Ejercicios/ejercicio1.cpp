/*Elabore un programa que encuentre el área de un círculo declarando la constante PI, el
usuario debe proporcionar el radio. Intente modificar PI dentro del programa, ¿Qué ocurre? */

#include <iostream>
using namespace std;

int main(){
    int radio;
    const float PI = 3.1416;
    cout << "Introduce el radio de la circunferencia: ";
    cin >> radio;
    cout << "Area del circulo: " << (radio*radio*PI) << "\n";
}