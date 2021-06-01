#include "paciente.h"

// Classe Base

//Construtores
PacienteBase::PacienteBase(){};
PacienteBase::PacienteBase(string name, unsigned age){
	nome = name;
	idade = age;
}
PacienteBase::PacienteBase(const PacienteBase &pac){
	nome = pac.nome;
	idade = pac.idade;
}
//
PacienteBase::~PacienteBase(){}


// Set e Get
string PacienteBase::getNome(){ return nome;}
string PacienteBase::getKey(){ return nome;}
unsigned PacienteBase::getIdade(){ return idade;}

void PacienteBase::setNome(string name){ nome = name;}
void PacienteBase::setIdade(unsigned age){ idade = age;}

//Funcao auxiliar para imprimir
ostream& PacienteBase::print(ostream &out) const{
	out << "Nome: " << nome << endl;
	out << "Idade: " << idade << endl;
	return out;
}

//Operadores sobrecarregados usados para impressão e comparacao
ostream &operator<< (ostream &out, PacienteBase const &patient){
	//cout << "Tipo do objeto: " << typeid(patient).name() << endl;
	return patient.print(out);
}

bool PacienteBase::operator< (const PacienteBase &pac){
	return this->nome < pac.nome ? true:false;
}

bool PacienteBase::operator> (const PacienteBase &pac){
	return this->nome > pac.nome ? true:false;
}

bool PacienteBase::operator== (const PacienteBase &pac){
	return this->nome == pac.nome ? true:false;
}




//Classe Derivada

//Construtores
Paciente::Paciente(){};
Paciente::Paciente(const Paciente &pac){
	nome = pac.nome;
	idade = pac.idade;
	diagnostico = pac.diagnostico;
}
Paciente::Paciente(string name, unsigned age, string diag): PacienteBase(name, age){
	diagnostico = diag;
}

Paciente::~Paciente(){}


//Set e Get
string Paciente::getDiagnostico(){ return diagnostico;}
void Paciente::setDiagnostico(string diag){ diagnostico = diag;}

// Funcao auxiliar para imprimir
ostream& Paciente::print(ostream &out) const{
	out << "Nome: " << nome << endl;
	out << "Idade: " << idade << endl;
	out << "Diagnostico: " << diagnostico << endl;
	return out;
}
