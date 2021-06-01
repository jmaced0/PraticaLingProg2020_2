#ifndef ARVORE_H
#define ARVORE_H

#include <iostream>
#include <string>
#include <stack>
#include <typeinfo>

using namespace std;

template <class T>
class Node{
	public:
		T dado;
		Node<T> *esquerda, *direita;
		Node(){
			esquerda = nullptr;
			direita = nullptr;
		}
		Node(Node &no){
			dado = new T(no);
			esquerda = nullptr;
			direita = nullptr;
		}
};

template <class T>
class Arvore;

template <typename T>
ostream &operator<<(ostream&, const Arvore<T> &);

template <class T>
class Arvore{

	private:


		Node<T>* InserirRecursivo( Node <T>*,  T, Node<T>**);
		Node<T>* DestruirRecursivo( Node<T>*); //função auxiliar para destruir arvore
		Node<T>* BuscaRecursiva(Node<T>*, string); 

	public:
		Node<T> *raiz;
		Arvore(); //construtor
		~Arvore(); //destrutor

		Node<T>* Inserir(T);
		T Busca(string);


		
		friend ostream &operator<< <T> (ostream &, const Arvore<T> &);	
};


//construtor
template <class T>
Arvore<T>::Arvore(){
	raiz = nullptr;
}

//destrutor
template <class T>
Arvore<T>::~Arvore(){
	raiz = DestruirRecursivo(raiz);
}
// função auxiliar para realizar destrutor
template <class T>
Node<T>* Arvore<T>::DestruirRecursivo(Node<T>* ptr){
	if (ptr != nullptr){
		ptr->esquerda = DestruirRecursivo(ptr->esquerda);
		ptr->direita = DestruirRecursivo(ptr->direita);
		delete ptr->dado; //deleta o objeto
		delete ptr; //deleta o no
	}
	return ptr;
}

template <class T>
T Arvore<T>::Busca(string str){

	Node<T>* aux = BuscaRecursiva(raiz, str);
	return aux == nullptr ? nullptr : aux->dado;
}

template <class T>
Node<T>* Arvore<T>::BuscaRecursiva(Node<T>* ptr, string str){
	if (ptr == nullptr){
		return ptr;
	}
	else if (ptr->dado->getKey() == str){
		return ptr;
	}
	else if (ptr->dado->getKey() < str){
		return BuscaRecursiva(ptr->direita, str);
	}
	else { return BuscaRecursiva(ptr->esquerda, str);}

}



//Insercao
template <class T>
Node<T>* Arvore<T>::Inserir(T elemento){
	Node<T>* auxPtr = nullptr;//só é necessario pq um dos requisitos é que inserção retorne ponteiro 
	raiz = InserirRecursivo(raiz, elemento, &auxPtr);

	return auxPtr;
}	

template <class T>
Node<T>* Arvore<T>::InserirRecursivo(Node<T> *ptr, T elemento, Node<T> **NoIncluido){
	if (ptr == nullptr){
		ptr = new Node<T>;
		ptr->dado = elemento;

		ptr->esquerda = nullptr;
		ptr->direita = nullptr;
		
		//retorna Nó incluido
		*NoIncluido = ptr;
	}
	else
	{
		if (*(ptr->dado) == *elemento){
			NoIncluido = nullptr;
			return ptr;
		}

		else {
		       	if( *(ptr->dado) < *elemento ){
				ptr->direita = InserirRecursivo(ptr->direita, elemento, NoIncluido);
			}
			else
			{
				ptr->esquerda = InserirRecursivo(ptr->esquerda, elemento, NoIncluido);
			}
		}
	}
	return ptr;
}

template <typename T>
ostream &operator<< (ostream &out, Arvore<T> &tree){

	if(tree.raiz != nullptr){

		Node<T>* ptr = tree.raiz;
		stack<Node<T> *> pilha;
		while (ptr != nullptr || !pilha.empty()){
			while(ptr != nullptr){
				cout << *(ptr->dado) << endl;
				pilha.push(ptr);
				ptr = ptr->esquerda;
			}
			if(!pilha.empty()){
				ptr = pilha.top();
				pilha.pop();
				ptr = ptr->direita;
			}	
		}	
	}
	return out;
}
#endif
