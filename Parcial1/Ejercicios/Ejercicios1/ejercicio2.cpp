/*Un error común difícil de detectar es dividir dos tipos de datos enteros o un entero con
un tipo flotante. Elabore un programa para imprimir el resultado de una división entre dos enteros
y de un entero con un flotante y determine cuál es el error que ocurre.*/
#include <iostream>
using namespace std;

int main(){
    int divisor, dividendo;
    float divisorf;
    cout << "*******Divisiion entre enteros******\n";
    cout << "Introduce el dividendo: ";
    cin >> dividendo;
    cout << "Introduce el divisor: ";
    cin >> divisor;
    if(divisor == 0){
        cout << "Sintaxis Error";
    }else{
        cout << "Total: " << (dividendo/divisor);
    }

    cout << "\n\n*******Division entre flotante******\n";
    cout << "Introduce el dividendo: ";
    cin >> dividendo;
    cout << "Introduce el divisor: ";
    cin >> divisorf;
    if(divisorf == 0){
        cout << "Sintaxis Error";
    }else{
        cout << "Total: " << (dividendo/divisorf) << "\n";
    }
}