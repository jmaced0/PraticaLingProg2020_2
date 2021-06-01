Enunciado:

Escreva um programa que leia linhas de texto de um arquivo *.txt e encontre as palavras
mais utilizadas, assim como as sequências de duas ou mais palavras consecutivas mais
utilizadas. Caso haja alguma pontuação entre as sequências de palavras, essa construção
não deve ser contabilizada. Considere que o arquivo *.txt já existe no mesmo diretório do
programa executável. Este arquivo pode trazer um texto como o abaixo:
Essa frase é um exemplo e, a partir dessa frase, espera-se que o exercício fique
claro. Essa frase tem pontuação. Todas as construções de palavras consecutivas
com pontuação devem ser excluídas.
Modele o problema como um grafo assimétrico, onde os vértices são as palavras e as
arestas são formadas entre pares de palavras que aparecem de forma consecutiva no
texto. As arestas podem ser ponderadas com peso igual ao número de aparições no texto.
Ao final, um grafo como o representado na figura abaixo, relativo ao texto do exemplo, será
modelado. Percebe-se pelo grafo abaixo que a aresta formada entre as palavras “essa” e
“frase” é a de maior destaque, assim como o rótulo dos vértices referentes às palavras
“frase” e “pontuação”. Isso indica que tanto a sequência “essa frase”, quanto as palavras
“frase” e “pontuação” foram as mais utilizadas no texto.
O programa implementa o grafo como uma classe. Da mesma forma, as arestas e os
vértices também são implementados como classes. A classe Grafo possui um método de
inserção de arestas, enquanto a classe aresta possui um método construtor que define os
seus vértices de origem e de destino. Os vértices e arestas podem ser criados conforme o
texto é lido. Ainda, a classe Grafo possui um método que retorna o vértice mais utilizado,
assim como a sequência de N arestas mais comum, ou seja, a sequência cuja soma dos
pesos das arestas é maior. Dessa forma, pede-se a implementação de um programa que
responda as seguintes perguntas:
1. Qual é(são) a(s) palavra(s) mais utilizada(s) no texto?
2. Qual é a sequência de 2 palavras consecutivas mais utilizada no texto?
3. Quais são as sequências de N palavras consecutivas mais utilizada no texto, no
qual o valor de N é passado pelo usuário como uma opção? Abstraia a
possibilidade da sequência não existir no texto.
Observação 1: Não é necessário produzir uma figura como a apresentada no enunciado.
A figura é apenas ilustrativa.
Observação 2: Use textos pequenos com apenas um parágrafo.
Observação 3: O tamanho máximo de N pode ser estabelecido manualmente (através de
uma variável do programa) conforme o tamanho máximo das frases do texto.


Observações do autor

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
