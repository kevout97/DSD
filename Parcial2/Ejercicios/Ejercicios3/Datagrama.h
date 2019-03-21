#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <iostream>
#include <string>

using namespace std;

class PaqueteDatagrama { 
	public:
		PaqueteDatagrama(char *, unsigned int, char * , int ); 
		PaqueteDatagrama(unsigned int );
		char * obtieneDireccion();
		unsigned int obtieneLongitud(); 
		int obtienePuerto();
		char * obtieneDatos();

		void inicializaPuerto(int); 
		void inicializaIp(char* );
		void inicializaDatos(char* );
	private:
		char* datos;
		char* ip;
		unsigned int longitud; 
		int puerto;
};