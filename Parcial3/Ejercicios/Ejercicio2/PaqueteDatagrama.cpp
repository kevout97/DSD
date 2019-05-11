#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <iostream>
#include <string>
#include <string.h>
#include "PaqueteDatagrama.h"

using namespace std;

PaqueteDatagrama::PaqueteDatagrama(char * cad, unsigned int tam, char * ipa, int port){
	datos = (char*)malloc(tam*sizeof(char));
	ip = (char*)malloc(16*sizeof(char));
	memcpy(datos,cad,tam);
	memcpy(ip,ipa,16);
	longitud = tam;
	puerto=port;
}

PaqueteDatagrama::PaqueteDatagrama(unsigned int tam){
	longitud = tam;
}

char * PaqueteDatagrama::obtieneDireccion(){
	return ip; 
}

unsigned int PaqueteDatagrama::obtieneLongitud(){
	return longitud; 
}

int PaqueteDatagrama::obtienePuerto(){
	return puerto; 
}

char * PaqueteDatagrama::obtieneDatos(){
	return datos; 
}

void PaqueteDatagrama::inicializaPuerto(int port){
	puerto = port; 
}

void PaqueteDatagrama::inicializaIp(char* ipa){
	ip = (char*)malloc(16*sizeof(char));
	memcpy(ip,ipa,16);
}

void PaqueteDatagrama::inicializaDatos(char* cad){
	datos = (char*)malloc(sizeof(&cad)*sizeof(char));
	memcpy(datos,cad,sizeof(&cad));
}
