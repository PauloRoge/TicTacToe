#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <time.h> //para sortear números pseudoaleatórios.

#define MAX_SIZE 3

//PROTOTYPES
void info(); //imprime instruções iniciais.
void show(char board[][MAX_SIZE]); //imprime a tabela em cada instância da partida.
int fillBoard(char(*board)[3], char teclado, char marcador);  //atualiza as marcações no tabuleiro.
int verificarVencedor(char jogo[][3]); //função que retorna o resultado da partida.

int main()
{
    setlocale(LC_ALL, "portuguese");
    srand((unsigned int)time(NULL));

    char continuar; // armazena uma caracter que codifica uma condição de parar ou não parar.
    char tecla;
    int vez = rand() % 2;

    info();
    do
    {
        continuar = _getch();
    } while (continuar != 's' && continuar != 'n'); //garante que não haver entrada inválida.

    while (continuar == 's')
    {
        int draw = 0;
        char board[MAX_SIZE][MAX_SIZE]; //inicializa tabuleiro com (3x3) posições.
        
        for (int i = 0; i < MAX_SIZE; i++) //atribui um backspace em cada posição vazia.
            for (int j = 0; j < MAX_SIZE; j++)
                board[i][j] = ' ';
        do
        {
            system("cls");
            show(board);

            printf("vez de %s", vez == 0 ? "X" : "O");
            do
            {
                tecla = _getch();

            } while (tecla < 48 ||tecla > 57); //limitando o domínio entre 1 e 9, usando a tabela ASCII.

            vez = fillBoard(board, tecla, vez == 0 ? 'X' : 'O');
            draw++;

        } while (verificarVencedor(board) == ' ' && draw < 9);

        system("cls");
        show(board);
        if (draw == 9) printf("Draw");
        else
            printf("\n\n%s VENCEU!", verificarVencedor(board) == 'X' ? "X" : "O");
        
        printf("\n\n\tjogar novamente?\n\t(s)sim  (n)nao");
        do
        {
            continuar = _getch();
        } while (continuar != 's' && continuar != 'n'); //garante que não haja entrada inválida.
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
    if (marcador == 'X') //retorna a vez do próximo jogador.
        return 1;
    else
        return 0;
}

//functions
void info() {
    printf("\n\tTic-Tac-Toe\n\n\tComo jogar: \n\n");
    printf("\t     |     |     \n\t  7  |  8  |  9  \n\t_____|_____|_____");
    printf("\n\t     |     |     \t*use o teclado numerico para selecionar");
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

int verificarVencedor(char board[][3]) {
    // Verificar linhas
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
            return board[i][0];  // Retorna o jogador vencedor (x ou o)
        }
    }

    // Verificar colunas
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == board[1][j] && board[0][j] == board[2][j]) {
            return board[0][j];  // Retorna o jogador vencedor (x ou o)
        }
    }

    // Verificar diagonais
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
        return board[0][0];  // Retorna o jogador vencedor (x ou o)
    }
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
        return board[0][2];  // Retorna o jogador vencedor (x ou o)
    }

    return ' ';  // Retorna um espaço em branco se não houver vencedor ainda
}