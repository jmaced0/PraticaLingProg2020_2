#include "vertice.h"

Vertice::Vertice (string *p){
	palavra = p;
}

string *Vertice::getPalavra(){
	return palavra;
}

void Vertice::setPalavra (string *p){
	palavra = p;
}


