#ifndef Poligono_H_
#define Poligono_H_
#include "Coordenada.h"
#include <bits/stdc++.h>
using namespace std;

class Poligono{
private:
    vector<Coordenada> coordenadas;
public:
    Poligono();
    void agregaVertice(double x, double y);
    void muestraVertices();
};
#endif