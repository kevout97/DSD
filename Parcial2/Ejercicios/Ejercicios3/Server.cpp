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
int port = 7200;
unsigned int longitud = 300;

int main(){
    SocketDatagrama sd(port);
    PaqueteDatagrama pd(longitud);
    sd.recibe(pd);
}