#include "nacional.h"

//contructor
Nacional::Nacional(string name){
	nome = name;
	contador_estados = 0;
}

//Adicionar estado
void Nacional::setInfoEstado (string name, vector <unsigned> serie){
	if (contador_estados > NUM_ESTADOS){
		cout << "Todos os estados já foram criados, só é possível atualizar a série histórica" << endl;
	}
	else{
		//cria um estado e põe no final do vetor de estados
		Estadual estado(name, serie);
		estados.push_back(estado);

		//incrementa o numero de estados na lista
		contador_estados++;
	}
}


//Obter serie historica

// Retorna serie historica de mortes por estado
vector <unsigned> Nacional::getSerieHistoricaEstadual(unsigned idx){
	vector <unsigned> data;
	data = estados[idx].getSerieHistorica();
	return data;
}

//função para somar dois vetores
//Trunca na menor dimensão entre os dois vetores
vector <unsigned> SomarVetores(vector <unsigned> vecA, vector<unsigned> vecB){
	vector <unsigned> sum;
	
	if (vecA.size() <= vecB.size()){
		for (unsigned idx = 0; idx < vecA.size(); idx++){
			sum.push_back( vecA[idx] + vecB[idx]);
		}

	}
	else{

		for (unsigned idx = 0; idx < vecB.size(); idx++){
			sum.push_back( vecA[idx] + vecB[idx]);
		}
	}
	return sum;
}
// Retorna serie historica de mortes do país
vector <unsigned> Nacional::getSerieHistorica(){
	vector <unsigned> sum;
	sum = estados[0].getSerieHistorica();
	for (unsigned idx = 1; idx < estados.size(); idx++){
		sum = SomarVetores(sum, estados[idx].getSerieHistorica());
	}
	return sum;
}


// Printa o total de mortes no pais e por estado
void Nacional::printTotalMortes(){
	unsigned sum = 0;
	cout << "\t\t\t\t\tTotal de mortes por estados e total no pais nos ultimos " << TAM_SERIE << " dias:" << endl;

	for (unsigned idx = 0; idx < estados.size(); idx++){
		unsigned aux = estados[idx].getTotalMortes();
		cout << estados[idx].getNome() << "\t" << aux << endl;
	        sum += aux;
	}

	cout << nome  << "\t" << sum << "\n" <<endl;
}	




