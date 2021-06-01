CC = g++
CFLAGS = -std=c++11 -Wall

main: main.o vertice.o aresta.o grafo.o splitText.o
	$(CC) $(CFLAGS) -o programa main.o vertice.o aresta.o grafo.o splitText.o

main.o: main.cpp vertice.h aresta.h grafo.h splitText.h
	$(CC) $(CFLAGS) -c main.cpp

vertice.o: vertice.h

aresta.o: aresta.h vertice.h

grafo.o: grafo.h aresta.h vertice.h

splitText.o: splitText.h

clean:
	rm main.o vertice.o aresta.o grafo.o splitText.o programa
