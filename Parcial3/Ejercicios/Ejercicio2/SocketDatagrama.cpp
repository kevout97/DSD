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

void SocketDatagrama::modeBroadcast(int broadcastPermission){
    if (setsockopt(s, SOL_SOCKET, SO_BROADCAST, (void *) &broadcastPermission, sizeof(broadcastPermission)) < 0)
        cout << "setsockopt() failed" << endl;
}

char* SocketDatagrama::recibe(int size){
    char* num = (char*)malloc(size*sizeof(char));
    unsigned int tam = sizeof(direccionForanea);
    ipCliente = (char*)malloc(sizeof(char));
    recvfrom(s, (char *) num, 2*sizeof(int), 0, (struct sockaddr *)&direccionForanea, &tam);
    strcpy(ipCliente,inet_ntoa(direccionForanea.sin_addr));
    return num;
}

char* SocketDatagrama::obtieneIPCliente(){
    return ipCliente;
}

void SocketDatagrama::envia(PaqueteDatagrama p){
    memset(&direccionForanea, 0, sizeof(direccionForanea));
    direccionForanea.sin_family = AF_INET;
    direccionForanea.sin_addr.s_addr = inet_addr(p.obtieneDireccion());/* Broadcast IP address */
    direccionForanea.sin_port = htons(p.obtienePuerto());
    int clilen = sizeof(direccionForanea);
    sendto(s, p.obtieneDatos(), p.obtieneLongitud()*sizeof(char), 0, (struct sockaddr *)&direccionForanea, clilen);
}