#ifndef VERTICE_H
#define VERTICE_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

//cada vertice será uma palavra ou palavra + pronome caso esses sejam separados por hífen
class Vertice{
	public:
		Vertice (string*);
		string *getPalavra();
		void setPalavra(string*);
	private:
		string *palavra;
};

#endif
