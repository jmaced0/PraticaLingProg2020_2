CC = g++
CFLAGS = -Wall

main: main.o paciente.o
	$(CC) $(CFLAGS) -o programa main.o paciente.o

main.o: main.cpp arvore.h cadastro.h paciente.h
	$(CC) $(CFLAGS) -c main.cpp

paciente.o: paciente.h
	$(CC) $(CFLAGS) -c paciente.cpp

clean:
	rm main.o paciente.o programa
