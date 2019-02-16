#include <iostream>
#include "Ortoedro.h"
#include "Coordenada.h"
using namespace std;
int main( ){
    Ortoedro ortoedro1(Coordenada(0,0,0),Coordenada(4,5,6));
    cout << "El area es : " << ortoedro1.obtieneArea() << endl;
    cout << "El volumen es : " << ortoedro1.obtieneVolumen() << endl;
    
    return 0;
}