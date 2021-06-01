#include "catalogo.h"

/*Construtor
 */
Catalogo::Catalogo (unsigned max) : max_filmes(max) {}


/* Imprimir catalogo
 */
ostream &operator<< (ostream &out, Catalogo const & cat){
	for (auto  film: cat.filmes ){
		cout << film << endl;
	}	
	return out;
}



void Catalogo::sortFilmes(){
	/* Metodo sort usa o operador < para realizar a comparacao
	 */
	sort(filmes.begin(), filmes.end());
}


// Inserção de um filme
Catalogo &Catalogo::operator+= (Filme film){
	if (filmes.size() < max_filmes){ 
		bool achou = false;
		for (auto f : filmes){
			if (f == film) {
				achou = true;
				break;
			}
		}
		/* Caso filme não esteja na lista
		 */
		if (!achou){

			filmes.insert(filmes.begin(), film);
			sortFilmes();
		}
		else {
			cout << "Filme já está na lista" << endl;
		}
       	}
	else {
	       cout << "Catalogo cheio" << endl;
	}	       
	
	return *this;
}
// Inserção de um vetor de filmes
Catalogo &Catalogo::operator+= (vector <Filme> vec_filmes){

	for (auto film : vec_filmes){
		if (filmes.size() < max_filmes){ 
			bool achou = false;
			for (auto f : filmes){
				if (f == film) {
					achou = true;
					break;
				}
			}
			/* Caso filme não esteja na lista
			 */
			if (!achou){

				filmes.insert(filmes.begin(), film);
				sortFilmes(); // não dá para ordenar no fim, pois catalogo pode ficar cheio
			}
			else {
				cout << "Filme " <<  film.titulo <<" já está na lista" << endl;
			}
	       	}
		else {
		       cout << "Catalogo cheio" << endl;
	       	break;
		}	       
	}
	
	return *this;
}


// Remoção de um filme
Catalogo &Catalogo::operator-= (Filme film){
		if (filmes.size() == 0){
			cout << "Catalogo vazio" << endl;
			return *this;
		}
		bool achou = false;
		unsigned idx = 0;
		for (auto f : filmes){
			if (f == film) {
				achou = true;
				break;
			}
			idx++;
		}
		/* Caso filme não esteja na lista
		 */
		if (achou){
			filmes.erase(filmes.begin() + idx);
			sortFilmes();
			cout << "Filme apagado" << endl;
		}
		else {
			cout << "Filme não estava no catalogo" << endl;
		}
		return *this;
}

//Busca de um filme no catalogo
Filme* Catalogo::operator() (string nome){
		if (filmes.size() == 0){
			cout << "Catalogo vazio" << endl;
			return nullptr;
		}
		Filme *film = new Filme;
		bool achou = false;
		unsigned idx = 0;

		
		for (auto f : filmes){
			if (f.titulo == nome) {
				achou = true;
				break;
			}
			idx++;
		}

		/* Caso filme não esteja na lista
		 */
		if (achou){
			film->titulo = filmes.at(idx).titulo;
			film->produtora = filmes.at(idx).produtora;
			film->nota = filmes.at(idx).nota;
			return film;
		}
		else {

			delete film;
			return nullptr;
		}

}


//Editar produtora do filme
Filme* Catalogo::operator() (string nome, string prod){
		if (filmes.size() == 0){
			cout << "Catalogo vazio" << endl;
			return nullptr;
		}
		Filme *film = new Filme;
		bool achou = false;
		unsigned idx = 0;

		for (auto f : filmes){
			if (f.titulo == nome) {
				achou = true;
				break;
			}
			idx++;
		}

		/* Caso filme não esteja na lista
		 */
		if (achou){
			cout << prod << endl;
			filmes.at(idx).produtora = prod;
			film->titulo = filmes.at(idx).titulo;
			film->produtora = filmes.at(idx).produtora;
			film->nota = filmes.at(idx).nota;
			return film;
		}
		else {
			delete film;
			return nullptr;
		}

}


//Editar nota do filme
Filme* Catalogo::operator() (string nome, double n){
		if (filmes.size() == 0){
			cout << "Catalogo vazio" << endl;
			return nullptr;
		}
		Filme *film = new Filme;
		bool achou = false;
		unsigned idx = 0;

		for (auto f : filmes){
			if (f.titulo == nome) {
				achou = true;
				break;
			}
			idx++;
		}

		/* Caso filme não esteja na lista
		 */
		if (achou){
			filmes.at(idx).nota = n;
			film->titulo = filmes.at(idx).titulo;
			film->produtora = filmes.at(idx).produtora;
			film->nota = filmes.at(idx).nota;
			return film;
		}
		else {
			delete film;
			return nullptr;
		}

}

//Buscar filme mais bem avaliado
Filme* Catalogo::BuscarMelhorAvaliado(){

	unsigned idx = 0;
	unsigned idx_melhor = 0;
	unsigned melhor_nota = 0;

	if (filmes.size() == 0){
		cout << "Catalogo vazio" << endl;
		return nullptr;
	}

	for( auto f : filmes){
		if (f.nota > melhor_nota) {
		       melhor_nota = f.nota;
	      		idx_melhor = idx;
		}
		idx++;
	}		

	Filme *film = new Filme;
	film->titulo = filmes.at(idx_melhor).titulo;
	film->produtora = filmes.at(idx_melhor).produtora;
	film->nota = filmes.at(idx_melhor).nota;

	return film;
}

//Salvar catalogo
void Catalogo::SalvarCatalogo(string nome_arquivo){

	ofstream arquivo(nome_arquivo, fstream::in | fstream::trunc);
	if (!arquivo.is_open()){
		cout << "Falha ao abrir arquivo. Não foi possível salvar o catalogo" << endl;
	}

	else{	
		for (auto f: filmes){
			arquivo << f.titulo << '\n' << f.produtora << '\n' <<f.nota << '\n';
		}
	}
	arquivo.close();

}
