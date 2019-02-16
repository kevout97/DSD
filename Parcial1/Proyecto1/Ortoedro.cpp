#include <iostream>
#include "Coordenada.h"
#include "Rectangulo.h"
#include "Ortoedro.h"
using namespace std;

Ortoedro::Ortoedro(Coordenada a,Coordenada b): inferior(a.obtenerX(),b.obtenerY(),b.obtenerX(),a.obtenerY()),
    superior(a.obtenerX(),b.obtenerY(),b.obtenerX(),a.obtenerY()),
    derecha(a.obtenerY(),b.obtenerZ(),b.obtenerY(),a.obtenerZ()),
    izquierda(a.obtenerY(),b.obtenerZ(),b.obtenerY(),a.obtenerZ()),
    frontal(a.obtenerX(),b.obtenerZ(),b.obtenerX(),a.obtenerZ()),    
    trasero(a.obtenerX(),b.obtenerZ(),b.obtenerX(),a.obtenerZ()),
    superiorDer(b.obtenerX(),b.obtenerY(),b.obtenerZ()),
    inferiorIzq(a.obtenerX(),a.obtenerY(),a.obtenerZ())
{}

Coordenada Ortoedro::obtieneSupDer(){
    return superiorDer;
}

Coordenada Ortoedro::obtieneInfIzq(){
    return inferiorIzq;
}

double Ortoedro::obtieneArea(){
    return (inferior.obtieneArea()+superior.obtieneArea()+derecha.obtieneArea()+izquierda.obtieneArea()+frontal.obtieneArea()+trasero.obtieneArea());
}

double Ortoedro::obtieneVolumen(){
    return ((inferior.obtieneArea())*(superiorDer.obtenerZ()-inferiorIzq.obtenerZ()));
}