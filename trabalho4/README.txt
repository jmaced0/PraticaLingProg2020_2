Enunciado

Escreva um programa que implemente uma classe Cadastro para gerenciamento de pacientes hospitalares. A classe Cadastro reproduz parte das operações existentes na classe Agenda, como implementada na lista de exercícios do laboratório atual, o Laboratório 9. Porém, ao invés de utilizar uma estrutura vector para armazenamento, a
classe Cadastro utiliza uma estrutura do tipo árvore binária, implementada como uma classe template, como em “template <class T> class Arvore”. A classe Cadastro deve oferecer as seguintes operações:
• Inserção: A inserção é realizada através do método insere que emprega o operador +=, como em “arvore += paciente”, implementado na classe template Arvore. Cada elemento inserido deve ser armazenado na árvore privada. Para isso, o elemento é posicionado à esquerda do nó raiz atual da árvore, caso o nome do paciente seja maior em ordem alfabética que o do nó raiz. Caso o nome seja menor em ordem alfabética, este deve ser posicionado à direita do nó raiz atual. Este procedimento pode ser realizado de forma recursiva. A figura abaixo ilustra a inserção do caractere “i” na árvore binária de caracteres. Note que a primeira comparação foi entre a raiz atual “g” e o “i”. A comparação demonstrou que o caractere “i” é maior em ordem alfabética que o “g” e, como tal, deve ser posicionado à esquerda de “g”. Em seguida, a mesma comparação é realizada com o “m”, raiz atual da sub-árvore à esquerda, onde se conclui que “i” é menor que “m”. Portanto, o caractere “i” deve ser posicionado à direita do “m”. Como não há mais nenhuma sub-árvore à direita do “m”, o caractere “i” é finalmente inserido. Não há preocupações em manter a árvore balanceada.
A inserção deve retornar um ponteiro para o nó inserido ou NULL caso a operação de inserção falhe. Uma falha ocorre caso um paciente com o mesmo nome já exista no cadastro.
• Busca: A busca deve ser realizada através do método busca que utiliza o operador (), como em “arvore(“nome”)”. A busca retorna um ponteiro para o elemento encontrado ou NULL, caso contrário. A busca é realizada a partir do nome do paciente, uma vez que não é permitido inserir dois pacientes com o mesmo nome.
• Impressão: A impressão de todos os elementos da árvore pode ser obtida através de método imprime. Todos os pacientes da árvore e seus atributos, por sua vez, devem ser impressos a partir do operador <<, como em “cout << arvore”. Para ajudar, é interessante implementar também o operador << sobrecarregado para objetos da classe Paciente, como em “cout << paciente”.
Note que, tanto a operação de inserção quanto a de busca podem retornar NULL. Trate esses casos como uma exceção na função principal. Caso essas exceções ocorram, o programa deve imprimir uma mensagem específica usando o método what() da classe exception.
Ainda, assim como na lista de exercícios realizada, o cadastro deve ser capaz de ser utilizado para armazenamento de pacientes diversos, com diferentes tipos de atributos privados específicos. Dessa forma, o cadastro tem que ser genérico o suficiente para ser utilizado para qualquer tipo de paciente. Crie, portanto, uma classe Paciente base e classes derivadas específicas. Utilize o conceito de polimorfismo.


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

