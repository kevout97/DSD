//Escribe un programa que encuentre el más pequeño y el más grande en una serie de palabras.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FILAS 7
#define COLUMNAS 20

char* masPequenio(char** palabras);
char* masLargo(char** palabras);

char* masPequenio(char** palabras){
    int tamanio = strlen(palabras[0]);
    char* palabra = (char*)malloc(COLUMNAS*sizeof(char));
    for(int i = 0; i < FILAS; i++){
        if(strlen(palabras[i]) <= tamanio){
            tamanio = strlen(palabras[i]);
            palabra = palabras[i];
        }
    }
    return palabra;
}

char* masLargo(char** palabras){
    int tamanio = strlen(palabras[0]);
    char* palabra = (char*)malloc(COLUMNAS*sizeof(char));
    for(int i = 0; i < FILAS; i++){
        if(strlen(palabras[i]) >= tamanio){
            tamanio = strlen(palabras[i]);
            palabra = palabras[i];
        }
    }
    return palabra;
}

int main(){
    printf("Ingresa las palabras:\n");
    char** palabras = (char**)malloc(FILAS*sizeof(char*));
    for(int i = 0; i < FILAS; i++){
        palabras[i] = (char*)malloc(COLUMNAS*sizeof(char));
        scanf("%s",palabras[i]);
    }
    printf("La palabra mas pequenia es: %s\n",masPequenio(palabras));
    printf("La palabra mas larga es: %s\n",masLargo(palabras));    
}