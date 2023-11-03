#include <iostream> //Entrada e sa�da padr�o. 
#include <stdlib.h> //Para fun��o rand e system.
#include <conio.h>  //Para usar a fun��o _getch.
#include <time.h>   //Para sortear n�meros pseudoaleat�rios.
#include <locale.h>
#include <Windows.h>
#include "velha.h"

using namespace std;

void show(char board[][MAX_SIZE]) {
    cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t     |     |     \n";
    cout << "\t\t\t\t\t\t  " << board[0][2] << "  |  " << board[0][1] << "  |  " << board[0][0] << "  \n";
    cout << "\t\t\t\t\t\t_____|_____|_____\n\t\t\t\t\t\t     |     |     \n";
    cout << "\t\t\t\t\t\t  " << board[1][2] << "  |  " << board[1][1] << "  |  " << board[1][0] << "  \n";
    cout << "\t\t\t\t\t\t_____|_____|_____\n\t\t\t\t\t\t     |     |     \n";
    cout << "\t\t\t\t\t\t  " << board[2][2] << "  |  " << board[2][1] << "  |  " << board[2][0] << "  \n";
    cout << "\t\t\t\t\t\t     |     |     \n";
}

int isEmpty(char board[][MAX_SIZE], char tecla) {
    switch (tecla)
    {
    case '1':
        return board[2][2] == ' '; // Retorna verdadeiro (1) se a posi��o estiver vazia.
    case '2':
        return board[2][1] == ' '; //funciona como condi��o
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
        return 0; // Retorna falso (0) se a posi��o n�o for v�lida.
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

    return (marcador == 'X') ? 1 : 0; //Retorna a vez do pr�ximo jogador.
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

    return ' ';  // Retorna um espa�o em branco se n�o houver vencedor ainda
}

void revezamento(int nmoves, int* vez, int* rodada) {
    if (nmoves == 0)
    {
        *vez = *rodada;
        *rodada = !*rodada;
    }
}