#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include "FileClass.h"

using namespace std;

FileClass::FileClass(char* nombre,int size){
	strcpy(name,nombre);
	sizeFile = size;
}

FileClass::FileClass(){}

char* FileClass::getName(){
	return name;
}

int FileClass::getSize(){
	return sizeFile;
}

int FileClass::getSizeFile(char* nombre){
	ifstream is(nombre, ios::binary);
	is.seekg (0, is.end);
    int length = is.tellg();
    is.seekg (0, is.beg);
    is.close();
	return length;
}

void FileClass::setName(char* nombre){
	strcpy(name,nombre);
}

char* FileClass::getData(char* nombre){
	char* dataFile = (char*)malloc(sizeof(char));
	char* tmp = (char*)malloc(sizeof(char));
	ifstream infile(nombre,ifstream::binary);
	if(infile){
		infile.seekg (0, ios::end);
		int size = infile.tellg();
		dataFile = (char*)malloc(size*sizeof(char));
		infile.seekg (0, ios::beg);
		infile.read (dataFile, size);
		infile.close();
	}else{
		cout << "Error al abrir el archivo" << endl;
	}
	return dataFile;
}

void FileClass::writeFile(char* nombre,char* contenido){
	ofstream outfile(nombre,ofstream::binary);
	outfile.write(contenido,strlen(contenido));
	outfile.close();
}

void FileClass::deleteFile(char* nombre){
	if( remove( nombre ) != 0 )
		cout << "Error al eliminar el archivo" << endl;
	else
		cout << "El archivo fue eliminado" << endl;
}