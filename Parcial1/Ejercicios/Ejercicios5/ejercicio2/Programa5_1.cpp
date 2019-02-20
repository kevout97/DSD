#include <bits/stdc++.h>
#include "Coordenada.h"
#include "Poligono.h"
using namespace std;
int main( )
{
    Poligono poli;
    int n;
    double x, y;
    cout << "Cuantos vertices desea ingresar?";
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> x >> y;
        poli.agregaVertice(x,y);
    }
    
    poli.muestraVertices();
    return 0;
}