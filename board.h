#ifndef __BOARD_H__
#define __BOARD_H__

// definicoes que podem, ou nao, ser uteis:
#define SYMBOLS_J1 " abcdABCD"
#define SYMBOLS_J2 " wxyzWXYZ"
#define JOGADOR1 0
#define JOGADOR2 1
#define MIN_ROWS 3
#define MIN_COLS 4



// mensagem que deve ser apresentada qundo os parametros do main nao sao validos
// o programa apresenta a mensagem e termina
#define INVAL_PARAMS "ERRO: Parametros invalidos"

// mensagem apresentada sempre que o utilizador faz uma jogada ou comando invalido
#define INVAL_MOVE "Comando Invalido"

#define EXIT_MSG "Fim do jogo"
#define PL1_WINS "Jogador 1 Ganhou!"
#define PL2_WINS "Jogador 2 Ganhou!"
#define PL_DICE "Jogador lancou dados com valor "

// mensagem apresentada se a abertura do ficheiro falhar
#define FILE_ERR1 "Ficheiro nao encontrado \n"
// mensagem apresentada se a leitur do ficheiro falhar
#define FILE_ERR2 "Erro na leitura do ficheiro\n"

#define PL1_MOVE "------ Jogador 1 ------"
#define PL2_MOVE "------ Jogador 2 ------"


/** 
	Estado de um peao
   FALSE - Nao se encontra nesta casa do tabuleiro
   TRUE - Esta nesta casa do tabuleiro
   WIN - O peao ja deu um volta, e esta na casa mae 
*/
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
