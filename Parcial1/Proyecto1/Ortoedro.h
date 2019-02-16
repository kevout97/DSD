#ifndef ORTOEDRO_H_
#define ORTOEDRO_H_
#include "Coordenada.h"
#include "Rectangulo.h"

class Ortoedro{
private:
    Rectangulo inferior;
    Rectangulo superior;
    Rectangulo derecha;
    Rectangulo izquierda;
    Rectangulo frontal;
    Rectangulo trasero;
    Coordenada superiorDer;
    Coordenada inferiorIzq;
public:
    Ortoedro(Coordenada a,Coordenada b);
    double obtieneVolumen();
    double obtieneArea();
    Coordenada obtieneSupDer();
    Coordenada obtieneInfIzq();
};
#endif