#ifndef __BOARD_H__
#define __BOARD_H__

#define SYMBOLS_J1 " abcdABCD"
#define SYMBOLS_J2 " wxyzWXYZ"

#define JOGADOR1 0
#define JOGADOR2 1
#define PEAO1 0
#define PEAO2 1
#define PEAO3 2
#define PEAO4 3

#define DIM 128
#define MIN_ROWS 3
#define MIN_COLS 4
#define DICE_SIZE 6

#define INVAL_PARAMS "ERRO: Parametros invalidos"
#define INVAL_MOVE "Comando Invalido"

#define EXIT_MSG "Fim do jogo"
#define PL1_WINS "Jogador 1 Ganhou!"
#define PL2_WINS "Jogador 2 Ganhou!"
#define PL_DICE "Jogador lancou dados com valor "

#define FILE_ERR1 "Ficheiro nao encontrado \n"
#define FILE_ERR2 "Erro na leitura do ficheiro\n"

#define PL1_MOVE "------ Jogador 1 ------"
#define PL2_MOVE "------ Jogador 2 ------"

#define PRINTMOVE(P) P ? puts(PL2_MOVE) :  puts(PL1_MOVE)

/** 
	Estado de um peao
   FALSE - Nao se encontra nesta casa do tabuleiro
   TRUE - Esta nesta casa do tabuleiro
   WIN - O peao ja deu um volta, e esta na casa mae 
*/
typedef enum {FALSE = 0, TRUE = 1, WIN = 2} state;

/**
	Nomeia cada linha quando uma casa e desenhada
	o topo da casa é o HEADER, e o fundo da casa desenhada é o TAIL
*/
typedef enum {HEADER = 0, OCCUPANCY_1 = 1, SAFE_HOUSE = 2, OCCUPANCY_2 = 3, TAIL = 4} line_rendering;

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

/**
	Node de uma lista, que contem a casa de um tabuleiro
*/
typedef struct _node
{
	/* informação retida numa cada do tabuleiro */
	casa item;
	
	/* Ponteiro para a proxima "node", proxima casa do tabuleiro */
	struct _node * next;
} node;

/**
	Lista de "nodes", é uma lista de casas, e logo um tabuleiro
*/
typedef struct 
{
	/* Ponteiro para o primeiro "node" da lista, a primeira casa do tabuleiro */
	node * head;
	
	/* Ponteiro para o ultimo "node" da lista, a ultima casa do tabuleiro */
	node * tail;
	
	/* Numero de nodes ou numero de casas do tabuleiro */
	int length;
} list;

/**
	Obtem uma determinada casa do tabuleiro que está definido na lista 
	localizada pela sua posicao
	
	theBoard - Lista de casas do tabuleiro
	idx - Numero de posicao da casa
*/
casa * listCasaAt(list theBoard, int idx);

/**
	Imprime o conteudo dentro de uma casa do tabuleiro linha a linha
	Incluindo peoes presentes na casa e simbolo das casas seguras
	
	line - linha da casa a imprimir
	pos - Numero de posicao da casa a imprimir
	theBoard - Lista contendo o tabuleiro
*/
void printCasaLine(line_rendering line, int pos, list theBoard);

/**
	Simula o dado do jogo
	
	numberOfDices - Numero de dados a jogar
*/
int rolldice(int numberOfDices);

/**
	Imprime o tabuleiro no ecrã
	
	rows - Numero de linhas do tabuleiro
	cols - Numero de colunas do tabuleiro
	theBoard - Lista que contem as casas do tabuleiro
	modo - modo de apresentação do tabuleiro
*/
void boardPrint(const unsigned int rows, const unsigned int cols, list theBoard, const int modo);

#endif
