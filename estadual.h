#include <vector>
#include <string>
#include <iostream>

#define NUM_DIAS 14
#define TAM_SERIE (NUM_DIAS + 2)

using namespace std;

class Estadual {
	private:
		// vetor para armazenar seria histórica de mortes
		vector <unsigned> mortes;
		
		// nome do estado
		string name;

		
	public:
		//métodos para retorna o numero de mortes, total ou a serie histórica
		unsigned getTotalMortes();
		vector <unsigned> getSerieHistorica();

		//métodos para mudar série historica
		void setSerieHistorica(vector <unsigned>);

		//constructor
		Estadual(string, vector<unsigned>);

		string getNome();
			
};
