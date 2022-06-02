#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "board.h"

/**
	Simula o dado do jogo
	
	numberOfDices - Numero de dados a jogar
*/
int rolldice(int numberOfDices)
{
	int i, sum;

	for (i = sum = 0 ; i < numberOfDices ; i++)
	{
		sum += rand() % DICE_SIZE + 1;
	}

	return sum;
}

/**
	Imprime o tabuleiro no ecrã
	
	rows - Numero de linhas do tabuleiro
	cols - Numero de colunas do tabuleiro
	theBoard - Lista que contem as casas do tabuleiro
	modo - imprime a posicao dos peoes se for 1, nao imprime se for 0
*/
void boardPrint(const unsigned int rows, const unsigned int cols, list theBoard)
{
	unsigned int i, k, pos, right_pos, left_pos, pos_l, pos_r;
	line_rendering line;

	const int Ncasas = 2*(cols+rows-2);

	assert(rows >= MIN_ROWS && rows % 2 && "Tabuleiro tem de ter no minimo 3 linhas e impar");
	assert(cols > MIN_COLS && "Numero colunas do tabuleiro tem de ser superior a 4");
	assert(theBoard.length == Ncasas && "Falha na construcao do tabuleiro, demasiado grande");
	assert(theBoard.head != NULL && "Falha na construcao do tabuleiro");

	/* print first line */
	/* first line starts in position floor(rows/2) */
	for (line = HEADER ; line <= TAIL ; line++)
	{
		pos = rows/2;
		for (i = 0 ; i < cols ; i++, pos++)
			printCasaLine(line, pos, theBoard);
		putchar('\n');
	}

	/* print intermediate top lines down to middle line inclusive */
	left_pos = rows/2 - 1;
	right_pos = pos;
	for (i = 0 ; i < rows/2 ; i++, left_pos--, right_pos++)
	{
		for (line = HEADER ; line <= TAIL ; line++)
		{
			pos_l = left_pos;
			pos_r = right_pos;
			for (k = 0 ; k < cols ; k++)
			{
				if (k == 0)
					printCasaLine(line, pos_l, theBoard);
				else if (k == cols-1)
					printCasaLine(line, pos_r, theBoard);
				else
					printf("        ");
			}
			putchar('\n');
		}
	}

	/* print bottom intermediate lines */
	left_pos = Ncasas-1;
	for (i = 0 ; i < rows/2-1 ; i++, left_pos--, right_pos++)
	{		
		for (line = HEADER ; line <= TAIL ; line++)
		{
			pos_l = left_pos;
			pos_r = right_pos;			
			for (k = 0 ; k < cols ; k++)
			{
				if (k == 0)
					printCasaLine(line, pos_l, theBoard);
				else if (k == cols-1)
					printCasaLine(line, pos_r, theBoard);
				else
					printf("        ");				
			}
			putchar('\n');
		}
	}
	
	/* print bottom line */
	for (line = HEADER ; line <= TAIL ; line++)
	{
		pos = left_pos;
		for (i = 0 ; i < cols ; i++, pos--)
			printCasaLine(line, pos, theBoard);
		putchar('\n');
	}
	fflush(stdout);
}

/**
	Obtem uma determinada casa do tabuleiro que está definido na lista 
	localizada pela sua posicao
	
	l - Lista de casas do tabuleiro
	idx - Numero de posicao da casa
*/
casa * listCasaAt(list theBoard, int idx)
{
	/* ponteiro para um node da lista */
	node *t;
	
	/* iterador do ciclo for */
	int i;

	for (t = theBoard.head, i = 0 ; t != NULL && i < idx ; t = t-> next, i++)
		;

	return t != NULL ? &(t -> item) : NULL;
}

/**
	Imprime o conteudo dentro de uma casa do tabuleiro linha a linha
	Incluindo peoes presentes na casa e simbolo das casas seguras
	
	line - linha da casa a imprimir
	pos - Numero de posicao da casa a imprimir
	theBoard - Lista contendo o tabuleiro
*/
void printCasaLine(line_rendering line, int pos, list theBoard)
{
	/* Valor temporario da casa do tabuleiro que esta a ser processada */
	casa *it;

	switch(line)
	{
		case HEADER: /* imprime numero da casa na linha 0 */
			printf("+--%2d--+", pos);
			break;
		case OCCUPANCY_1: /* imprime peoes do jogador 1 presentes, na linha 1 */
			it = listCasaAt(theBoard, pos);
			assert(it != NULL);
			printf("| %c%c%c%c |", 
				it->jogador_peao[JOGADOR1][PEAO1] ? 
					(it->jogador_peao[JOGADOR1][PEAO1] == WIN ? 
						SYMBOLS_J1[5]:
						SYMBOLS_J1[1]):
					SYMBOLS_J1[0],
				it->jogador_peao[JOGADOR1][PEAO2] ?
					(it->jogador_peao[JOGADOR1][PEAO2] == WIN ?
						SYMBOLS_J1[6]:
						SYMBOLS_J1[2]):
					SYMBOLS_J1[0],
				it->jogador_peao[JOGADOR1][PEAO3] ?
					(it->jogador_peao[JOGADOR1][PEAO3] == WIN ?
						SYMBOLS_J1[7]:
						SYMBOLS_J1[3]):
					SYMBOLS_J1[0],
				it->jogador_peao[JOGADOR1][PEAO4] ?
					(it->jogador_peao[JOGADOR1][PEAO4] == WIN ?
						SYMBOLS_J1[8]:
						SYMBOLS_J1[4]):
					SYMBOLS_J1[0]);
			break;
		case SAFE_HOUSE: /* imprime se casa e segura, na linha 2 */
			it = listCasaAt(theBoard, pos);
			assert(it != NULL);
			if (it->casaSegura)
				printf("| **** |");
			else
				printf("|      |");
			break;
		case OCCUPANCY_2: /* imprime peoes do jogador 2 presentes, na linha 3 */
			it = listCasaAt(theBoard, pos);
			assert(it != NULL);
			printf("| %c%c%c%c |", 
				it->jogador_peao[JOGADOR2][PEAO1] ?
					(it->jogador_peao[JOGADOR2][PEAO1] == WIN ?
						SYMBOLS_J2[5]:
						SYMBOLS_J2[1]):
					SYMBOLS_J2[0],
				it->jogador_peao[JOGADOR2][PEAO2] ?
					(it->jogador_peao[JOGADOR2][PEAO2] == WIN ?
						SYMBOLS_J2[6]:
						SYMBOLS_J2[2]):
					SYMBOLS_J2[0],
				it->jogador_peao[JOGADOR2][PEAO3] ?
					(it->jogador_peao[JOGADOR2][PEAO3] == WIN ?
						SYMBOLS_J2[7]:
						SYMBOLS_J2[3]):
					SYMBOLS_J2[0],
				it->jogador_peao[JOGADOR2][PEAO4] ?
					(it->jogador_peao[JOGADOR2][PEAO4] == WIN ?
						SYMBOLS_J2[8]:
						SYMBOLS_J2[4]):
					SYMBOLS_J2[0]);
			break;
		case TAIL:
			printf("+------+");
	}
}
