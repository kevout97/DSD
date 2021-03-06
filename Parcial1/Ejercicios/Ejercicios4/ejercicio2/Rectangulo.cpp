#include <iostream>
#include "Coordenada.h"
#include "Rectangulo.h"
using namespace std;

Rectangulo::Rectangulo(Coordenada c1,Coordenada c2) : superiorIzq(c1.obtenerX(),c1.obtenerY()), inferiorDer(c2.obtenerX(),c2.obtenerY())
{ }

Rectangulo::Rectangulo(double xSupIzq, double ySupIzq, double xInfDer, double
yInfDer):superiorIzq(xSupIzq, ySupIzq), inferiorDer(xInfDer, yInfDer)
{ }

void Rectangulo::imprimeEsq(){
cout << "Para la esquina superior izquierda.\n";
cout << "x = " << superiorIzq.obtenerX() << " y = " << superiorIzq.obtenerY() << endl;
cout << "Para la esquina inferior derecha.\n";
cout << "x = " << inferiorDer.obtenerX() << " y = " << inferiorDer.obtenerY() << endl;
}

Coordenada Rectangulo::obtieneSupIzq(){
return superiorIzq;
}

Coordenada Rectangulo::obtieneInfDer(){
return inferiorDer;
}