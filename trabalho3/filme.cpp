#include "filme.h"

ostream &operator<< (ostream &out, const Filme& movie){
	out << setw(12) << "Filme: " <<     setw(25) << movie.titulo << "\n" ;
	out << setw(12) << "Produtora: " << setw(25) << movie.produtora << "\n";
	out << setw(12) << "Nota: " <<      setw(25) << movie.nota << endl;

	return out;

};

istream &operator>> (istream &in, Filme &filme){

	in.clear();
	in.ignore();

	cout << "Digite o titulo do filme: ";
	getline(in, filme.titulo);


	cout << "Digite a produtora do filme: ";
	getline(in, filme.produtora);

	cout << "Digite a nota do filme: ";
	in >> filme.nota;


	return in;


}
bool operator< (const Filme &filmeA, const Filme &filmeB) { return filmeA.titulo < filmeB.titulo ? true : false ;}
bool operator== (const Filme &filmeA, const Filme &filmeB) { return filmeA.titulo == filmeB.titulo ? true : false ;}
