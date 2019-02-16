#include <iostream>
#include "Coordenada.h"
#include "Rectangulo.h"
using namespace std;


Rectangulo::Rectangulo(double xSupIzq, double ySupIzq, double xInfDer, double yInfDer):superiorIzq(xSupIzq, ySupIzq), inferiorDer(xInfDer, yInfDer)
{ }

Rectangulo::Rectangulo(Coordenada c1,Coordenada c2) : superiorIzq(c1.obtenerX(),c1.obtenerY()), inferiorDer(c2.obtenerX(),c2.obtenerY())
{ }

Coordenada Rectangulo::obtieneSupIzq(){
    return superiorIzq;
}

Coordenada Rectangulo::obtieneInfDer(){
    return inferiorDer;
}

double Rectangulo::obtieneArea(){
    return ((inferiorDer.obtenerX()-superiorIzq.obtenerX())*(superiorIzq.obtenerY()-inferiorDer.obtenerY()));
}