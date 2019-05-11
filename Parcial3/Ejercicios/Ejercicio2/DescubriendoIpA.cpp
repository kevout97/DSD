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
using namespace std;
//g++ DescubriendoIpA.cpp -o DescubriendoIpA
//sudo ./DescubriendoIpA 192.168.1. 1 254
// 192.168.1. ----> Parte de la red que ya no puede ser modificada
// 1 -----> Sufijo del primer host disponible
// 254 ----> Sufijo del ultimo host disponible
int puerto = 7200;
int main(int arg, char* argv[]){
   int num[2];
   int firstHost = atoi(argv[2]), lastHost = atoi(argv[3]), s, res, clilen;
   struct sockaddr_in server_addr, msg_to_client_addr;
   char* ip = (char*)malloc(sizeof(char)*15);
   char* tmp = (char*)malloc(sizeof(char));
   s = socket(AF_INET, SOCK_DGRAM, 0);
   bzero((char *)&server_addr, sizeof(server_addr));
   server_addr.sin_family = AF_INET;
   server_addr.sin_addr.s_addr = INADDR_ANY;
   server_addr.sin_port = htons(puerto);
   bind(s, (struct sockaddr *)&server_addr, sizeof(server_addr));
   num[0] = 5; num[1] = 3;
   for(int i = firstHost; i <= lastHost; i++) {
      sprintf(tmp,"%d",i);
      strcpy(ip,argv[1]);
      strcat(ip,tmp);
      msg_to_client_addr.sin_family = AF_INET;
      msg_to_client_addr.sin_addr.s_addr = INADDR_ANY;
      msg_to_client_addr.sin_addr.s_addr = inet_addr(ip);
      msg_to_client_addr.sin_port = htons(puerto);
      clilen = sizeof(msg_to_client_addr);
      sendto(s, (char *)num, sizeof(int), 0, (struct sockaddr *)&msg_to_client_addr, clilen);
   }
   while(1){
       recvfrom(s, (char *) &res, 2*sizeof(int), 0, (struct sockaddr *)&msg_to_client_addr,(socklen_t*) &clilen);
       cout << "Se ha detectado el servidor con la IP: " << inet_ntoa(msg_to_client_addr.sin_addr) << endl;
   }
}