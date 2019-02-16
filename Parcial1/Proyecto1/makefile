programa6: programa6.cpp Ortoedro.o
	g++ programa6.cpp Ortoedro.o Coordenada.o Rectangulo.o
Ortoedro.o: Ortoedro.cpp Rectangulo.o Coordenada.o Ortoedro.h
	g++ Ortoedro.cpp -c
Rectangulo.o: Rectangulo.cpp Coordenada.o Rectangulo.h
	g++ Rectangulo.cpp -c
Coordenada.o: Coordenada.cpp Coordenada.h
	g++ Coordenada.cpp -c