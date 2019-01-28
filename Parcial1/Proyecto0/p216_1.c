/*
Escriba un programa que le pida al usuario que ingrese una serie de enteros (que almacena en una matriz) luego ordena los enteros llamando a la función selection_sort.
y ordene de menor a mayor los numeros de dicho arreglo
*/
#include <stdio.h>
#include <stdlib.h>

int* selection_sort(int* matriz,int tamanio){
    int i = 0, tmp = matriz[0];
    while( i < tamanio){
        if(tmp > matriz[i]){
            matriz[i-1] = matriz[i];
            matriz[i] = tmp;
            tmp = matriz[0];
            i = 0;
        }else{
            tmp = matriz[i];
            i++;
        }
    }
    return matriz;
}

void imprimeMatriz(int* matriz, int tamanio){
    for(int i = 0; i < tamanio; i++){
        printf("%d\t",matriz[i]);
    }
}

int main(){
    printf("Indique el tamaño de la matriz: ");
    int tamanio;
    scanf("%d", &tamanio);
    int* matriz = (int*)malloc(tamanio * sizeof(int));
    printf("Ingrese los numeros: \n");
    for(int i = 0; i < tamanio; i++){
        scanf("%d",&(matriz[i]));
    }
    int* final = selection_sort(matriz,tamanio);
    printf("Maytriz final: ");
    imprimeMatriz(final,tamanio);
    printf("\n");
}