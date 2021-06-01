#ifndef ARESTA_H
#define ARESTA_H

#include "vertice.h"

using namespace std;

class Aresta {
	        public:
			//contrutor: vertice entre duas palavras
			//com peso qeu representa o numero de aparacições dessa aresta
			Aresta (Vertice *, Vertice *, unsigned = 1);

			//metodos
			Vertice *getPrimeiroVertice();
			Vertice *getSegundoVertice();
			void setNumOcorrencias(unsigned);
			unsigned getNumOcorrencias(); 
		private:
			Vertice *primeiroVertice;
			Vertice *segundoVertice;
			unsigned num_ocorrencias;
};

#endif
