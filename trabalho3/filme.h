#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

#ifndef FILME_H
#define FILME_H

struct Filme{
	string titulo;
	string produtora;
	double nota;

};

ostream &operator<< (ostream &, const Filme &);
istream &operator>> (istream &, Filme &);
bool operator< (const Filme &, const Filme &);
bool operator== (const Filme &, const Filme &);

#endif
