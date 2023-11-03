#define MAX_SIZE 3

// Imprime a tabela em cada instância da partida.
void show(char board[][MAX_SIZE]);

// Verificar se a posição no tabuleiro está vazia.
int isEmpty(char board[][MAX_SIZE], char tecla);

// Preenche as marcações no tabuleiro.
int fillBoard(char(*board)[3], char teclado, char marcador);

// Função que retorna o resultado da partida.
int verificarVencedor(char board[][MAX_SIZE]);

void revezamento(int nmoves, int* vez, int* rodada);  //compromete-se a revesar quem começa em cada partida.