#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <iostream>
#include "SocketDatagrama.h"
using namespace std;

SocketDatagrama::SocketDatagrama(int port){ 
    s = socket(AF_INET, SOCK_DGRAM, 0);
    bzero((char *)&direccionLocal, sizeof(direccionLocal));
    direccionLocal.sin_family = AF_INET;
    direccionLocal.sin_addr.s_addr = INADDR_ANY;
    direccionLocal.sin_port = htons(port);
    bind(s, (struct sockaddr *)&direccionLocal, sizeof(direccionLocal));
}

SocketDatagrama::SocketDatagrama(){
    s = socket(AF_INET, SOCK_DGRAM, 0);
    bzero((char *)&direccionLocal, sizeof(direccionLocal));
    direccionLocal.sin_family = AF_INET;
    direccionLocal.sin_addr.s_addr = INADDR_ANY;
    direccionLocal.sin_port = htons(0);
    bind(s, (struct sockaddr *)&direccionLocal, sizeof(direccionLocal));
 }

int SocketDatagrama::recibe(PaqueteDatagrama p){
    char num[p.obtieneLongitud()];
    int i = 0;
    cout << "En espera de datos..." <<endl;
    int clilen = sizeof(direccionForanea);
    i = recvfrom(s, (char *) num, p.obtieneLongitud()*sizeof(char), 0, (struct sockaddr *)&direccionForanea, (socklen_t*)&clilen);;
    cout << "Te lo envio: " << inet_ntoa(direccionForanea.sin_addr) << ":"<< ntohs(direccionForanea.sin_port) << endl;
    envia(p);
}

ssize_t SocketDatagrama::envia(PaqueteDatagrama p){
    int clilen = sizeof(direccionForanea);
    string tmp = p.obtieneDatos();
    const char * datos = tmp.c_str();
    return (sendto(s, datos, p.obtieneLongitud()*sizeof(char), 0, (struct sockaddr *)&direccionForanea, clilen));
}