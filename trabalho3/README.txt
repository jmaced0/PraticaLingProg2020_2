
Enunciado

Escreva um programa que implemente uma classe Catalogo para gerenciamento de
filmes. O filme é definido a partir de uma struct (não é classe) contendo uma string
com o nome do filme, uma string com o nome da produtora e um double para
armazenar a nota do filme conforme a avaliação do dono do catálogo. Já a classe
Catalogo implementa uma estrutura do tipo vector para armazenar os filmes, além de
um tamanho máximo para o número de filmes. As diferentes ações permitidas com o objeto
da classe Catalogo devem usar operadores como se segue:
 Inserção ordenada de um filme no catálogo: deve ser feita com o operador +=.
Por exemplo, “catalogo += filme” insere um filme ordenado pelo nome no
catálogo. Note que o nome, produtora e nota do filme devem ser inicializados
previamente, antes da inserção. A inserção deve prever também a possibilidade de
inserção de um vector de filmes, como uma operação de inserção em lote. Nesse
caso, a inserção pode ser feita ao final do vector de filmes da classe e
reordenada por completo a posteriori. Experimente o método insert da classe
vector.
O operador < (ou >) deve ser implementado para que a comparação entre filmes
seja possível. Por exemplo, “filme1 < filme2” deve retornar true caso o nome
do filme1 seja menor que o nome do filme2. Ainda, a classe Catalogo não
permite a inserção de filmes com o mesmo nome. Dessa forma, é importante
implementar o operador == para verificar se o filme a ser inserido tem o mesmo
nome de outro já existente. Por exemplo, “filme1 == filme2” deve retornar
true se os nomes dos filmes forem os mesmos e false, caso contrário.
 Remoção de um filme do catálogo: deve ser feito através do operador -=. Por
exemplo, “catalogo -= filme” remove o filme do catálogo. A busca do filme
deve ser feita a partir do nome do filme e a remoção no vector pode usar o
método erase.
 Busca de um filme no catálogo: deve ser feita através do operador ()
sobrecarregado. A busca é realizada a partir do nome do filme passado por valor,
da seguinte maneira: catalogo(“nome”). A busca retorna um ponteiro para o
filme encontrado ou NULL, caso contrário.
 Edição de um filme no catálogo: deve ser feito através do operador (), sendo
que o nome do filme e o valor a ser utilizado na atualização são passados para o
operador. O nome é usado para a busca e, como tal, não pode ser alterado. A
operação de edição do nome de um filme deve ser realizada através da remoção e
inserção de um novo filme. Porém, caso a edição seja da produtora ou da nota,
estas podem ser feitas respectivamente com catalogo(“nome”,
“novaprodutora”) ou catalogo(“nome”, novanota). Um ponteiro para o
objeto que acabou de ser editado deve ser retornado ou NULL, caso este não
tenha sido encontrado.
 Impressão do catálogo inteiro de filmes e do filme na tela: devem ser
realizadas respectivamente com cout << catalago e cout << filme.
 Inicialização dos dados referentes a um filme: deve ser feito através de cin >>
filme.
 Busca pelo filme mais bem avaliado: deve ser feita através do operador < (ou
>), já sobrecarregado para a operação de inserção.
Observação 1: Crie um menu que permita a execução de todas as ações por intermédio
da interação com o usuário. É permitido igualmente que as opções sejam passadas para o
executável através de argc e argv.
Observação 2: Implemente persistência de dados dos filmes. Toda vez que um catálogo é
criado, este deve carregar todos os filmes já registrados e armazenados em um arquivo de
texto. Toda vez que o programa encerra, o arquivo de texto deve ser reescrito por
completo.



Observações do autor

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
