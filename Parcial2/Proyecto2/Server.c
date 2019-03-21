#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include <string.h>

int s, sizeofArray;
int* datagrams;
struct sockaddr_in createServerClient(char* ip,int port);
int receiveDatagram();
int sendDatagram(int message,struct sockaddr_in server_client_addr);
void packetDetectionServer();
void packetDetectionClient(struct sockaddr_in server_client_addr);
int sendPackets(int totalPackets, struct sockaddr_in server_client_addr);

struct sockaddr_in createServerClient(char* ip,int port){/*Función que crea un cliente o un servidor.*/
    struct sockaddr_in server_client_addr;
    s = socket(AF_INET, SOCK_DGRAM, 0);
    bzero((char *)&server_client_addr, sizeof(server_client_addr));
    server_client_addr.sin_family = AF_INET;
    if(strlen(ip) > 0){
        server_client_addr.sin_addr.s_addr = inet_addr("127.0.0.1");/*Example "127.0.0.1"*/
        server_client_addr.sin_port = htons(port);
    }else{
        server_client_addr.sin_addr.s_addr = INADDR_ANY;
        server_client_addr.sin_port = htons(port);
        bind(s, (struct sockaddr *)&server_client_addr, sizeof(server_client_addr));
        printf("Servidor escuchando...\n");
    }
    return server_client_addr;
}

int receiveDatagram(){
    int res;
    recvfrom(s, (char *)&res, sizeof(int), 0, NULL, NULL);
    printf("%d\n",res);
    return res;
}

int sendDatagram(int message,struct sockaddr_in server_client_addr){
    int tmp = sendto(s, (char *)&message, sizeof(int), 0, (struct sockaddr *) &server_client_addr, sizeof(server_client_addr));
    printf("Tmp: %d\n",tmp);
    return tmp;
}

void packetDetectionServer(){
    int response = 0;
    sizeofArray = 1;
    do{
        response = receiveDatagram();
        datagrams[sizeofArray - 1] = response;
        sizeofArray++;
        datagrams = (int*)realloc(datagrams,(sizeofArray)*sizeof(int));
    }while(response != 0 && response != -1);
}

void packetDetectionClient(struct sockaddr_in server_client_addr){
    int response = 0, cont = 1;
    sizeofArray = 1;
    do{
        response = receiveDatagram();
        datagrams[sizeofArray - 1] = response;
        sizeofArray++;
        datagrams = (int*)realloc(datagrams,(sizeofArray)*sizeof(int));
        if(response != cont && response != 0 && response != -1){ /*Verificamos que el paquete que esperamos sea el correcto*/
            sendDatagram(cont,server_client_addr);
        }
        cont++;
    }while(response != 0 && response != -1);
}

int sendPackets(int totalPackets, struct sockaddr_in server_client_addr){
    int totalSend = 0;
    for(int i = 1; i <= totalPackets; i++){
        totalSend = (sendDatagram(i,server_client_addr) > 0)?totalSend + 1:totalSend - 1;
    }
    totalSend = (sendDatagram(0,server_client_addr) > 0)?totalSend + 1:totalSend - 1;
    return totalSend;
}

void printReport(int totalPackets){
    printf("Porcentaje de datagramas recibidos: %d\n",((sizeofArray * 100)/totalPackets));
    printf("Datagramas que fueron recibidos.\n");
    for(int i = 0; i < sizeofArray - 2; i++){
        printf("%d ",datagrams[i]);
    }
    printf("\n");    
}

int main(int argc, char *argv[]){
    int sizeofArray = 1;
    datagrams = (int*)malloc(sizeof(int));
    pthread_t th1;
    int totalPackets = atoi(argv[1]), puerto = 7202; /*Puerto sel otro servidor*/
    struct sockaddr_in server_addr = createServerClient("",7200);/*Ponemos a la escucha nuestro servidor*/
    struct sockaddr_in client_addr = createServerClient("127.0.0.1",puerto);/*Creamos un socket para conectarnos con el servidor externo*/
    sendPackets(totalPackets,client_addr);/*Envio de datagramas*/
    //packetDetectionServer();
    pthread_create(&th1, NULL, (void *)packetDetectionServer, NULL);/*Hilo para escuchar datagramas del otro servidor*/
    
    pthread_join(th1, NULL);
    printReport(totalPackets);
    free(datagrams);
    return 0;
}