#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include <string.h>
#include <unistd.h>

struct sockaddr_in server_addr, client_addr;
int sizeofArray, totalPackets, totalSend, socketServer, socketClient;
int* datagrams;

void createServerClient(char* ip,int port);
int receiveDatagram();
int sendDatagram(int message);
void printReport();
void packetDetectionServer();
void sendPackets();

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
    int response = 0;
    sizeofArray = 1;
    datagrams = (int*)malloc(sizeof(int));
    do{
        response = receiveDatagram();
        if(response < totalPackets){
            datagrams[sizeofArray - 1] = response;
            sizeofArray++;
            datagrams = (int*)realloc(datagrams,(sizeofArray)*sizeof(int));
        }
    }while(response != totalPackets);
    printReport();
    free(datagrams);
}

void printReport(){
    printf("Porcentaje de datagramas enviados: %d%\n",(((totalSend-1) * 100)/totalPackets));
    if(sizeofArray > 2){
        printf("Datagramas que fueron perdidos:\n");
        for(int i = 0; i < sizeofArray - 2; i++){
            printf("%d ",datagrams[i]);
        }
    }
    printf("\n");    
}

void sendPackets(){
    printf("Enviando %d paquetes.\n", totalPackets);
    totalSend = 0;
    for(int i = 1; i <= totalPackets; i++){
        totalSend = (sendDatagram(i) > 0)?totalSend + 1:totalSend - 1;
        usleep(100000);
    }
    totalSend = (sendDatagram(0) > 0)?totalSend + 1:totalSend - 1;
}

int main(int argc, char const *argv[]){
    totalPackets = atoi(argv[1]);
    createServerClient("",7200);
    createServerClient("127.0.0.1",7201);//Conexion con el otro servidor
    pthread_t th1;
    pthread_create(&th1, NULL, (void *)packetDetectionServer, NULL);
    sendPackets();/*Envio de datagramas*/
    pthread_join(th1, NULL);
    return 0;
}