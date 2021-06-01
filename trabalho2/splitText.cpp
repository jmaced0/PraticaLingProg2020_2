#include "splitText.h"

vector <string> splitText(vector <string> texto){
	vector <string> frases;
	string linha, fimLinhaAnterior;
	unsigned inicio, fim;

	fimLinhaAnterior.clear();
	for (unsigned idx_linhas = 0; idx_linhas < texto.size(); idx_linhas++){
		linha = texto.at(idx_linhas);

		inicio = 0;
		fim = linha.find_first_of(",.!?:;");
		while (linha[fim +1] != '\0'){
			//se linha final da linha anterior está vazia
			if(fimLinhaAnterior.empty()){
				frases.push_back(linha.substr(inicio, fim - inicio));
				fim = fim+1;
			}
			//se linha anterior tem algo
			else{
				frases.push_back(fimLinhaAnterior + linha.substr(inicio, fim - inicio));
				fimLinhaAnterior.clear();
				fim = fim + 1;
			}

			
			inicio = fim + 1;
			//se inicio não é o fim da linha
			if(linha[inicio]!='\0'){
				fim = linha.find_first_of(",.!?:;", inicio+1);
			}
			else{
				fimLinhaAnterior = linha.substr(fim+1);
			}
		}
		frases.push_back(linha.substr(inicio, fim - inicio));

	}

	return frases;

}

vector <string> splitEmPalavras(string frase){

	vector <string> palavras;
	unsigned idx1 = 0;
	unsigned idx2 = 0;
	char s;
	string aux;
	for (unsigned idx_letra = 0; idx_letra < frase.size(); idx_letra++ ){
		
		s = frase[idx_letra];
		if (s==' '){
			aux = frase.substr(idx1, idx2 - idx1);
			if((aux[aux.size() - 1] == '.') || 
				(aux[aux.size() - 1] == ',') || 
				(aux[aux.size() - 1] == ';') || 
				(aux[aux.size() - 1] == ':') || 
				(aux[aux.size() - 1] == '!') || 
				(aux[aux.size() - 1] == '?') 
				
		  	  ){
				aux.pop_back();
			}
			palavras.push_back(aux);
			idx1 = idx2 + 1;
		}	
		idx2++;		
	}
	//ultima palavra
	aux = frase.substr(idx1, idx2 - idx1);
	if((aux[aux.size() - 1] == '.') || 
		(aux[aux.size() - 1] == ',') || 
		(aux[aux.size() - 1] == ';') || 
		(aux[aux.size() - 1] == ':') || 
		(aux[aux.size() - 1] == '!') || 
		(aux[aux.size() - 1] == '?')){
	       aux.pop_back();
	}	       
				
	
	palavras.push_back(aux);
	return palavras;

}
