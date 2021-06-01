#ifndef EXCECOES_H
#define EXCECOES_H

#include <iostream>
#include <exception>
using namespace std;

struct InsertExcept : public exception{
	const char *what() const throw (){
		return "Já existe um paciente com esse nome.\n";
	}
};

struct SearchExcept : public exception{
	const char *what() const throw (){
		return "Paciente nao esta cadastrado. \n";
	}
};

#endif
