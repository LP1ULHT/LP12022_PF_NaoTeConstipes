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

#define INVAL_PARAMS "ERRO: Parametros invalidos"
#define INVAL_MOVE "Comando Invalido"

#define INVAL_INPUT1 "Caracter invalido, opoes validas sao 's' ou 'h'"
#define INVAL_INPUT2 "Jogada invalida, faça nova jogada"
#define INVAL_INPUT3 "Peao escolhido invalido"
#define INVAL_INPUT4 "Peao escolhido ja terminou percurso"

#define EXIT_MSG "Fim do jogo"
#define PL1_WINS "Jogador 1 Ganhou!"
#define PL2_WINS "Jogador 2 Ganhou!"
#define PL_DICE "Jogador lancou dados com valor "

#define FILE_ERR1 "Ficheiro nao encontrado \n"
#define FILE_ERR2 "Erro na leitura do ficheiro\n"
#define FILE_ERR3 "Casa segura adicionada \n"

#define ASSERT_ERR1 "Valor de colunas e linhas tem de ser par"

#define PL1_MOVE "------ Jogador 1 ------"
#define PL2_MOVE "------ Jogador 2 ------"

#define PRINTMOVE(P) P ? puts(PL2_MOVE) :  puts(PL1_MOVE)

typedef enum {FALSE = 0, TRUE = 1, WIN = 2} state;

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


typedef struct _node
{
	casa item;
	struct _node * next;
} node;

typedef struct 
{
	node * head;
	node * tail;
	int length;
} list;


int rolldice(int numberOfDices);


void boardPrint(const unsigned int rows, const unsigned int cols, list l, int modo);


#endif
