#include "grafo.h"
#include <algorithm>
#include <iterator>
#include <iomanip>


Grafo::Grafo(unsigned N){
	maxCaminhos = N;
}

void Grafo::setMaxCaminhos(unsigned N){
	maxCaminhos = N;
}

void Grafo::inserirAresta (Aresta *aresta){

	
	//caso nao tenha alguma aresta no grafo
	if(v.empty()){
		v.push_back(aresta);//nao entendi pq mas nao esta adicioando no primeiro elemeto do vetor
	}
	//caso tenha alguma aresta no grafo
	else{
		v.at(0)->setNumOcorrencias(0);
		unsigned aux;

		//checar se já tem aresta igual
		int achou = 0;
		for (unsigned idx = 0; idx < v.size(); idx++){
			//caso ache aresta
			if ((v.at(idx)->getPrimeiroVertice() == aresta->getPrimeiroVertice()) &&
			   	(v.at(idx)->getSegundoVertice() == aresta->getSegundoVertice())){
				
				aux = v.at(idx)->getNumOcorrencias();
				//incrementa o contador de ocorrencias
				v.at(idx)->setNumOcorrencias(aux + 1);
				achou = 1;
				
				break;
				

			}
		}
		//caso não tenha achado aresta
		if (achou == 0){
			v.push_back(aresta);
		}

	}
}


//funcao auxilar para classificar um vetor em funcao de outro
bool sortAux (const pair <unsigned, unsigned> &a, const pair <unsigned, unsigned> &b){
	return a.second > b.second;
}

void Grafo::getCaminhoMaisFrequente(unsigned N){
	
	if (N > maxCaminhos){
		cout << "Tamanho escolhido ultrapassa tamanho da maior frase do texto, tente um numero inteiro menor"
			<< endl;
	}
	else{
		
		vector <unsigned> vec_numero_oco;
		vector <unsigned> idx_arestas;
		vector <pair <unsigned, unsigned>>  pairVector;
		// fazer um vetor com o numero de occorencias de cada aresta
		for(unsigned idx = 0; idx < v.size(); idx++){
			vec_numero_oco.push_back(v.at(idx)->getNumOcorrencias());
			idx_arestas.push_back(idx);
			pairVector.push_back(make_pair(idx_arestas.at(idx),
							vec_numero_oco.at(idx)));

		}
		//sort indices
		sort(pairVector.begin(),pairVector.end(), sortAux);

		//codigo para o sort baseado em:
		//https://www.geeksforgeeks.org/sorting-vector-of-pairs-in-c-set-1-sort-by-first-and-second/

		idx_arestas.clear();
		for(auto idx: pairVector){
			idx_arestas.push_back(idx.first);
		}


		//pegar os N maiores
		idx_arestas.resize(N);
		


		unsigned count = 1;
		for (auto idx : idx_arestas){
			cout << count << "º: "
			<< *v.at(idx)->getPrimeiroVertice()->getPalavra() << " --> "
			<< *v.at(idx)->getSegundoVertice()->getPalavra() << endl;
			count++;
		}

	}
}

void Grafo::getVerticeMaisUsado(){
	//Como os vertices são unicos, a palvra mais usada é aquela cujo vertice está presente em mais arestas
	// Se palavra está no meio da frase: aparece em duas arestas
	// Se palavra está no meio ou no fim da frase: aparece em uma aresta
	// Caso palavra apareça no meio e no fim da frase, também somará dois, entretanto
	// não é possivel diferenciar entre aparecer no inicio e no fim e aparecer no meio
	// com a modelagem feita. Dessa forma, o numero de aparições será dado pelo maior 
	// numero entre aparições no inicio de um vertice ou no final de um vertice, considerando
	// que raramente uma palavra aparecerá no inicio e no fim de frases no mesmo parágrafo
	
	//Caso extremo: 2n palavras, onde n é o tamanho do vetor de vertices
	vector <string> palavras_inicio, palavras_fim, palavras;
	string inicio, fim;
	unsigned multiplicidade;
       
	for (unsigned idx = 1; idx < v.size() ; idx++){
		inicio = *v.at(idx)->getPrimeiroVertice()->getPalavra();
		fim = *v.at(idx)->getSegundoVertice()->getPalavra();
		multiplicidade = v.at(idx)->getNumOcorrencias();

		for (unsigned idx_mul = 0; idx_mul < multiplicidade; idx_mul++){
			palavras_inicio.push_back(inicio);
			palavras_fim.push_back(fim);
			palavras.push_back(inicio);
			palavras.push_back(fim);
		}
	}

	sort(palavras_inicio.begin(), palavras_inicio.end());
	sort(palavras_fim.begin(), palavras_fim.end());
	sort(palavras.begin(), palavras.end());

	//vertices
	
	palavras.erase(unique(palavras.begin(), palavras.end()), palavras.end());

	vector <unsigned> contador(palavras.size(), 0);
       	vector <unsigned> indices;	

	for (unsigned idx = 0; idx < palavras.size(); idx ++){
		auto a = count(palavras_inicio.begin(), palavras_inicio.end(), palavras.at(idx));
		auto b = count(palavras_fim.begin(), palavras_fim.end(), palavras.at(idx));
		contador.at(idx) = (a > b) ? a : b; 
		indices.push_back(idx);
	}
	vector <pair <unsigned, unsigned>>  pairVector;

	for (unsigned idx = 0; idx < palavras.size(); idx ++){
		pairVector.push_back(make_pair(indices.at(idx),contador.at(idx)));
	}
	sort(pairVector.begin(), pairVector.end(), sortAux);

	for(auto idx: pairVector){
		cout << left << setw(15) << setfill(' ')  << palavras.at(idx.first);
		cout << left << setw(15) << setfill(' ') << "\t" << idx.second << endl;
	}



	//for( auto p:palavras){cout << p << endl;}

}	
