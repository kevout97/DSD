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
#include <thread>
#include "SocketDatagrama.h" 
using namespace std;
//sudo ./DescubriendoIpC 192.168.1.255
// 192.168.1.55 ----> Ip de Broadcast
int puerto = 7200;

int main(int arg, char* argv[]){
    int num[2];
    num[0] = 5; num[1] = 3;
    SocketDatagrama sd(puerto);
    sd.modeBroadcast(1); // 1 --> setBroadcast, 0 ---> unsetBroadcast
    PaqueteDatagrama pd((char*)num,sizeof(&num),argv[1],puerto);
    sd.envia(pd);
    while(1){
        sd.recibe(2);
        cout << "Se ha detectado el servidor con la IP: " << sd.obtieneIPCliente() << endl;
    }
}