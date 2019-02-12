#include "Fecha.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
    srand((int) time(0));
	Fecha f1, f2;
    for(int i = 0 ;i < 100; i++){
        f1.inicializaFecha((rand() % 31) + 1,(rand() % 12) + 1,(rand() % 3000)+1);
        f2.inicializaFecha((rand() % 31) + 1,(rand() % 12) + 1,(rand() % 3000)+1);
        cout << "Valor por referencia: " << f1.masVieja(&f1,&f2) << "\n";    
        }
}