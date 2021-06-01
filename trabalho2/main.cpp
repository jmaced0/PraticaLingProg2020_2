#include "grafo.h"
#include "splitText.h"
#include <fstream>
#include <algorithm>

using namespace std;


int main(){
	//objeto para ler o texto
	ifstream texto;
	string linha;
	vector <string> paragrafo, frases, palavras, palavras_vertice;

	vector <Vertice> vertices;
	vector <Aresta> arestas;
	unsigned max_palavras = 1;
	Grafo grafo(max_palavras);

	texto.open("texto_teste.txt");

	if (texto.is_open()){
		

		cout << "\nTrecho de texto usado: \n" <<endl;
		while(getline(texto, linha)){
			cout << linha << endl;
			paragrafo.push_back(linha);
				
		}

		//Pegar palavras nao repetidas
		palavras_vertice = splitEmPalavras(paragrafo[0]);
		palavras_vertice.push_back("x");		
		sort(palavras_vertice.begin(), palavras_vertice.end());
		palavras_vertice.erase(unique(palavras_vertice.begin(), palavras_vertice.end()), palavras_vertice.end());

		//criar vertices com essas palavras não repetidas
		for (unsigned idx = 0 ; idx < palavras_vertice.size() ; idx++){
			vertices.push_back(Vertice(&palavras_vertice.at(idx)));
		}


		frases = splitText(paragrafo);

			
		//percorrer frases do texto para criar as arestas
		for (unsigned idx = 0; idx < frases.size(); idx++){
			linha = frases.at(idx);
			palavras.clear();

			palavras = splitEmPalavras(linha);
		
			//atualizar tamanho maximo de uma frase presente no texto
			if (palavras.size() > max_palavras){
				max_palavras = palavras.size();
				grafo.setMaxCaminhos(max_palavras);
			}

			//Para resolver problema do primeiro elemento não estar sendo adicionado corretamente
			//adiciona-se um "x " no inicio texto depois sua contagem passa a ser 0
			if(!idx){
				
				vector <string> s;
				s.push_back("x");
				s.insert(s.end(), palavras.begin(), palavras.end());
				palavras = s;

				
			}
			//somente temos uma aresta se a frase tiver mais de uma palavra
			if (palavras.size() > 1){
				for(unsigned idxPalavras = 1; idxPalavras < palavras.size(); idxPalavras++){
					unsigned v1, v2;
					
					//achar id dos vertices
					for(unsigned idx_vertice = 0; idx_vertice < vertices.size(); idx_vertice++){
						if (*vertices.at(idx_vertice).getPalavra() == palavras.at(idxPalavras-1)){
							v1 = idx_vertice;
						}
						if (*vertices.at(idx_vertice).getPalavra() == palavras.at(idxPalavras)){
							v2 = idx_vertice;
						}
					}
					arestas.push_back(Aresta(&vertices.at(v1), &vertices.at(v2)));
					grafo.inserirAresta(&arestas.back());
	
				}
			}	
		}
		
	

		int menu = 0;
		while (menu != 4){
			//opcoes do menu
			cout << "Escolha uma opcao do menu: \n"
				<< "\t1) Palavra mais utilizada no texto\n"
				<< "\t2) Sequencia de duas palavras mais utilizada no texto\n"
				<< "\t3) Sequencia de N palavras mais utilizada no texto\n"
				<< "\t4) Sair do programa" << endl;
			cout << "Digite um dos numeros acima: ";
			cin >> menu;
			cout << endl;

			// opcao 1
			if (menu == 1){
				grafo.getVerticeMaisUsado();

			}
			//opcao 2
			else if (menu == 2){
				unsigned N=2;
				grafo.getCaminhoMaisFrequente(N);
				cout << endl;
			}
			//opcao 3
			else if (menu == 3){

				cout << "Digite o numero de sequencias desejado: ";
				unsigned N;
				cin >> N;
				
				if(cin.bad() || cin.fail() || N == 0){
					cin.clear();
					cin.ignore();
					menu = 0;
					cout << "\n Entrada deve ser um inteiro entre positivo. Tente novamente" <<endl;
				}
				
				grafo.getCaminhoMaisFrequente(N);
				cout << endl;



			}
			//sair do programa ou checar input errado
			else if (menu != 4){
				if(cin.bad() || cin.fail()){
					cin.clear();
					cin.ignore();
					menu = 0;
					cout << "\n Entrada deve ser um inteiro entre 1 e 4. Tente novamente" <<endl;
				}
				else{ cout << "Opcao inválida! Tente novamente" << endl;}

			}
		}
		//fechar arquivo
		texto.close();
	}
	//erro ao abrir arquivo
	else{
		cout << "Falha ao abrir arquivo, programa encerrado." << endl;
	}


	return 0;
}
