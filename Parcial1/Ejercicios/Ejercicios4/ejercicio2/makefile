programa4_2: programa4_2.cpp Rectangulo.o
	g++ programa4_2.cpp Rectangulo.o Coordenada.o -o programa4_2
Rectangulo.o: Rectangulo.cpp Coordenada.o Rectangulo.h
	g++ Rectangulo.cpp -c
Coordenada.o: Coordenada.cpp Coordenada.h
	g++ Coordenada.cpp -c