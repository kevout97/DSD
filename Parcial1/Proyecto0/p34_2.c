//Escriba un programa que calcule el volumen de una esfera con un radio de 10 metros
//gcc -o p1 p34_2.c -lm
#include <stdio.h>
#include <math.h>
#define PI 3.1416

float volumen(int radio);

float volumen(int radio){
    return (4.0f/3.0f)*PI*((float)pow(radio,3));
}

int main(){
    int radio;
    printf("Ingresa el radio de la esfera:\n");
    scanf("%d",&radio);
    printf("El volumen de la esfera es %.2f\n",volumen(radio));
}