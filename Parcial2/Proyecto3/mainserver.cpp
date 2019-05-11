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
int puerto = 7200;
int main(){
    int puertoCliente = 7201, sizeDatagram;
    char* data = (char*)malloc(sizeof(char));
    char* name = (char*)malloc(sizeof(char));
    char* tam = (char*)malloc(sizeof(char));
    FileClass *fc = new FileClass();
    SocketDatagrama sd(puerto);
    PaqueteDatagrama *pd;
    for(;;){
        int opcion = atoi(sd.recibe(sizeof(int)));
        switch (opcion){
            case PUT:
                sizeDatagram = atoi(sd.recibe(sizeof(int)));
                fc = new FileClass();
                memcpy(fc,sd.recibe(sizeDatagram),sizeDatagram);//Se recibe el nombre del archivo
                sizeDatagram = atoi(sd.recibe(sizeof(int))); //Se recibe el tamanio del archivo
                data = (char*)malloc(sizeof(char)*sizeDatagram);
                memcpy(data,sd.recibe(sizeDatagram),sizeDatagram);//Se recibe el contenido del archivo
                fc->writeFile(fc->getName(),data);
                cout << "Archivo " << fc->getName() << "recibido " << endl;
                break;
            
            case GET:
                sizeDatagram = atoi(sd.recibe(sizeof(int)));
                fc = new FileClass();
                memcpy(fc,sd.recibe(sizeDatagram),sizeDatagram);
                data = (char*)malloc(sizeof(char)*fc->getSizeFile(fc->getName()));
                strcpy(data,fc->getData(fc->getName()));
                sprintf(tam,"%d",fc->getSizeFile(fc->getName()));
                pd = new PaqueteDatagrama((char*)tam,sizeof(int),(char*)sd.obtieneIPCliente(),puertoCliente);
                sd.envia(*pd);
                pd = new PaqueteDatagrama((char*)data,fc->getSizeFile(fc->getName()),(char*)sd.obtieneIPCliente(),puertoCliente);
                sd.envia(*pd);
                break;

            case DELETE:
                sizeDatagram = atoi(sd.recibe(sizeof(int)));
                fc = new FileClass();
                memcpy(fc,sd.recibe(sizeDatagram),sizeDatagram);
                fc->deleteFile(fc->getName());
                break;

            default:
                cout << "Opcion invalida" << endl;
                break;
        }
    }
}