# Cuestionario Capitulo 9

1. ¿Qúe almacena *sin_port*?

    **El puerto de conexión**


2. En este caso: 
    * ¿Cuál es el dominio del socket y cuál es su tipo? 

        **Dominio: AF_INET (Protocolo IPv4)**

        **Tipo: SOCK_DGRAM (Soporta Datagramas)**

    * ¿Para qué se usa la función *bzero*? 

        **Elimina la información de un tamaño especifico iniciando por la posicion dada y cambiando esta información con  0's.**

    * ¿Cuál es el tamaño en bits de la variable puerto?

        **16 bits**

    * Imprima el valor de la variable puerto en hexadecimal antes y despues de usar *htons* y explique detalladamente que operaciones realiza la función *htons* byte por byte.

        **La función se asegura que los números se almacenen en la memoria en orden de bytes de la red.**
        
        |Antes de htons| Despues de htons |
        |--------------|------------------|
        |0X50 0X30     | 0X30 0X50        |



3. La variable inicializada es:

    ```c
    server_addr, con los valores:

    struct sockaddr_in {
        short            sin_family;   // AF_INET
        unsigned short   sin_port;     // htons(7200)
        struct in_addr   sin_addr;     // in_addr: INADDR_ANY
        char             sin_zero[8];  // 0
    };

    struct in_addr {
        unsigned long s_addr;  // INADDR_ANY
    };
    ```

    **La estructura sin inicializar contiene datos basura, sin embargo en el programa, está estructura toma la información del socket del cliente que se conecta.**


4. ¿Cuales son las variables donde se almacenan la direccion IP y el puerto de algun cliente que le quiera hacer una peticion al servidor?
    
    **Para la direccion IP, la variable msg_to_client almacena la direccion IP del cliente Para el puerto no hay una variable especifica, pues el servidor no la necesita, los clientes tienen que crear la conexion en el puerto que el servidor este escuchando por lo que el servidor utilizara ese puerto para las conexiones, en dado caso a bajo nivel en el protocolo TCP o UDP se puede saber a que puerto dirigirse.**