#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <iostream>
#include <string>
#include <string.h>
#include "Datagrama.h"

int puerto = 7200;

using namespace std;

PaqueteDatagrama::PaqueteDatagrama(char * cad, unsigned int tam, char * ipa, int port)
{
	datos = (char*)malloc(tam*sizeof(char));
	memcpy(datos,cad,tam);
	longitud = tam;
	ip = (char*)malloc(16*sizeof(char));
	memcpy(ip,ipa,16);
	puerto=port;

}

PaqueteDatagrama::PaqueteDatagrama(unsigned int tam): longitud(tam){}

char * PaqueteDatagrama::obtieneDireccion(){return ip; }

unsigned int PaqueteDatagrama::obtieneLongitud(){return longitud; }

int obtienePuerto(){return puerto; }

char * PaqueteDatagrama::obtieneDatos(){return datos; }

void PaqueteDatagrama::inicializaPuerto(int port){puerto = port; }

void PaqueteDatagrama::inicializaIp(char* ipa){
	ip = (char*)malloc(16*sizeof(char));
	memcpy(ip,ipa,16);
}

void PaqueteDatagrama::inicializaDatos(char* cad){
	datos = (char*)malloc(3000*sizeof(char));
	memcpy(datos,cad,3000);
}
