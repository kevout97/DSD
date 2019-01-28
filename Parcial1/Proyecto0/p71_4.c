//Escriba un programa que lea un entero ingresado por el usuario e imprima su valor en octal (base8)
#include <stdio.h>
#include <stdlib.h>

void octal(int numero);

void octal(int numero){
    if(numero != 0){
        octal(numero/8);
        printf("%d", (numero % 8));
    }
}

int main(){
    printf("Ingresa un numero entre 0 y 32767:\n");
    int numero;
    scanf("%d",&numero);
    printf("En octal, tu numero es:");
    octal(numero);
    printf("\n");
}