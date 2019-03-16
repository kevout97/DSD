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

PaqueteDatagrama::PaqueteDatagrama(string cad, unsigned int tam, string ipa, int port)
{
	datos = cad;
	longitud = tam;
	ip =ipa;
	puerto=port;

}

PaqueteDatagrama::PaqueteDatagrama(unsigned int tam): longitud(tam){}

string PaqueteDatagrama::obtieneDireccion(){return ip; }

unsigned int PaqueteDatagrama::obtieneLongitud(){return longitud; }

int obtienePuerto(){return puerto; }

string PaqueteDatagrama::obtieneDatos(){return datos; }

void PaqueteDatagrama::inicializaPuerto(int port){puerto = port; }

void PaqueteDatagrama::inicializaIp(string cad){ip = cad; }

void PaqueteDatagrama::inicializaDatos(string cadena){datos = cadena; }
