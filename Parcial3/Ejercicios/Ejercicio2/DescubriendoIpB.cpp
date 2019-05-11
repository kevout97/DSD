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
using namespace std;
//g++ DescubriendoIpB.cpp -o DescubriendoIpB -pthread
//sudo ./DescubriendoIpB 192.168.1. 1 254
// 192.168.1. ----> Parte de la ip que ya no puede ser modificada
// 1 -----> Sufijo del primer host disponible
// 254 ----> Sufijo del ultimo host disponible
void enviar(char* ip,int firstHost, int lastHost);
void recibir();
int puerto = 7200, s = socket(AF_INET, SOCK_DGRAM, 0);
struct sockaddr_in server_addr, msg_to_client_addr;


void enviar(char* sufijo,int firstHost, int lastHost){
   cout << "Hilo para enviar mensajes corriendo..." << endl;
   int num[2];
   int clilen;
   num[0] = 5; num[1] = 3;
   char* ip = (char*)malloc(sizeof(char)*15);
   char* tmp = (char*)malloc(sizeof(char));
   for(int i = firstHost; i <= lastHost; i++) {
      sprintf(tmp,"%d",i);
      strcpy(ip,sufijo);
      strcat(ip,tmp);
      msg_to_client_addr.sin_family = AF_INET;
      msg_to_client_addr.sin_addr.s_addr = INADDR_ANY;
      msg_to_client_addr.sin_addr.s_addr = inet_addr(ip);
      msg_to_client_addr.sin_port = htons(puerto);
      clilen = sizeof(msg_to_client_addr);
      sendto(s, (char *)num, sizeof(int), 0, (struct sockaddr *)&msg_to_client_addr, clilen);
   }
}

void recibir(){
   cout << "Hilo para recibir mensajes corriendo..." << endl;
   int res, clilen;
   while(1){
       recvfrom(s, (char *) &res, 2*sizeof(int), 0, (struct sockaddr *)&msg_to_client_addr,(socklen_t*) &clilen);
       cout << "Se ha detectado el servidor con la IP: " << inet_ntoa(msg_to_client_addr.sin_addr) << endl;
   }
}

int main(int arg, char* argv[]){
   bzero((char *)&server_addr, sizeof(server_addr));
   server_addr.sin_family = AF_INET;
   server_addr.sin_addr.s_addr = INADDR_ANY;
   server_addr.sin_port = htons(puerto);
   bind(s, (struct sockaddr *)&server_addr, sizeof(server_addr));
   thread send(enviar,argv[1],atoi(argv[2]),atoi(argv[3]));
   thread receive(recibir);
   receive.join();
}