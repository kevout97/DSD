//Modifique el programa addfrac.c de la sección 3.2 para que el usuario ingrese ambas fracciones al mismo tiempo, separadas por un signo más
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* suma(char*expresion);

int* suma(char*expresion){
    char* fraccion1 = strtok(expresion,"+");
    char* fraccion2 = strtok(NULL,"+");

    int numerador1 = *(strtok(fraccion1,"/")) - '0';
    int denominador1 =  *(strtok(NULL,"/")) - '0';

    int numerador2 = *(strtok(fraccion2,"/")) - '0';
    int denominador2 = *(strtok(NULL,"/")) - '0';

    int totalNumerador = (numerador1 * denominador2) + (numerador2 * denominador1);
    int totalDenominador = denominador1 * denominador2;

    int* total = (int*)malloc(2*sizeof(int));
    total[0] = totalNumerador;
    total[1] = totalDenominador;

    return total;
}

int main(){
    printf("Ingresa dos fracciones separadas por un signo de suma (n1/d1+n2/d2):\n");
    char* expresion = (char*)malloc(7*sizeof(char));
    scanf("%s",expresion);
    int *total = suma(expresion);
    printf("La suma es %d/%d\n",total[0],total[1]);
}