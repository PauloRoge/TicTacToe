#include <stdio.h>  //Entrada e saída padrão.
#include <stdlib.h> //Para função rand e system.
#include <conio.h>  //Para usar a função _getch.
#include <time.h>   //Para sortear números pseudoaleatórios.

#define MAX_SIZE 3

//PROTOTYPES

//Imprime instruções iniciais.
void info(); 

//Imprime a tabela em cada instância da partida.
void show(char board[][MAX_SIZE]); 

//Verifica se a posição no tabuleiro está vazia.
int isEmpty(char board[][MAX_SIZE],char tecla);

//Preenche as marcações no tabuleiro.
int fillBoard(char(*board)[3], char teclado, char marcador);  

//Função que retorna o resultado da partida.
int verificarVencedor(char board[][MAX_SIZE]); 

int main()
{
    srand((unsigned int)time(NULL));

    char continuar; //Armazena um caracter que será codificado como condição de continuar ou não.
    char tecla; //armazena um caracter de 1 a 9, que será refente à um campo do tabuleiro.
    int vez = rand() % 2; //É sorteado o player que começa, apenas na primeira partida.

    info(); //imprime na tela informações iniciais.
    do
    {
        continuar = _getch();
    } while (continuar != 's' && continuar != 'n'); //Garante não haver entrada inválida.

    while (continuar == 's')
    {
        int draw = 0;
        char board[MAX_SIZE][MAX_SIZE]; //Inicializa tabuleiro com (3x3) posições.
        
        for (int i = 0; i < MAX_SIZE; i++) //Atribui um backspace em cada posição.
            for (int j = 0; j < MAX_SIZE; j++)
                board[i][j] = ' ';
        do
        {
            system("cls");
            show(board);

            printf("\n\n\n\n\n\n\n\nvez: (%s)",vez == 0 ? "X" : "O");
            do
            {
                tecla = _getch();

            } while (tecla < '1' ||tecla > '9' || !isEmpty(board,tecla)); //Limitando o domínio entre 1 e 9, a partir da tabela ASCII.

            vez = fillBoard(board, tecla, vez == 0 ? 'X' : 'O');
            draw++;

        } while (verificarVencedor(board) == ' ' && draw < 9);

        system("cls");
        show(board);

        if (draw == 9 && verificarVencedor(board) == ' ') printf("Draw");
        else
            printf("\n\n%s VENCEU!", verificarVencedor(board) == 'X' ? "X" : "O");
        printf("\n\n\tjogar novamente?\n\t(s)sim  (n)nao");

        do
        {
            continuar = _getch();
        } while (continuar != 's' && continuar != 'n'); //Garante que não haja entrada inválida.
    }

    return 0;
}

//FUNCTIONS
int isEmpty(char board[][MAX_SIZE], char tecla) {
    switch (tecla)
    {
    case '1':
        return board[2][2] == ' '; // Compara e retorna verdadeiro (1) se a posição estiver vazia.
    case '2':
        return board[2][1] == ' '; 
    case '3':
        return board[2][0] == ' ';
    case '4':
        return board[1][2] == ' ';
    case '5':
        return board[1][1] == ' ';
    case '6':
        return board[1][0] == ' ';
    case '7':
        return board[0][2] == ' ';
    case '8':
        return board[0][1] == ' ';
    case '9':
        return board[0][0] == ' ';
    default:
        return 0; // Retorna falso (0) se a posição não for válida.
    }
}

int fillBoard(char(*board)[3], char teclado, char marcador)
{
    switch (teclado)
    {
    case '1':
        board[2][2] = marcador;
        break;

    case '2':
        board[2][1] = marcador;
        break;

    case '3':
        board[2][0] = marcador;
        break;

    case '4':
        board[1][2] = marcador;
        break;

    case '5':
        board[1][1] = marcador;
        break;

    case '6':
        board[1][0] = marcador;
        break;

    case '7':
        board[0][2] = marcador;
        break;

    case '8':
        board[0][1] = marcador;
        break;

    case '9':
        board[0][0] = marcador;
        break;

    default:
        break;
    }

    return (marcador == 'X') ? 1 : 0; //Retorna a vez do próximo jogador.
}

int verificarVencedor(char board[][MAX_SIZE]) {
    // Verificar linhas
    for (int i = 0; i < 3; i++)
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != ' ') 
            return board[i][0];  // Retorna o jogador vencedor (X ou O)

    // Verificar colunas
    for (int j = 0; j < 3; j++)
        if (board[0][j] == board[1][j] && board[0][j] == board[2][j] && board[0][j] != ' ')
            return board[0][j];  // Retorna o jogador vencedor (X ou O)

    // Verificar diagonais
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != ' ')
        return board[0][0];  // Retorna o jogador vencedor (X ou O)

    if (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != ' ')
        return board[0][2];  // Retorna o jogador vencedor (X ou O)

    return ' ';  // Retorna um espaço em branco se não houver vencedor ainda
}
void info() {
    printf("\n\n\tDica: \n\n");
    printf("\t     |     |     \n\t  7  |  8  |  9  \n\t_____|_____|_____");
    printf("\n\t     |     |     \t*use o teclado numerico.");
    printf("\n\t  4  |  5  |  6  \t\n\t_____|_____|__");
    printf("___\n\t     |     |     \n\t  1  |  2  |  3  \n\t     |     |");
    printf("     \n\n\tJogar? (s)sim (n)nao");
}

void show(char board[][MAX_SIZE]) {
    printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t     |     |     \n");
    printf("\t\t\t\t\t\t  %c  |  %c  |  %c  \n", board[0][2], board[0][1], board[0][0]);
    printf("\t\t\t\t\t\t_____|_____|_____\n\t\t\t\t\t\t     |     |     \n");
    printf("\t\t\t\t\t\t  %c  |  %c  |  %c  \n", board[1][2], board[1][1], board[1][0]);
    printf("\t\t\t\t\t\t_____|_____|_____\n\t\t\t\t\t\t     |     |     \n");
    printf("\t\t\t\t\t\t  %c  |  %c  |  %c  \n", board[2][2], board[2][1], board[2][0]);
    printf("\t\t\t\t\t\t     |     |     \n");
}
