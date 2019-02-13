#ifndef RECTANGULO_H_
#define RECTANGULO_H_
#include "Coordenada.h"

class Rectangulo{
private:
    Coordenada superiorIzq;
    Coordenada inferiorDer;
public:
    Rectangulo(Coordenada c1,Coordenada c2);
    Rectangulo(double xSupIzq, double ySupIzq, double xInfDer, double yInfDer);
    void imprimeEsq();
    Coordenada obtieneSupIzq();
    Coordenada obtieneInfDer();
};
#endif