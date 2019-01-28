//Escriba un programa que lea una matriz de enteros de 5 x 5, y muestre la suma de sus columnas y sus filas

#include <stdio.h>
#include <stdlib.h>

int** sumaColumnasFilas(int** matriz, int filas,int columnas){
    int** total = (int**)malloc(2*sizeof(int*));
    total[0] = (int*)malloc(5*sizeof(int));
    total[1] = (int*)malloc(5*sizeof(int));
    for(int i = 0; i < filas; i ++){
        for(int j = 0; j < columnas; j++){
            total[0][i] += matriz[i][j];
        }
    }

    for(int i = 0; i < columnas; i ++){
        for(int j = 0; j < filas; j++){
            total[1][i] += matriz[j][i];
        }
    }

    return total;
}

int main(){
    int** matriz = (int**)malloc(5*sizeof(int*));
    for(int i = 0; i < 5; i++){
        matriz[i] = (int*)malloc(5*sizeof(int));
    }
    printf("Ingrese los datos en la matriz\n");

    for(int i = 0; i < 5; i++){
        printf("Fila %d: \n",(i+1));
        for(int j = 0; j < 5; j++){
            scanf("%d",&(matriz[i][j]));
        }
    }

    int** suma = sumaColumnasFilas(matriz,5,5);
    printf("Total de cada fila: ");
    for(int i = 0; i < 5; i++){
        printf("%d\t",suma[0][i]);
    }
    printf("\n");
    printf("Total de cada columna: ");
    for(int i = 0; i < 5; i++){
        printf("%d\t",suma[1][i]);
    }
    printf("\n");
}