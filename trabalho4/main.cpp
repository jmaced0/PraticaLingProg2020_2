#include "cadastro.h"
#include "paciente.h"
#include "excecoes.h"

int main(){

	Cadastro<PacienteBase*> cad;
	int menu = 0;
	while (menu != 4){
		cout << "Opções do menu: " << endl;
		cout << "\t1) Inserir um paciente no cadastro" << endl;
		cout << "\t2) Busca um paciente no cadastro" << endl;
		cout << "\t3) Imprimir cadastro" << endl;
		cout << "\t4) Sair do programa" << endl;
		cout << "Digite um inteiro referente a opcao desejada: ";
		
		cin.clear();
		cin >> menu;
		cout << endl;
		if (menu == 1){
			int opcao = 0;
			cout << "Existem dois possíveis cadastros de paciente. Escolha uma opcao: " << endl;
			cout << "\t1) Inserir apenas nome e idade" << endl;
			cout << "\t2) Inserir nome, idade e diagnostico" << endl;
			cin.clear();
			cin >> opcao;
			cout << endl;
			
			if (opcao == 1){
				string nome;
				unsigned idade;

				cin.clear();
				cin.ignore();
				cout << "Digite o nome do paciente: ";
				getline(cin, nome);
				cout << "Digite a idade do paciente: ";
				cin >> idade;

				try{
					if( (cad += new PacienteBase(nome, idade))  == nullptr){
						InsertExcept e;
						throw e;
					}else {	cout << "Paciente adicionado com sucesso!" << endl;}
					
				}catch(exception &e){cout << e.what() << endl;}
			}	
			else if(opcao == 2){
				string nome;
				unsigned idade;
				string diag;

				cin.clear();
				cin.ignore();
				cout << "Digite o nome do paciente: ";
				getline(cin, nome);

				cout << "Digite o diagnostico do paciente: ";
				getline(cin, diag);
					
				cout << "Digite a idade do paciente: ";
				cin >> idade;

				try{
					if( (cad += new Paciente(nome, idade, diag))  == nullptr){
						InsertExcept e;
						throw e;
					}
					else {cout << "Paciente adicionado com sucesso!" << endl;}
				}catch(exception &e){cout << e.what() << endl;}
			}
			else if(opcao != 1 || opcao != 2)
				if(cin.bad() || cin.fail()){
				cin.clear();
				cin.ignore();
				opcao = 0;
				cout << "\n Entrada deve ser um inteiro entre 1 e 2. Tente novamente" <<endl;
			}
		}
		
		else if (menu == 2){

			string nome;
			cin.clear();
			cin.ignore();
			cout << "Digite o nome do paciente: ";
			getline(cin, nome);

			try{
				//PacienteBase *pac = new PacienteBase; 
				///pac = cad(nome);
	
				if ( cad(nome) == nullptr){
					SearchExcept aux;
					throw aux;
				}
				else {
			       	cout << *cad(nome) << endl;
				}

				//delete pac;
			}
			catch(exception &e){
				cout << e.what() << endl;
			}
		}

		else if (menu == 3){
			cout << cad << endl;		
		}

		else if (menu != 4){
			
			if(cin.bad() || cin.fail()){
				cin.clear();
				cin.ignore();
				menu = 0;
				cout << "\n Entrada deve ser um inteiro entre 1 e 4. Tente novamente" <<endl;
			}
		}
	}
/*
	Paciente *pacienteA = new Paciente("Jose Guilherme", 22, "dcmkl");
	Paciente *pacienteB = new Paciente("Juliana", 20, "iwi");

	cad += pacienteA;
	cad += pacienteB;

	cout << *pacienteA << endl;	

	
	


	cout << "Procurando Jose" << endl;
	try{
		Node<PacienteBase*> *pac = cad("Jose Guilherme");
	
		if (pac == nullptr){
			SearchExcept aux;
			throw aux;
		}
		else {
		       	cout << *pac->dado << endl;
		}
	}
	catch(exception &e){
		cout << e.what() << endl;
	}

	cout << "Procurando Marcos" << endl;
	try{
		Node<PacienteBase*> *pac = cad("Marcos");
	
		if (pac == nullptr){
			SearchExcept aux;
			throw aux;
		}
		else {
		       	cout << *pac->dado << endl;
		}
	}
	catch(exception &e){
		cout << e.what() << endl;
	}


	//delete pacienteA;
	//delete pacienteB;
*/
	return 0;

}
