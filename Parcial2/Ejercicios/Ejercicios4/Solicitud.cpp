#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <iostream>
#include "Solicitud.h"
using namespace std;

Solicitud::Solicitud(){ 
    socketlocal = new SocketDatagrama(0);
}

Solicitud::doOperation(){
    
}
