//Escriba un programa que acepte una fecha del usuario en la forma mm/dd/yyyy y luego la muestra en la forma yyyymmdd
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* nuevoFormato(char*fecha);

char* nuevoFormato(char*fecha){
    char* mes = strtok(fecha,"/");
    char* dia = strtok(NULL,"/"); // La función strtok() al recibir NULL recuerda la cadena y la última palabra que devolvió y continua con la siguiente.
    char* anio = strtok(NULL,"/");

    char* nuevaFecha = (char*)malloc(8*sizeof(char));
    strcpy(nuevaFecha,anio);
    strcat(nuevaFecha,mes);
    strcat(nuevaFecha,dia);

    return nuevaFecha;
}

int main(){
    char* fecha = (char*)malloc(10*sizeof(char));
    printf("Fecha de ingreso (mm/dd/yyyy):\n");
    scanf("%s",fecha);
    printf("Ingresaste la fecha: %s\n",nuevoFormato(fecha));
}
