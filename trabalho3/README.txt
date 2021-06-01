Obs.: O código foi desenvolvido e testado no Linux, distribuição Ubuntu 20.04.

 
1.Compilação do programa

	O programa é compilado por meio do comando "make", onde primeiramente os objetos de cada arquivo são criados e posteriomente ocorre a linkedição. Após o processo de compilação, o arquivo executável "programa" e os objetos são criados, esses arquivos podem ser removidos por meio do comando "make clean".

2.Utilização do programa

	Após abrir o executável, sem argumentos, por exemplo usando "./programa", um MENU contendo as opções requisitadas é disponibilizado na tela. Para acessar uma das opções basta digitar o numero referente a ela e posteriormente pressionar ENTER.
	Existe um arquivo de texto com 3 filmes ficticios na pasta, apenas para exemplificar o funcionamento do programa. Mas caso não haja um arquivo com o nome "arquivo.txt" na pasta do executável, um novo arquivo será criado ao fim da execução do programa
	Opcoes:
	1) Exibe todos os filmes do catálogo
	2) Insere um novo filme no catálogo
	3) Remove um filme do catálogo realizando a busca pelo nome a ser digitado
	4) Busca um filme no catálogo usando como chave seu nome e então exibe as informações do filme
	5) Altera a produtadora de determinado filme
	6) Altera a nota de determinado filme
	7) Exibe as informações do filme com maior nota
	8) Sai do programa

