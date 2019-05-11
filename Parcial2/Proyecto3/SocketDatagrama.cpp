#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <iostream>
#include "SocketDatagrama.h"
using namespace std;

SocketDatagrama::SocketDatagrama(int port){//Inicializa el servidor 
    s = socket(AF_INET, SOCK_DGRAM, 0);
    bzero((char *)&direccionLocal, sizeof(direccionLocal));
    direccionLocal.sin_family = AF_INET;
    direccionLocal.sin_addr.s_addr = INADDR_ANY;
    direccionLocal.sin_port = htons(port);
    bind(s, (struct sockaddr *)&direccionLocal, sizeof(direccionLocal));
    cout << "Servidor inicializado..." << endl;
}

int SocketDatagrama::createSocket(int port, char* ip){//Create un socket para la conexion a otro server
    int sc = socket(AF_INET, SOCK_DGRAM, 0);
    bzero((char *)&direccionForanea, sizeof(direccionForanea));
    direccionForanea.sin_family = AF_INET;
    direccionForanea.sin_addr.s_addr = inet_addr(ip);
    direccionForanea.sin_port = htons(port);
    return sc;
}


char* SocketDatagrama::recibe(int size){
    char* num = (char*)malloc(size*sizeof(char));
    ipCliente = (char*)malloc(sizeof(char));
    unsigned int tam = sizeof(direccionForanea);
    recvfrom(s, (char *) num, size*sizeof(char), 0, (struct sockaddr *)&direccionForanea, &tam);
    strcpy(ipCliente,inet_ntoa(direccionForanea.sin_addr));
    return num;
}

char* SocketDatagrama::obtieneIPCliente(){
    return ipCliente;
}

void SocketDatagrama::envia(PaqueteDatagrama p){
    int sc = createSocket(p.obtienePuerto(),p.obtieneDireccion());
    int clilen = sizeof(direccionForanea);
    sendto(sc, p.obtieneDatos(), p.obtieneLongitud()*sizeof(char), 0, (struct sockaddr *)&direccionForanea, clilen);
}