#include "covidStats.h"


// Preenche vetor com dados aleatorios entre 0 e o valor definido pela macro MAX_MORTES_DIA no
// arquivo covidStats.h
void fillCovidData(unsigned dim1, unsigned dim2, Nacional& country, vector <string> states){
	
	srand(time(nullptr)); //seed based on current time
	vector <unsigned> aux_vec;

		
	for( unsigned idx_dim1 = 0; idx_dim1 < dim1 ; idx_dim1++){

		aux_vec.clear();
		for (unsigned idx_dim2 = 0; idx_dim2 < dim2; idx_dim2++)	{
			aux_vec.push_back(rand() % (MAX_MORTES_DIA + 1));
		}
		country.setInfoEstado(states[idx_dim1], aux_vec);
	}
}

//Calcula a média movel de ordem n do vetor data
//retorna vetor vazio caso a ordem seja maior que o tamanho do vetor
vector <double> movMean (vector <unsigned>& data, unsigned order = 3){
	vector <double> moveMean;
	unsigned aux, idx_data, idx_mean;

	if (order > data.size()){
		cout << "Ordem da média movel deve ser menor que o tamanho do vetor" << endl;
		moveMean.clear();
		return moveMean;
	}
	else{
		
		for (idx_data = order-1; idx_data < data.size(); idx_data ++ ){
			aux = 0;
			for (idx_mean = idx_data; idx_mean >= idx_data - order + 1 && idx_mean < data.size()+1; idx_mean-- ){
				aux += data[idx_mean];
			}
			
			moveMean.push_back(aux / order);
		}
		return moveMean;
	}	
}	


