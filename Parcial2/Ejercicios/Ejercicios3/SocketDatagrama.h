#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <iostream>
#include "Datagrama.h"
using namespace std;
class SocketDatagrama{
public:
    SocketDatagrama(int);
    SocketDatagrama();
    int recibe(PaqueteDatagrama p);
    ssize_t envia(PaqueteDatagrama p);
private:
    struct sockaddr_in direccionLocal;
    struct sockaddr_in direccionForanea;
    int s;
};