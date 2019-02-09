#ifndef FRACCION_H_
#define FRACCION_H_
class Fraccion{
private:
    int numerador;
    int denominador;
public:
    Fraccion(int = 1, int = 1);
    void inicializarFraccion(int,int);
    double division();
    void simplificacion();
    void imprimeFraccion();
};
#endif