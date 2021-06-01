#ifndef CATALOGO_H
#define CATALOGO_H

#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

#include "filme.h"

class Catalogo {
	// impressao de todos os filmes do catalogo
	friend ostream &operator<< (ostream &, Catalogo const &);

	private:
		vector <Filme> filmes;
		unsigned max_filmes;
		
		void sortFilmes();

	public:
		Catalogo(unsigned);
		
		//inserção de filme
		Catalogo &operator+= (Filme);
		
		//inserção de vetor de filmes
		Catalogo &operator+= (vector <Filme>);
		
		//remocao de filme
		Catalogo &operator-= (Filme);

		//procura por um filme
		Filme* operator()(string);

		//Editar editora de um filme
		Filme* operator()(string, string);
		
		//Editar nota de um filme
		Filme* operator()(string, double);

		//Buscar filme mais bem avaliado
		Filme* BuscarMelhorAvaliado();

		//Salvar catalogo
		void SalvarCatalogo (string);

};


#endif
