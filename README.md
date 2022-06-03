**UNIVERSIDADE LUSÓFONA DE HUMANIDADES E TECNOLOGIAS**

* 2021/2022*

# Projeto Final - Não Te Constipes


# 1. Introdução

*Não Te Constipes* é um jogo de tabuleiro para dois jogadores, em que cada jogador tem uma família de 4 peões:
   - O jogador 1 é dono dos peões identificados pelas letras `a`, `b`, `c` e `d`.
   - O jogador 2 é dono dos peões identificados pelas letras `x`, `y`, `z` e `w`.

No início do jogo, os 4 peões de cada jogador estão na sua casa mãe, em lados opostos do tabuleiro. A cada jogada, o jogador lança os dados e escolhe só um dos seus peões para se movimentar. O peão escolhido, avança o número de casas que saiu no lançamento dos dados. 

O objetivo de cada jogador  é conseguir que todos os seus 4 peões completem uma volta ao tabuleiro. Ganha o primeiro jogador a alcançar esse feito.

No entanto, se um peão for ultrapassado por um peão da outra família (peão do jogador oponente), fica constipado e tem de voltar para a sua casa mãe.
O peão quando remetido à casa mãe deixa de ficar constipado e pode ser usado normalmente.

## 1.1 Instruções

Na resolução deste projeto deve ser utilizada a Linguagem de Programação C. Para além da correta implementação dos requisitos, tenha em conta os seguintes aspetos:
- O código apresentado deve estar *bem indentado*. 
- O código deve compilar sem erros ou *warnings* utilizando o *gcc* com as seguintes flags:
 `-Wall -Wextra -Wpedantic -Wvla`
- Tenha em atenção os nomes dados das variáveis, para que sejam indicadores daquilo que as mesmas vão conter.
- Evite o uso de constantes mágicas. 
- Evite duplicação de código. 
- Considere a implementação de funções para melhorar a legibilidade, evitar a duplicação e criar soluções mais genéricas.
- É proibida a utilização de variáveis globais - i.e. variáveis declaradas fora de qualquer função.
- É proibida a utilização da função `strtok()` e da instrução `goto`
- Este trabalho deverá ser realizado individualmente.

Para a realização deste projeto, os alunos deverão adquirir as seguintes competências:
- Manipulação de ficheiros
- Vetores e matrizes
- Strings
- Ciclos
- Condições
- Argumentos do main
- Estruturas
- Memória Dinâmica
- Listas ligadas


# Regras do jogo

O tabuleiro é construído quando o programa arranca. O tabuleiro tem sempre a forma retangular (ou quadrangular). O número de linhas e colunas pode ser passado pela linha de comandos (ver secção argumentos do main) ou então podem ser utilizados os valores por omissão:
   - número de linhas = 3
   - número de colunas = 7


.

Cada jogada começa com o lançamento de dois dados (ou seja pode sair um número entre 2 e 12). Após lançar os dados, o jogador indica qual o peão que pretende movimentar. O peão selecionado avança no tabuleiro no sentido dos ponteiros do relógio. Caso o peão passe por uma casa onde esteja um peão da família oposta, fará com que esse peão (o da família oposta) tenha de voltar à sua casa mãe. Esta situação chama-se deixar o peão constipado.

Se o número do dado garante que nessa jogada o peão dá uma volta ao tabuleiro, então:
- Este peão vai para a sua casa mãe;
- Este peão não pode ser mais jogado;
- Este peão fica representado na casa mãe com uma letra maiúscula.


## Exemplo

Ao iniciar o programa com os valores por omissão, é apresentado o seguinte tabuleiro:
```
+-- 1--++-- 2--++-- 3--++-- 4--++-- 5--++-- 6--++-- 7--+
|      ||      ||      ||      ||      ||      ||      |
|      ||      ||      ||      ||      ||      ||      |
|      ||      ||      ||      ||      ||      ||      |
+------++------++------++------++------++------++------+
+-- 0--+                                        +-- 8--+
| abcd |                                        |      |
| **** |                                        | **** |
|      |                                        | wxyz |
+------+                                        +------+
+--15--++--14--++--13--++--12--++--11--++--10--++-- 9--+
|      ||      ||      ||      ||      ||      ||      |
|      ||      ||      ||      ||      ||      ||      |
|      ||      ||      ||      ||      ||      ||      |
+------++------++------++------++------++------++------+
+------------------------------------+
|         Nao Te Constipes           |
+------------------------------------+
| <id do peao> (abcd, xyzw)          |
| s - sair                           |
| h - imprimir menu                  |
+------------------------------------+
------ Jogador 1 ------
Jogador lancou dados com valor 4
>
```
Uma vez que o jogador 1 é sempre o primeiro a jogar, os dados são lançados automaticamente, e o programa fica à espera que o jogador 1 decida qual o peão que quer movimentar. No seguinte exemplo, o jogador 1 vai escolher o peão 'a'.
```
>a
+-- 1--++-- 2--++-- 3--++-- 4--++-- 5--++-- 6--++-- 7--+
|      ||      ||      || a    ||      ||      ||      |
|      ||      ||      ||      ||      ||      ||      |
|      ||      ||      ||      ||      ||      ||      |
+------++------++------++------++------++------++------+
+-- 0--+                                        +-- 8--+
|  bcd |                                        |      |
| **** |                                        | **** |
|      |                                        | wxyz |
+------+                                        +------+
+--15--++--14--++--13--++--12--++--11--++--10--++-- 9--+
|      ||      ||      ||      ||      ||      ||      |
|      ||      ||      ||      ||      ||      ||      |
|      ||      ||      ||      ||      ||      ||      |
+------++------++------++------++------++------++------+
------ Jogador 2 ------
Jogador lancou dados com valor 9
>
```
De notar que o peão 'a', como consequência do dado ser 4, ficou na casa 4 do tabuleiro.
O programa ficou agora à espera que o jogador 2 escolha qual o peão que deseja movimentar.

Em qualquer momento, os jogadores podem decidir terminar o jogo, escolhendo a opção 's', ou imprimir o menu, escolhendo a opção 'h'.


# Ultrapassagens
No cenário seguinte é exemplificada uma situação de ultrapassagem que "constipa" os peões adversários.
Como já referido, "constipar" significa que os peões do oponente ultrapassado são enviados para a sua casa mãe.
Neste cenário a letra 'a' tem o dado com o valor 10. Na casa 9, ultrapassa o peão 'w' e para na casa 14 onde está o peão 'y'.
Ambos os peões 'w' e 'y' são considerados ultrapassados  e, por isso, agora aparecem na casa mãe.
Nota o detalhe:  um peão "constipa" peões oponentes que estejam na mesma casa.

```
+-- 1--++-- 2--++-- 3--++-- 4--++-- 5--++-- 6--++-- 7--+
|      ||      ||      || a    ||      ||      ||      |
|      ||      ||      ||      ||      ||      ||      |
|      ||      ||      ||      ||      ||      ||      |
+------++------++------++------++------++------++------+
+-- 0--+                                        +-- 8--+
|  bcd |                                        |      |
| **** |                                        | **** |
|      |                                        |  x z |
+------+                                        +------+
+--15--++--14--++--13--++--12--++--11--++--10--++-- 9--+
|      ||      ||      ||      ||      ||      ||      |
|      ||      ||      ||      ||      ||      ||      |
|      ||   y  ||      ||      ||      ||      || w    |
+------++------++------++------++------++------++------+
------ Jogador 1 ------
Jogador lancou dados com valor 10
> a
+-- 1--++-- 2--++-- 3--++-- 4--++-- 5--++-- 6--++-- 7--+
|      ||      ||      ||      ||      ||      ||      |
|      ||      ||      ||      ||      ||      ||      |
|      ||      ||      ||      ||      ||      ||      |
+------++------++------++------++------++------++------+
+-- 0--+                                        +-- 8--+
|  bcd |                                        |      |
| **** |                                        | **** |
|      |                                        | wxyz |
+------+                                        +------+
+--15--++--14--++--13--++--12--++--11--++--10--++-- 9--+
|      || a    ||      ||      ||      ||      ||      |
|      ||      ||      ||      ||      ||      ||      |
|      ||      ||      ||      ||      ||      ||      |
+------++------++------++------++------++------++------+

```

# Casas seguras

No início do jogo é possível configurar no tabuleiro casas denominadas seguras.
Quando um peão se encontra numa casa segura, nunca se constipa e se é ultrapassado pelo oponente mantém-se na casa presente, e não regressa à casa mãe.
No cenário em baixo, são configuradas as casas 5 e 9 como seguras (ficam marcadas com ****). Quando o peão é jogado com o valor 10, só consegue "constipar" o peão 'y', porque o peão w está na casa segura 9.

```
+-- 1--++-- 2--++-- 3--++-- 4--++-- 5--++-- 6--++-- 7--+
|      ||      ||      || a    ||      ||      ||      |
|      ||      ||      ||      || **** ||      ||      |
|      ||      ||      ||      ||      ||      ||      |
+------++------++------++------++------++------++------+
+-- 0--+                                        +-- 8--+
|  bcd |                                        |      |
| **** |                                        | **** |
|      |                                        |  x z |
+------+                                        +------+
+--15--++--14--++--13--++--12--++--11--++--10--++-- 9--+
|      ||      ||      ||      ||      ||      ||      |
|      ||      ||      ||      ||      ||      || **** |
|      ||   y  ||      ||      ||      ||      || w    |
+------++------++------++------++------++------++------+
------ Jogador 1 ------
Jogador lancou dados com valor 10
> a
+-- 1--++-- 2--++-- 3--++-- 4--++-- 5--++-- 6--++-- 7--+
|      ||      ||      ||      ||      ||      ||      |
|      ||      ||      ||      || **** ||      ||      |
|      ||      ||      ||      ||      ||      ||      |
+------++------++------++------++------++------++------+
+-- 0--+                                        +-- 8--+
|  bcd |                                        |      |
| **** |                                        | **** |
|      |                                        | wxyz |
+------+                                        +------+
+--15--++--14--++--13--++--12--++--11--++--10--++-- 9--+
|      || a    ||      ||      ||      ||      ||      |
|      ||      ||      ||      ||      ||      || **** |
|      ||      ||      ||      ||      ||      || w    |
+------++------++------++------++------++------++------+

```
# Implementação

## Tabuleiro
Para a construção do tabuleiro usa-se uma lista ligada, sendo definida com a seguinte estrutura principal:
```
typedef struct 
{
	node * head;
	node * tail;
	int length;
} list;
```

A estrutura define uma lista de elementos do tipo *node*, onde um “node” é a seguinte estrutura:

```
typedef struct _node
{
	casa item;
	struct _node * next;
} node;
```

Cada node corresponde a uma casa do tabuleiro. Assim, um tabuleiro é uma lista (de) nodes onde cada node contém uma casa.
A estrutura `casa` indica quais os peões que lá estão e se é ou não uma casa segura. A seguinte estrutura define o tipo `casa`.

```
/**
	Casa de um tabuleiro
*/
typedef struct
{
	/** jogador 1 e 2 e seus peoes 1 a 4 presentes TRUE ou nao FALSE */
	state jogador_peao[2][4];
	
	/** Indica se a casa é segura e nao podem comer os peoes */
	state casaSegura;
} casa;
```
O campo jogador_peao é uma matriz que representa todos os peões do jogo.
A matriz é composta por duas linhas que são o jogador 1 e jogador 2;
 A matriz é composta por 4 colunas que são os peões a,b,c e d do jogador 1 e w, x, y e z do jogador 2.
 O tipo da matriz, `state`, deve ser definido da seguinte forma:
O campo jogador_peao é uma matriz que representa todos os peões do jogo.
´´´
typedef enum {FALSE = 0, TRUE = 1, WIN = 2} state;
´´´

Os valores possíveis são:
 - FALSE – O peão não está presente nesta casa
 - TRUE – O peão está presente nesta casa
 - WIN – O peão está desativado, porque já deu a volta ao tabuleiro e ganhou.


## Dados (números aleatórios)
O lançamento dos dados deve ser feito usando a função fornecida:

```int rolldice(int numberOfDices);```

Esta função recebe o número de dados - que no caso deste jogo é sempre 2 - e devolve o número resultante da soma dos dois dados. 
A função está declarada na biblioteca fornecida `board.h`.

Esta função deve ser chamada no início de cada jogada e só pode ser chamada uma vez (por cada jogada). É imperativo que respeitem esta regra, pois caso não o façam, os números gerados não vão corresponder aos números gerados pelo Pandora. Para esse fim, é também necessário inicializar a `seed` do gerador de números aleatórios. Para garantir repetibilidade, a seed deve ser inicializada com o valor `1`. Ou seja, após a declaração de variáveis, a função `main` deve incluir a seguinte invocação:

```
srand(1); // initialize seed
```




## Argumentos do main
Ao lançar a aplicação esta pode aceitar 4 argumentos.
Os argumentos são três números e um nome dum ficheiro.
 Por exemplo:
```
main.exe 0 5 9 configuracao.txt
```
* O primeiro número indica o modo de apresentação do tabuleiro - neste caso 0, é o modo por defeito. Em alternativa, o valor 1 fará com que o tabuleiro seja impresso em modo simples, apenas mostrando o número das casas e os peões.
* O segundo número indica o número de linhas do tabuleiro (neste exemplo é 5)
* O terceiro número indica o número de colunas do tabuleiro (neste exemplo é 9)
* O quarto é um campo com um nome dum ficheiro com informação das casas seguras (neste exemplo configuração.txt)

O ficheiro contém uma lista de números, cada número identifica uma casa segura.

Os argumentos são opcionais e o utilizador pode passar as seguintes combinações de argumentos:
- Não passar argumentos - deverão ser utilizados os valores por omissão;
- Passar apenas o modo de apresentação do tabuleiro;
- Passar o modo de apresentação do tabuleiro, e o número de linhas;
- Passar o modo de apresentação do tabuleiro, o número de linhas e o número de colunas;
- Passar todos os argumentos.

## Leitura do ficheiro (Casas Seguras)

O ficheiro é uma lista de números, onde cada número indica uma casa segura do tabuleiro.
Se o ficheiro quiser indicar que as casas seguras são 2, 7 e 12. O conteúdo do ficheiro deve ser o seguinte:
```
2
7
12
```
## Inclusão e compilação das funções fornecidas

É fornecida uma biblioteca `board.h` e correspondente `board.o` que deve ser incluída e utilizada. Esta biblioteca fornece duas funções:
- `int rolldice (int numberOfDices);`
- `void boardPrint(const unsigned int rows, const unsigned int cols, list l, int mode);`

A função `boardPrint` imprime o tabuleiro no terminal. A função recebe como parâmetros:
- os números de linhas do tabuleiro;
- os números de colunas do tabuleiro;
- a lista ligada com a informação das casas;
- o modo de impressão que pode apenas tomar os valores;
   - 0 - imprime o tabuleiro normalmente
   - 1 - imprime apenas as posições dos peões sem mostrar o tabuleiro completo.


Para que esta função funcione corretamente, é necessário que a lista cumpra os seguintes requisitos:
- O campo `head` aponta para a casa 0.
- O campo `tail` aponta para a última casa do tabuleiro.
- O campo `length` está atualizado corretamente com o número de casas do tabuleiro.

A função assume que a lista é uma lista de nodes definidos pela estrutura acima. No entanto, os alunos são livres de modificar a estrutura, adicionando campos novos, desde que mantenham os nomes dos campos que estão na estrutura sugerida.

Para utilizarem esta biblioteca é necessário fazer o include do .h nos locais onde chamam as funções fornecidas, isto é, `#include "board.h"`. Para compilar o código incluindo a biblioteca, é necessário linkar com o ficheiro board.c. É fornecido um ficheiro Makefile que facilita o processo. Para compilar usando o makefile, basta executar o comando `make` no terminal.
 
## Mensagens de erro e códigos de saída
Todas as mensagens que devem ser apresentadas no programa são fornecidas no ficheiro board.h .
O board.h também inclui a estruturas de dados mencionadas na secção tabuleiro.

De notar que a  mensagem, "Jogador lançou dados com valor " necessita à frente a impressão do número do dado.
Por exemplo:
*Jogador lancou dados com valor 10*

# Exemplo de utilização

No cenário seguinte é apresentado uma situação em que a jogada final resulta na vitória do jogador 2.
```
+-- 1--++-- 2--++-- 3--++-- 4--++-- 5--++-- 6--++-- 7--+
|      ||      ||      || a    ||      ||      ||      |
|      ||      ||      ||      || **** ||      ||      |
|      ||      ||      ||      ||      ||      ||      |
+------++------++------++------++------++------++------+
+-- 0--+                                        +-- 8--+
|  BCD |                                        |      |
| **** |                                        | **** |
|      |                                        | WX Z |
+------+                                        +------+
+--15--++--14--++--13--++--12--++--11--++--10--++-- 9--+
|      ||      ||      ||      ||      ||      ||      |
|      ||      ||      ||      ||      ||      || **** |
|      ||   y  ||      ||      ||      ||      ||      |
+------++------++------++------++------++------++------+
------ Jogador 2 ------
Jogador lancou dados com valor 11
> y
+-- 1--++-- 2--++-- 3--++-- 4--++-- 5--++-- 6--++-- 7--+
|      ||      ||      || a    ||      ||      ||      |
|      ||      ||      ||      || **** ||      ||      |
|      ||      ||      ||      ||      ||      ||      |
+------++------++------++------++------++------++------+
+-- 0--+                                        +-- 8--+
|  BCD |                                        |      |
| **** |                                        | **** |
|      |                                        | WXYZ 
+------+                                        +------+
+--15--++--14--++--13--++--12--++--11--++--10--++-- 9--+
|      ||      ||      ||      ||      ||      ||      |
|      ||      ||      ||      ||      ||      || **** |
|      ||      ||      ||      ||      ||      ||      |
+------++------++------++------++------++------++------+
Jogador 2 Ganhou!
```
Nesta situação ao jogador 1, falta só o peão 'a' dar a volta ao tabuleiro, logo peões 'b', 'c', 'd' já deram a volta e por isso são representados na casa mãe com a letra maiúscula.
De forma similar o jogador 2, falta só o peão 'y' dar a volta ao tabuleiro, logo os peões 'w', 'x', 'z' já deram a volta e por isso são representados na casa mãe com a letra maiúscula.
Ao calhar o valor 11, o jogador 2 avança com o peão 'y' onze casas para a frente e ganha o jogo. Daí que na casa mãe todos os peões têm   letras maiúsculas.
De notar que ‘y’ está na casa 14, logo a 10 casas da casa mãe, se o valor do dados é superior a distância, neste o dado é 11 e superior a 10, o peão cai sempre na casa mãe e cumpriu a volta ao tabuleiro.  

 
# Material a entregar

* Ficheiro `.c` com código devidamente comentado e indentado:
    - Deve implementar as funcionalidades pedidas;
    - O código deverá ser submetido na plataforma PANDORA [(2)](#ref2);
    - A plataforma corre automaticamente uma série de testes e no fim atribui uma classificação. **indicativa**. Os alunos deverão analisar o relatório emitido pela plataforma e poderão alterar o código e voltar a submeter o trabalho. Neste trabalho haverá limite de submissões.
      A plataforma não permite a entrega de trabalhos após a data e hora limite.
    - Incorreta indentação do código poderá originar penalizações na nota.

# Datas 

O código deverá ser submetido na plataforma PANDORA [(2)](#ref2) até às **23:59 do dia 24 de Junho de 2022** no *contest* **LP12022PF**.



## 7. Peso na avaliação

O projeto final vale 20% da nota final e será cotado de 0 a 20 valores.

O projeto de recurso e de época especial valem 50% da nota final e será cotado de 0 a 20 valores.
 
A nota indicada pelo pandora é apenas indicativa. O código será posteriormente comparado e avaliado pelos docentes.

Após a entrega do projeto será realizada uma defesa do projeto onde cada elemento do grupo terá de efetuar alterações ao código. Se o aluno não conseguir efetuar as alterações pedidas ao seu código será aplicada uma penalização sobre a nota do projeto que poderá variar entre 10% a 100%.
 
Este projeto tem nota mínima.

## 8. Honestidade académica

Nesta disciplina, espera-se que cada aluno siga os mais altos padrões de honestidade académica. Trabalhos que sejam identificados como cópias serão anulados e os alunos envolvidos terão nota zero - quer tenham copiado, quer tenham deixado copiar.
Para evitar situações deste género, recomendamos aos alunos que nunca partilhem ou mostrem o seu código.
A decisão sobre se um trabalho é uma cópia cabe exclusivamente aos docentes da unidade curricular.
Os alunos são encorajados a discutir os problemas com outros alunos mas não deverão, no entanto, copiar códigos, documentação e relatórios de outros alunos. Em nenhuma circunstância deverão partilhar os seus próprios códigos, documentação e relatórios. De facto, não devem sequer deixar códigos, documentação e relatórios em computadores de uso partilhado.

## Referências

<a name="ref1"></a>

* (1) Pereira, A. (2017). C e Algoritmos, 2ª edição. Sílabo.

<a name="ref2"></a>

* (2)  PANDORA - Yet Another Automated Assessment Tool, https://saturn.ulusofona.pt/.

<a name="ref3"></a>

* (3)  Lusófona Moodle, https://secure.grupolusofona.pt/ulht/moodle/

## Metadados

* Autor: [Pedro Serra]
* Curso:  [Licenciatura em Videojogos]
* Instituição: [Universidade Lusófona de Humanidades e Tecnologias][ULHT]
