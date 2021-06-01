CC = g++
CFLAGS = -Wall

main: main.o filme.o catalogo.o 
	$(CC) $(CFLAGS) -o programa main.o filme.o catalogo.o

main.o: main.cpp filme.h catalogo.h
	$(CC) $(CFLAGS) -c main.cpp

filme.o: filme.h

catalogo.o: filme.h catalogo.h

clean:
	rm main.o filme.o catalogo.o programa
