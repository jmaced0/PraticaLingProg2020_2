Obs.: O código foi desenvolvido e testado no Linux, distribuição Ubuntu 20.04.

 
1.Compilação do programa

	O programa é compilado por meio do comando "make", onde primeiramente os objetos de cada arquivo são criados e posteriomente ocorre a linkedição. Após o processo de compilação, o arquivo executável "programa" e os objetos são criados, esses arquivos podem ser removidos por meio do comando "make clean".

2.Utilização do programa

	Após abrir o executável, sem argumentos, por exemplo usando "./programa", um MENU contendo as opções requisitadas é disponibilizado na tela. Para acessar uma das opções basta digitar o numero referente a ela e posteriormente pressionar ENTER.
	Opcoes:
	1) Exibe uma lista com as palavras do texto e sua o numero de vezes que ela apareceu no texto.
	2) Exibe os dois vertices mais frequentes no grafo assimetrico cujos vertices são as palavras.
	3) Analogo ao item anterior mais com a opção de escolher o numero de vertices a ser exibido.
	4) Sair do programa

Observações:
	1- Caso queira usar outro arquivo de texto, troque o nome deste arquivo para "texto_teste.txt" e o coloque na mesma pasta do executável.
	2- Caso haja empate no numero de vertices mais frequentes, os primeiros a serem mostrados seram aqueles que foram lidos por ultimo do texto.
