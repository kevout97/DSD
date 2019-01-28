//Escriba un programa que calcule el factorial de un numero
#include <stdio.h>

int factorial(int numero);

int factorial(int numero){
    if(numero == 0 || numero == 1){
        return 1;
    }else{
        return numero * factorial(numero - 1);
    }
}

int main(){
    printf("Ingresa un numero: ");
    int numero;
    scanf("%d",&numero);
    printf("El factorial de %d es: %d\n",numero,factorial(numero));
}