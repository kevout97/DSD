#include "SocketDatagrama.hpp"
using namespace std;

int puerto = 7200;

int main(void){
   unsigned int num[3],incremento,respuesta = 0;
   char ip1[] = "127.0.0.1";
   char ip2[] = "10.100.68.243";
   char ip3[] = "10.100.68.45";
   SocketDatagrama clientSocket(0);
   PaqueteDatagrama *mensaje;

   cout << "Ingresa el numero a comprobar\n";
//    cin >> num[0];
      num[0] = 4294967291;

   while(num[0] > 2){
/////////////////////////////////////////////////////////////////////////
      //cout << "Se busca comprobar el numero " << num[0] << endl;
      incremento = num[0]*.35;
      num[1] = 2;
      num[2] = incremento;
      mensaje = new PaqueteDatagrama((char*)num, 3*sizeof(int), ip1, puerto);
      clientSocket.envia(*mensaje);
////////////////////////////////////////////////////////////////////////
      incremento = num[0]*.32;
      num[1] = num[2]+1;
      num[2] += incremento;
      mensaje = new PaqueteDatagrama((char*)num, 3*sizeof(int), ip2, puerto);
      clientSocket.envia(*mensaje);
/////////////////////////////////////////////////////////////////////
      num[1] = num[2]+1;
      num[2] = num[0]-1;
      mensaje = new PaqueteDatagrama((char*)num, 3*sizeof(int), ip3, puerto);
      clientSocket.envia(*mensaje);
/////////////////////////////////////////////////////////////////////////////////
      mensaje = new PaqueteDatagrama(sizeof(int));
      //cout << "Esperando RESPUESTA DEL SERVER" << endl;
      clientSocket.recibe(*mensaje);
      //cout << "Mensaje recibido: " << *(int*)mensaje->obtieneDatos() << endl;
      respuesta += *(int*)mensaje->obtieneDatos();

      mensaje = new PaqueteDatagrama(sizeof(int));
      //cout << "Esperando RESPUESTA DEL SERVER" << endl;
      clientSocket.recibe(*mensaje);
      //cout << "Mensaje recibido: " << *(int*)mensaje->obtieneDatos() << endl;
      respuesta += *(int*)mensaje->obtieneDatos();

      mensaje = new PaqueteDatagrama(sizeof(int));
      //cout << "Esperando RESPUESTA DEL SERVER" << endl;
      clientSocket.recibe(*mensaje);
      //cout << "Mensaje recibido: " << *(int*)mensaje->obtieneDatos() << endl;
      respuesta += *(int*)mensaje->obtieneDatos();

      if(respuesta == 3){
         cout << "El numero " << num[0] << " es primo\n";
         break; 
      }else{
         cout << "El numero " << num[0] << " no es primo\n";
         num[0]--;
         respuesta = 0;
      }
   }
}