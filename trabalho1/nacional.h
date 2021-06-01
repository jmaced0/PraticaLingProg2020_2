#include "estadual.h"
#define NUM_ESTADOS 27

class Nacional{
	private:
		//contador para verificar se tamanho máximo de estador já foi alcançado
		unsigned contador_estados;
		//nome do pais
		string nome;
		//vetor de objetos estado
		vector <Estadual> estados;

	public:
		//contructor, seta apenas o nome do estado
		Nacional (string);
		//seta o nome e a série histórica de cada estado
		void setInfoEstado(string , vector <unsigned> );
		//retornar a serie histórica de mortes no país
		vector <unsigned> getSerieHistorica();
		vector <unsigned> getSerieHistoricaEstadual(unsigned);

		void printTotalMortes();

};
