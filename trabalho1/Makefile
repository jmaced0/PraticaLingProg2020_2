CC = g++
CFLAGS = -Wall

main: main.o estadual.o nacional.o covidStats.o
	$(CC) $(CFLAGS) -o programa main.o estadual.o nacional.o covidStats.o

main.o: main.cpp estadual.h nacional.h covidStats.h 
	$(CC) $(CFLAGS) -c main.cpp

estadual.o: estadual.h

nacional.o: nacional.h estadual.h

covidStats.o: covidStats.h nacional.h estadual.h

clean:
	rm estadual.o nacional.o covidStats.o main.o programa

