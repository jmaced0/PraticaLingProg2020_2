Enunciado:

O programa deverá apresentar dados referentes ao avanço da COVID-19 no Brasil e nos
estados individualmente. Para isso, um menu contendo as seguintes opções deve ser
disponibilizado:
1. Exibição da evolução do número de óbitos no Brasil, e nos estados
individualmente, usando a estratégia de média móvel dos últimos N dias. A média
móvel deverá ser calculada ao menos para os últimos três dias, ou seja, média
móvel do número de óbitos como calculada no dia atual, no dia anterior e no dia
anterior ao anterior. Assumir que o programa tem acesso a dados referentes ao
número de óbitos diários por estado por um intervalo maior que N + 2 e que N é
minimamente igual a 7;
2. Exibição de forma agrupada dos estados em alta, estabilidade e baixa segundo a
média móvel do dia atual, como calculada no item 1 (arbitrar limiares de definição,
por exemplo, estados acima de 15% são considerados em alta, abaixo de -15% em
baixa e, caso contrário, estabilidade);
3. Repetir a mesmo dado do item 2, se em alta, baixa ou estabilidade, para o Brasil;
4. Exibição do estado com maior alta e maior baixa segundo a média móvel do dia
atual calculada no item 1;
5. Exibir os dados acumulados de número de óbitos (soma desde o início do período
de observação) no Brasil e nos estados individualmente.
O programa deve prever a implementação de uma classe Nacional e Estadual, na qual
a classe Nacional é composta por M objetos da classe Estadual. Cada objeto da classe
Estadual deve representar um estado brasileiro e, como tal, deve gerenciar os seus
dados individuais. Note que os dados da série histórica podem ser arbitrários, ou seja, não
necessariamente precisam representar a realidade. Os dados da série podem ser
inicializados junto com os objetos de cada estado, sem necessidade de inserção ou
remoção de dados diários através de opção do menu.
Dica: Verifique a possibilidade do uso da classe vector para armazenamento dos objetos
da classe Estadual e para armazenamento dos dados da série histórica pelos estados.

Observações do autor:

Obs.: O código foi desenvolvido e testado no Linux, distribuição Ubuntu 20.04. Os dados de cada estado são gerados aleatoriamente a cada execução do programa com possíveis valores entre 0 e 200. 

1.Compilação do programa

	O programa é compilado por meio do comando "make", onde primeiramente os objetos de cada arquivo são criados e posteriomente ocorre a linkedição. Após o processo de compilação, o arquivo executável "programa" e os objetos são criados, esses arquivos podem ser removidos por meio do comando "make clean".

2.Utilização do programa

	Após executar o executável "programa", sem argumentos, um MENU com contendo as opções requisitadas é disponibilizado na tela. Para acessar uma das opções basta digitar o número referente a ela que está no início da linha e posteriormente pressionar ENTER. 
	Logo que o programa executa a tarefa de determinada opcao do MENU, todas a opções são novamente impressas na tela para que uma nova opção seja escolhida. Para sair do programa deve-se digitir "-1" e pressionar ENTER
