#include <cstdlib>
#include <ctime>
#include "nacional.h"
#define MAX_MORTES_DIA 200
using namespace std;

// Preenche vetor com dados aleatorios entre 0 e o valor definido pela macro MAX_MORTES_DIA no
// arquivo covidStats.h
void fillCovidData (unsigned, unsigned, Nacional&, vector <string>);

//Calcula a média movel de ordem n do vetor data
//retorna vetor vazio caso a ordem seja maior que o tamanho do vetor
vector <double> movMean (vector <unsigned>&, unsigned);

