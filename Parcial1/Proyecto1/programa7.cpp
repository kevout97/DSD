/*Elabore un programa para encontrar los números primos menores al valor N que introduzca el usuario, mediante el algoritmo de la Criba de Eratóstenes:
http://es.wikipedia.org/wiki/Criba_de_Erat%C3%B3stenes
Use un template vector para almacenar objetos de una clase, cuyos miembros son los números enteros y un dato tipo bool, para descartar al objeto en el caso de que no sea primo (originalmente todos los elementos del vector tienen un valor true en este dato miembro).*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void mostrar_criba(vector<int> criba){
    cout << endl;

    for (int i = 0; i < criba.size(); i++)
        cout << criba[i] << "\t";

    cout << endl;

}

vector<int> criba_eratostenes(int n){
    vector<int> criba;
    int current_primo;  // numero primo que iremos tomando del vector

    // vector con numeros desde 2 hasta n
    for (int i = 2; i <= n; i++)
        criba.push_back(i);
        
    if (n == 2 || n == 3) 
        return criba;

    // iterador para el vector criba
    vector<int>::iterator it = criba.begin();

    current_primo = *it;  // El primer primo es el 2

    do{
        vector<int>::iterator it2 = it + 1;

        for(; it2 <= criba.end(); it2++)
            if(*it2 % current_primo == 0)
                criba.erase(it2);

        it++;
        current_primo = *it;

    } while (pow(current_primo, 2) < n);

    return criba;
}

int main(){
    int n;      // Limite de criba
    vector<int> num_primos;
    cout << "Número límite: ";
    cin >> n;
    num_primos = criba_eratostenes(n);
    mostrar_criba(num_primos);

    return 0;
}