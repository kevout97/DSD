//Escriba un programa que imprima cuantos digitos tiene un numero. Asuma que el numero no tendrá mas de 4 digitos
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int contarDigitos(char* numero);

int contarDigitos(char* numero){
    return strlen(numero);
}

int main(){
    printf("Ingresa un numero:\n");
    char* numero = (char*)malloc(4*sizeof(char));
    scanf("%s",numero);
    printf("El numero %s tiene %d digitos\n",numero,contarDigitos(numero));
}

