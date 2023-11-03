#define MAX_SIZE 3

// Imprime a tabela em cada inst�ncia da partida.
void show(char board[][MAX_SIZE]);

// Verificar se a posi��o no tabuleiro est� vazia.
int isEmpty(char board[][MAX_SIZE], char tecla);

// Preenche as marca��es no tabuleiro.
int fillBoard(char(*board)[3], char teclado, char marcador);

// Fun��o que retorna o resultado da partida.
int verificarVencedor(char board[][MAX_SIZE]);

void revezamento(int nmoves, int* vez, int* rodada);  //compromete-se a revesar quem come�a em cada partida.