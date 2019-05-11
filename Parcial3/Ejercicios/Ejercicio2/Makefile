DescubriendoIpC: DescubriendoIpC.cpp SocketDatagrama.o PaqueteDatagrama.o
	g++ DescubriendoIpC.cpp SocketDatagrama.o PaqueteDatagrama.o -o DescubriendoIpC
SocketDatagrama.o: SocketDatagrama.cpp PaqueteDatagrama.o SocketDatagrama.h
	g++ SocketDatagrama.cpp -c
PaqueteDatagrama.o: PaqueteDatagrama.cpp PaqueteDatagrama.h
	g++ PaqueteDatagrama.cpp -c