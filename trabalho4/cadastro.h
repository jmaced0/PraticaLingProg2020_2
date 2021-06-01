#ifndef CATALOGO_H
#define CATALOGO_H

#include "arvore.h"
#include <memory>

template <class T>
class Cadastro;

template <typename T>
ostream &operator<< (ostream &, Cadastro<T> &);

template <class T>
class Cadastro{
	friend ostream &operator<< <T> (ostream &, Cadastro<T> &); //impressao

	private:
		Arvore<T> arvore;
	
	public:
		Node<T>* operator+= (T); //insercao
		T operator() (string); // busca

};

template <typename T>
ostream &operator<< (ostream &out , Cadastro<T> &tree){
	cout << tree.arvore << endl;
	return out;
}

template <class T>
Node<T> *Cadastro<T>::operator+= (T elemento){
	return arvore.Inserir(elemento);
}	

template <class T>
T Cadastro<T>::operator() (string str){
	return arvore.Busca(str);

}	
#endif
