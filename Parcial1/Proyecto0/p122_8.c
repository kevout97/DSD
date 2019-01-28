/* Escriba un programa que imprima un mes del calendario. El usuario debe especificar el numero de dias del mes
* y el dia de la semana en que inicia el mes*/

#include <stdio.h>

void imprimeMes(int dias, int inicio);

void imprimeMes(int dias, int inicio){
    int i = 1 - inicio;
    int j = 1;
    while( i < dias){
        if( i < 0){
            printf("\t");
        }else{
            printf("%d\t",(i + 1));
        }

        if( (j % 7) == 0 ){
            printf("\n");
        }
        j++;
        i++;
    }
}

int main(){
    printf("Ingresa el numero de dias: ");
    int dias;
    scanf("%d",&dias);
    printf("Ingresa el dia de inicio (1 = Domingo, 7 = Sabado): ");
    int inicio;
    scanf("%d", &inicio);
    printf("\n");
    imprimeMes(dias,inicio);
}