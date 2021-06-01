#ifndef GRAFO_H
#define GRAFO_H

#include "aresta.h"

using namespace std;

class Grafo {
	public:
		Grafo(unsigned);
		void inserirAresta (Aresta *);
		void getCaminhoMaisFrequente(unsigned);
		void getVerticeMaisUsado();
		void setMaxCaminhos(unsigned N);
	private:
		unsigned maxCaminhos;
		vector <Aresta *> v;

};

#endif
