#include <bits/stdc++.h>
#include "Coordenada.h"
#include "Poligono.h"
using namespace std;

Poligono::Poligono()
{
}

void Poligono::agregaVertice(double x,double y)
{
	Coordenada aux(x,y);
	coordenadas.push_back(aux);
}

void Poligono::muestraVertices()
{
	for(int i = 0; i < coordenadas.size(); i++)
	{
		cout << "X:" << coordenadas[i].obtenerX() << " Y: " << coordenadas[i].obtenerY() << endl;
	}
}