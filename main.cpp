#include "covidStats.h"
#include <algorithm>

int main (){
	vector <string> names = {"RO", "AC", "AM", "RR", "PA", "AP", "TO", //norte
	"MA", "PI", "CE", "RN", "PB", "PE", "AL", "SE", "BA",              //nordeste
	"MG", "ES", "RJ", "SP", //sudest
	"PR", "SC", "RS",       //sul
	"MS", "MT", "GO", "DF"}; // centro-oeste + DF


	vector <double> mediaMovel;
	vector <unsigned> serieHistorica;
	Nacional brasil("Brasil"); // instanciar objeto

	fillCovidData(names.size(), TAM_SERIE, brasil, names); //preencher serie histórica com dados aleatórios
	

	int menu_select = 0;
	unsigned idx_estados, idx_dias;

	while (menu_select != -1){
	
		cout << "\nEscolha uma opção do menu \n\t1  - Exibir media movel " << endl;
		cout << "\t2  - Exibir situacao dos estados (mortes em alta, baixa ou estabilidade)" << endl;
		cout << "\t3  - Exibir situacao do Brasil" << endl;
		cout << "\t4  - Exibir estados com maiores alta e baixa segundo media movel" << endl;
		cout << "\t5  - Exibir dados acumulados nos estados e no Brasil" << endl;
		cout << "\t-1 - Sair do programa" << endl;
		cout << "Digite a opção desejada: ";
		
		cin >> menu_select;

		if (menu_select == 1) {
			
			
			cout << "\n\t\t\t\t\t\tMedia Movel (ordem 3)\n" << endl;
			cout << "Dia";
			for (idx_dias = 0; idx_dias < NUM_DIAS; idx_dias++ ){
				if (idx_dias == NUM_DIAS -1){ cout << "\tHoje";}
				else{cout << "\t"<< idx_dias + 1;}
			}
			cout << endl;
			
			for (idx_estados = 0; idx_estados < names.size() ; idx_estados ++){

				serieHistorica  = brasil.getSerieHistoricaEstadual(idx_estados);
				mediaMovel = movMean(serieHistorica, 3);
				cout << "\n" << names[idx_estados];

				for (int idx_dias = 0; idx_dias < NUM_DIAS; idx_dias++ ){
					cout << "\t" << mediaMovel[idx_dias];
				}	
			}
			serieHistorica  = brasil.getSerieHistorica();
			mediaMovel = movMean(serieHistorica, 3);
			
			
			cout << "\nBrasil";

			for (int idx_dias = 0; idx_dias < NUM_DIAS; idx_dias++ ){
				cout << "\t" << mediaMovel[idx_dias];
			}
			cout <<endl;	
		}		

		else if (menu_select == 2){

			vector <string> estados_alta, estados_baixa, estados_estavel;

			for (idx_estados = 0; idx_estados < names.size() ; idx_estados ++){

				serieHistorica  = brasil.getSerieHistoricaEstadual(idx_estados);
				mediaMovel = movMean(serieHistorica, 3);

				double aux = mediaMovel[NUM_DIAS - 1] / mediaMovel[NUM_DIAS - 4];

				if (aux < 0.85){
					estados_baixa.push_back(names[idx_estados]);
				}
				else if (aux > 1.15){
					estados_alta.push_back(names[idx_estados]);
				}
				else{
					estados_estavel.push_back(names[idx_estados]);
				}
			}

			cout << "\nEstados em alta" << endl;
			for (idx_estados = 0; idx_estados < estados_alta.size(); idx_estados++){
				cout << "\t\t" << estados_alta[idx_estados] <<endl;
			}	
			
			cout << "\nEstados em estabilidade" << endl;
			for (idx_estados = 0; idx_estados < estados_estavel.size(); idx_estados++){
				cout << "\t\t" << estados_estavel[idx_estados] <<endl;
			}

			cout << "\nEstados em baixa" << endl;
			for (idx_estados = 0; idx_estados < estados_baixa.size(); idx_estados++){
				cout << "\t\t" << estados_baixa[idx_estados] <<endl;
			}	


		}

		else if (menu_select == 3){

			
			serieHistorica  = brasil.getSerieHistorica();
			mediaMovel = movMean(serieHistorica, 3);
		
			double aux = mediaMovel[NUM_DIAS - 1] / mediaMovel[NUM_DIAS - 4];

			cout << "\nSituacao do Brasil em relacao ha 3 dias: " ;
			if (aux < 0.85){
				cout << "baixa de " << 100*(1 - aux) << "%\n"<< endl;
			}
			else if (aux > 1.15){
				cout << "alta de " << 100*(aux - 1) << "%\n" << endl;
			}
			else{
				cout << "estabilidade com variacao de " << 100*(aux - 1) << "%\n" << endl;
			}	
		}

		else if (menu_select == 4){
			vector <double> variacao;
			for (idx_estados = 0; idx_estados < names.size() ; idx_estados ++){

				serieHistorica  = brasil.getSerieHistoricaEstadual(idx_estados);
				mediaMovel = movMean(serieHistorica, 3);

				variacao.push_back( mediaMovel[NUM_DIAS - 1] / mediaMovel[NUM_DIAS - 4]);
			}

			unsigned max_idx = distance(variacao.begin(), max_element(variacao.begin(),variacao.end()));
			unsigned min_idx = distance(variacao.begin(), min_element(variacao.begin(),variacao.end()));

			cout << endl;
			cout << "Estado com maior baixa: " << names[min_idx] << " com uma reducao de " << 100*(1 - variacao[min_idx]) << "%" << endl;
			cout << "Estado com maior alta: "  << names[max_idx] << " com um aumento de "  << 100*(variacao[max_idx] - 1) << "%" << endl;
		}

		else if (menu_select == 5){
			cout << endl;
			brasil.printTotalMortes();
		}
		
		else if (menu_select !=-1){
			
			// Tratar erro do Cin
			if (cin.bad() || cin.fail()){
				cin.clear();
				cin.ignore();
				menu_select = 0;
				cout << "\nEntrada deve ser um inteiro entre -1 e 5. Tente novamente." << endl;
			}

			else {cout << "Opcao invalida! Tente novamente." << endl;}
		}

	}
	
	return 0;
}
