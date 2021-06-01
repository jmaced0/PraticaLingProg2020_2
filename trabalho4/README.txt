Obs.: O código foi desenvolvido e testado no Linux, distribuição Ubuntu 20.04.

 
1.Compilação do programa

	O programa é compilado por meio do comando "make", onde primeiramente os objetos de cada arquivo são criados e posteriomente ocorre a linkedição. Após o processo de compilação, o arquivo executável "programa" e os objetos são criados, esses arquivos podem ser removidos por meio do comando "make clean".

2.Utilização do programa

	Após abrir o executável, sem argumentos, por exemplo usando "./programa", um MENU contendo as opções requisitadas é disponibilizado na tela. Para acessar uma das opções basta digitar o numero referente a ela e posteriormente pressionar ENTER.
	Opcoes:
	1) Inserir um paciente no cadastro
	2) Buscar um paciente no cadastro
	3) Imprimir todos os pacientes do cadastro
	4) Sai do programa

Obs.: A inserção de pacientes apresenta duas subopções para representa a inserção de um objeto da classe base ou um objeto da classe derivada. A impressão dos pacientes é feita usando polimorfismo, ou seja, independete do tipo de objeto adcionado a arvore, a impressao será realizada o metodo virtual da classe em questão, base ou principal. Além disso, foi implementado um metodo "getKey()"	para que a inserção na arvore seja generica, ou seja, todo tipo de paciente adicionado a arvore deve ter esse metodo.

