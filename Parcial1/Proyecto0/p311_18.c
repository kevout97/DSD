//Escriba un programa que acepte una fecha del usuario en la forma mm / dd / yyyy y luego la muestre en la forma mes dd, yyyy donde 
//mes es el nombre del mes
//gcc p311_18.c -lm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char* obtenerMes(int mes);
char* nuevaFecha(char* fecha);
int caracter_a_entero(char* numero);

int caracter_a_entero(char* numero){
    int decimal;
    for(int i = 0; i < strlen(numero); i++){
        decimal += (numero[i] - '0') * (int)pow(10,strlen(numero) - i - 1);
    }
    return decimal;
}

char* obtenerMes(int mes){
    char** meses = (char**)malloc(12*sizeof(char*));
    for(int i = 0; i < 12; i++){
        meses[i] = (char*)malloc(30*sizeof(char*));
    }
    strcpy(meses[0],"Enero");
    strcpy(meses[1],"Febrero");
    strcpy(meses[2],"Marzo");
    strcpy(meses[3],"Abril");
    strcpy(meses[4],"Mayo");
    strcpy(meses[5],"Junio");
    strcpy(meses[6],"Julio");
    strcpy(meses[7],"Agosto");
    strcpy(meses[8],"Septiembre");
    strcpy(meses[9],"Octubre");
    strcpy(meses[10],"Noviembre");
    strcpy(meses[11],"Diciembre");

    return meses[mes - 1];
}

char* nuevaFecha(char*fecha){
    char* mes = strtok(fecha,"/");
    char* dia = strtok(NULL,"/"); // La función strtok() al recibir NULL recuerda la cadena y la última palabra que devolvió y continua con la siguiente.
    char* anio = strtok(NULL,"/");

    char* nuevaFecha = (char*)malloc(50*sizeof(char));
    strcpy(nuevaFecha,obtenerMes(caracter_a_entero(mes)));
    strcat(nuevaFecha," ");
    strcat(nuevaFecha,dia);
    strcat(nuevaFecha,", ");
    strcat(nuevaFecha,anio);

    return nuevaFecha;
}

int main(){
    printf("Ingrese la fecha (mm/dd/yyyy): ");
    char* fecha = (char*)malloc(sizeof(char)*10);
    scanf("%s",fecha);
    printf("La fecha que ingresaste es: %s\n",nuevaFecha(fecha));
}