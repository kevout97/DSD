#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include <string.h>

struct sockaddr_in server_addr, client_addr;
int sizeofArray, totalPackets, socketServer, socketClient;
int* datagrams;

void createServerClient(char* ip,int port);
int receiveDatagram();
int sendDatagram(int message);
void printReport();
void packetDetectionServer();

void createServerClient(char* ip,int port){/*Función que crea un cliente o un servidor.*/
    
    if(strlen(ip) > 0){
        socketClient = socket(AF_INET, SOCK_DGRAM, 0);
        bzero((char *)&client_addr, sizeof(client_addr));
        client_addr.sin_family = AF_INET;
        client_addr.sin_addr.s_addr = inet_addr(ip);/*Example "127.0.0.1"*/
        client_addr.sin_port = htons(port);
        printf("Cliente Creado...\n");
    }else{
        socketServer = socket(AF_INET, SOCK_DGRAM, 0);
        bzero((char *)&server_addr, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr = INADDR_ANY;
        server_addr.sin_port = htons(port);
        bind(socketServer, (struct sockaddr *)&server_addr, sizeof(server_addr));
        printf("Servidor Escuchando...\n"); 
    }
}

int receiveDatagram(){
    int res;
    recvfrom(socketServer, (char *)&res, sizeof(int), 0, NULL, NULL);
    return res;
}

int sendDatagram(int message){
    return sendto(socketClient, (char *)&message, sizeof(int), 0, (struct sockaddr *)&client_addr, sizeof(client_addr));
}

void packetDetectionServer(){
    int response = 0, cont = 1;
    for(;;){
        sizeofArray = 1;
        datagrams = (int*)malloc(sizeof(int));
        printf("Esperando Paquetes...\n");
        do{
            response = receiveDatagram();
            datagrams[sizeofArray - 1] = response;
            sizeofArray++;
            datagrams = (int*)realloc(datagrams,(sizeofArray)*sizeof(int));
            if(response != cont && response != 0){ /*Verificamos que el paquete que esperamos sea el correcto*/
                sendDatagram(cont);
            }
            cont++;
        }while(response != 0);
        sendDatagram(sizeofArray-2);
        printReport();
        free(datagrams);
    }
}

void printReport(){
    printf("Datagramas que fueron recibidos.\n");
    for(int i = 0; i < sizeofArray - 2; i++){
        printf("%d ",datagrams[i]);
    }
    printf("\n");    
}

int main(int argc, char const *argv[]){
    createServerClient("",7201);
    createServerClient("127.0.0.1",7200);//Conexion con el otro servidor
    packetDetectionServer();
    return 0;
}