#define TAM_MAX_DATA 4000  
struct mensaje{
    int messageType; //0= Solicitud, 1 = Respuestaunsigned 
    int requestId; //Identificador del mensajechar IP[16]; 
    int puerto;int operationId; //Identificador de la operaciónchar arguments[TAM_MAX_DATA]; 
};