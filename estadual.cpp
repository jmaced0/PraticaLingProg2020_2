#include "estadual.h"

Estadual::Estadual (string state_name, vector<unsigned> serieHistorica){
	//Checar se tamanho da série ultrapassado o valor maximo, definido pela macro TAM_SERIE
	//caso ultrapasse, pega apenas ultimos elementos da serie
	if (serieHistorica.size() > TAM_SERIE){
		cout << "Serie Histórica é limitada a " << TAM_SERIE << "elementos. A serie foi truncada" << endl;
		vector<unsigned> aux(serieHistorica.end() - TAM_SERIE, serieHistorica.end());
		mortes = aux;
	}
	else {	mortes = serieHistorica;}

	name = state_name;
}

void Estadual::setSerieHistorica(vector <unsigned> serie){
	//Checar se tamanho da série ultrapassado o valor maximo, definido pela macro TAM_SERIE
	//caso ultrapasse, pega apenas ultimos elementos da serie
	if (serie.size() > TAM_SERIE){
		cout << "Serie Histórica é limitada a " << TAM_SERIE << "elementos. A serie foi truncada" << endl;
		vector<unsigned> aux(serie.end() - TAM_SERIE, serie.end());
		mortes = aux;
	}
	else {	mortes = serie;}
}

unsigned Estadual::getTotalMortes(){
	unsigned sum = 0;
	for (unsigned idx = 0; idx < mortes.size(); idx++ ){ sum += mortes[idx];}
	return sum;
}

vector <unsigned> Estadual::getSerieHistorica(){return mortes;}

string Estadual::getNome(){return name;}

