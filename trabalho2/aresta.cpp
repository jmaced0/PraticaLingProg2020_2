#include "aresta.h"

Aresta::Aresta (Vertice *primeiro, Vertice *segundo, unsigned occ){
	primeiroVertice = primeiro;
	segundoVertice  = segundo;
	num_ocorrencias = occ;
}

Vertice *Aresta::getPrimeiroVertice(){
	return primeiroVertice;
}

Vertice *Aresta::getSegundoVertice(){
	return segundoVertice;
}

void Aresta::setNumOcorrencias(unsigned occ){
	num_ocorrencias = occ;
}

unsigned Aresta::getNumOcorrencias(){
	return num_ocorrencias;
}
