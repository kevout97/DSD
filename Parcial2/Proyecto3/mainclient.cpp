#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "FileClass.h"
#include "SocketDatagrama.h"
#define PUT 1
#define GET 2
#define DELETE 3

using namespace std;
int puerto = 7201;

int main(int argc, char const *argv[]){// 1 IP Server, 2 Puerto Server, 3 Nombre Archivo, 4 Opcion
    char* ipServidor = (char*)malloc(sizeof(char)*strlen(argv[1]));
    strcpy(ipServidor,argv[1]);
    char* name;
    char* data;
    char* tam = (char*)malloc(sizeof(char));
    int puertoServidor = atoi(argv[2]), opcion = atoi(argv[4]), sizeDatagram;
    FileClass *fc = new FileClass();
    SocketDatagrama sd(puerto);
    PaqueteDatagrama * pd = new PaqueteDatagrama((char*)argv[4],sizeof(int),ipServidor,puertoServidor);
    sd.envia(*pd);

    switch (opcion){
        case PUT:
            fc = new FileClass((char*)argv[3],0); //Se guarda el nombre del archivo en un objeto
            sprintf(tam,"%d",sizeof(*fc)); 
            pd = new PaqueteDatagrama((char*)tam,sizeof(int),ipServidor,puertoServidor); 
            sd.envia(*pd); 
            pd = new PaqueteDatagrama((char*)fc,sizeof(FileClass),ipServidor,puertoServidor);
            sd.envia(*pd); // Enviamos el objeto con el nombre del archivo
            sprintf(tam,"%d",fc->getSizeFile(fc->getName()));
            pd = new PaqueteDatagrama((char*)tam,sizeof(int),ipServidor,puertoServidor);
            sd.envia(*pd); // Enviamos el tamanio del archivo
            data = (char*)malloc(sizeof(char)*fc->getSizeFile(fc->getName()));
            strcpy(data,fc->getData(fc->getName()));
            pd = new PaqueteDatagrama((char*)data,fc->getSizeFile(fc->getName()),ipServidor,puertoServidor);
            sd.envia(*pd); // Enviamos el contenido del archivo
            cout << "Archivo: "<< argv[3] << " enviado al servidor" << endl;
            break;
        
        case GET:
            fc = new FileClass((char*)argv[3],0); //Se guarda el nombre del archivo en un objeto
            sprintf(tam,"%d",sizeof(*fc)); 
            pd = new PaqueteDatagrama((char*)tam,sizeof(int),ipServidor,puertoServidor);
            sd.envia(*pd);
            pd = new PaqueteDatagrama((char*)fc,sizeof(FileClass),ipServidor,puertoServidor);
            sd.envia(*pd);
            sizeDatagram = atoi(sd.recibe(sizeof(int)));
            data = (char*)malloc(sizeof(char)*sizeDatagram);
            strcpy(data,sd.recibe(sizeDatagram));
            fc->writeFile(fc->getName(),data);
            cout << "Archivo: "<< fc->getName() << " recibido desde el servidor" << endl;
            break;

        case DELETE:
            cout << "DELETE" << endl;
            fc = new FileClass((char*)argv[3],0);
            sprintf(tam,"%d",sizeof(*fc));
            pd = new PaqueteDatagrama((char*)tam,sizeof(int),ipServidor,puertoServidor);
            sd.envia(*pd);
            pd = new PaqueteDatagrama((char*)fc,sizeof(FileClass),ipServidor,puertoServidor);
            sd.envia(*pd);
            cout << "Archivo: "<< fc->getName() << " eliminado en el servidor" << endl;
            break;

        default:
            cout << "Opcion invalida" << endl;
            break;
    }
}