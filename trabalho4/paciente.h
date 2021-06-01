#ifndef PACIENTE_H
#define PACIENTE_H

#include <iostream>
#include <string>

using namespace std;

class PacienteBase{
	protected:
		string nome;
		unsigned idade;
	public:
		PacienteBase(string, unsigned);
		PacienteBase();
		PacienteBase(const PacienteBase&); //copy constructor
		virtual ~PacienteBase();
		
		//Impressao
		friend ostream& operator<< (ostream &, const PacienteBase &);
		virtual ostream& print(ostream &) const;
		
		//Set e Get dos atributos
		string getNome();
		string getKey(); //so para funcao ter nome padrao
		void setNome(string);
		unsigned getIdade();
		void setIdade(unsigned);

		//sobrecarga de operadores para comparacao
		bool operator<  (const PacienteBase &);
		bool operator>  (const PacienteBase &);
		bool operator== (const PacienteBase &);
		
};



class Paciente: public PacienteBase{
	protected:
		string diagnostico;
	public:
		//construtor
		Paciente(string, unsigned, string);
		Paciente();
		Paciente(const Paciente&);
		virtual ~Paciente();

		virtual ostream& print(ostream &) const override;
		
		//Set e Get dos atributos
		string getDiagnostico();
		void setDiagnostico(string);
		
};

#endif
