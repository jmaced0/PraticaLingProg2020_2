#include "catalogo.h"
#include "filme.h"

int main(){
	unsigned const MAX_FILMES = 20;

	vector <Filme> vec_filmes;
	Catalogo catalogo(MAX_FILMES);
	Filme aux;

	//Abrir ou criar arquivo
	string nome_arquivo("arquivo.txt");


	ifstream arquivo;
	arquivo.open(nome_arquivo, fstream::in);

	if(arquivo.is_open()){
		//Ler filmes
		if (arquivo.peek() != '\0'){
			unsigned contadorFilmes = 0;
			arquivo >> aux.titulo >> aux.produtora >> aux.nota;
			while (!arquivo.eof()){ 
				vec_filmes.push_back(aux);
				contadorFilmes++;
				arquivo >> aux.titulo >> aux.produtora >> aux.nota;
			}
		}
	
		//
		arquivo.close();	
	}

	catalogo += vec_filmes;

	int menu = 0;
	while (menu != 8){
		cout << "Opções do menu: " << endl;
		cout << "\t1) Mostrar filmes no catalogo" << endl;
		cout << "\t2) Inserir um filme no catalogo" << endl;
		cout << "\t3) Remover um filme do catalogo" << endl;
		cout << "\t4) Buscar um filme no catalogo" << endl;
		cout << "\t5) Editar produtora de um filme" << endl;
		cout << "\t6) Editar nota de um filme" << endl;
		cout << "\t7) Buscar filme melhor avaliado" << endl;
		cout << "\t8) Sair do programa" << endl;
		cout << "Digite um inteiro referente a opcao desejada: ";
		
		cin.clear();
		cin >> menu;
		cout << endl;
		if (menu == 1){
			cout << catalogo << endl;

		}
		
		else if (menu == 2){
			cin.clear();
			cin >> aux;

			catalogo += aux;


		}

		else if (menu == 3){

			string nome;
			cout << "Digite o nome do filme a ser removido: ";
			cin.clear();
			cin.ignore();
			getline (cin, nome);

			aux.titulo = nome;
			catalogo -= aux;

		}

		else if (menu == 4){

			string nome;
			cout << "Digite o nome do filme: ";
			cin.clear();
			cin.ignore();
			getline (cin, nome);

			Filme *filmePtr = catalogo(nome);
			if(filmePtr ==nullptr){
				cout << "Filme não encontrado" << endl;
			}
			else {	cout << *filmePtr << endl;}

			delete filmePtr;
		}

		else if (menu == 5){

			string nome;
			cout << "Digite o nome do filme a ser editado: ";
			cin.clear();
			cin.ignore();
			getline (cin, nome);
			
			
			
			string prod;
			cout << "Digite o nome da nova produtora: ";
			cin.clear();
			getline (cin, prod);

			Filme *filmePtr = catalogo(nome, prod);

			delete filmePtr;
			

		}
		else if (menu == 6){

			string nome;
			cout << "Digite o nome do filme a ser editado: ";
			cin.clear();
			cin.ignore();
			getline (cin, nome);
			


			double nota;
			
			cout << "Digite a nova nota: ";
			cin.clear();
			cin >> nota;

			Filme *filmePtr = catalogo(nome, nota);


			delete filmePtr;
		}
		else if (menu == 7){
			Filme *filmePtr = catalogo.BuscarMelhorAvaliado();
			cout << *filmePtr << endl;
			

			delete filmePtr;

		}
		else if (menu != 8){
			
			if(cin.bad() || cin.fail()){
				cin.clear();
				cin.ignore();
				menu = 0;
				cout << "\n Entrada deve ser um inteiro entre 1 e 8. Tente novamente" <<endl;
			}
			else{ cout << "Opcao inválida! Tente novamente" << endl;}

		}
	}

	catalogo.SalvarCatalogo(nome_arquivo);

	return 0;

}
