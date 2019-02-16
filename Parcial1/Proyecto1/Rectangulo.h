#ifndef RECTANGULO_H_
#define RECTANGULO_H_
#include "Coordenada.h"

class Rectangulo{
private:
    Coordenada superiorIzq;
    Coordenada inferiorDer;
public:
    Rectangulo(double xSupIzq, double ySupIzq, double xInfDer, double yInfDer);
    Rectangulo(Coordenada c1,Coordenada c2);
    Coordenada obtieneSupIzq();
    Coordenada obtieneInfDer();
    double obtieneArea();
};
#endif