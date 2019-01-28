/* Use la instrucción switch, escriba un programa que convierta una calificación numérica en una calificación de letras. 
* Use la siguiente escala de calificación A = 90-100, B = 80-89, C = 70-79, D = 60-69, F = 0-59.
* En caso contrario imprima un mensaje de error
*/
#include <stdio.h>
#include <stdlib.h>

char conversionCalificacion(int calificacion);

char conversionCalificacion(int calificacion){
    switch(calificacion){
        case 10:
        case 9:
            return 'A';
        case 8:
            return 'B';
        case 7:
            return 'C';
        case 6:
            return 'D';
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            return 'F';
    }
}

int main(){
    printf("Ingresa la calificacion: ");
    int calificacion;
    scanf("%d",&calificacion);
    if(calificacion > 100 || calificacion < 0){
        printf("La calificacion excede los rangos permitidos\n");
    }else{
        printf("Tu calificacion en letra es: %c\n",conversionCalificacion(calificacion/10));
    }
}