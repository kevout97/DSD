#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <iostream>
#include "PaqueteDatagrama.h"

using namespace std;
class SocketDatagrama{
public:
    SocketDatagrama(int);
    int createSocket(int,char*);
    char* recibe(int size);
    void envia(PaqueteDatagrama p);
    char* obtieneIPCliente();
private:
    struct sockaddr_in direccionLocal;
    struct sockaddr_in direccionForanea;
    int s;
    char* ipCliente;
};