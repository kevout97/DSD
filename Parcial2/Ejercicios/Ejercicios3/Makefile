server: Server.cpp SocketDatagrama.o
	g++ Server.cpp SocketDatagrama.o PaqueteDatagrama.o -o server
SocketDatagrama.o: SocketDatagrama.cpp PaqueteDatagrama.o SocketDatagrama.h
	g++ SocketDatagrama.cpp -c
PaqueteDatagrama.o: PaqueteDatagrama.cpp Datagrama.h
	g++ PaqueteDatagrama.cpp -c