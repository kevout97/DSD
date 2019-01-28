#!/bin/bash
#Script para unir los archivos .c de un directorio
#Los parametros que recibe el script es el directorio, el nombre del archivo final

#Ejemplo de ejecucion: ./unirArchivos.sh Proyecto0 Kevin_Gomez_Gonzalez_DSD_4CM1_0.txt 

touch $2
for file in $(ls $1 | grep .c); do 
    echo "$(cat $1/$file)" >> $2
    echo "***************************************************************************************************************************************************" >> $2
done
echo "Consultar el archivo $2"