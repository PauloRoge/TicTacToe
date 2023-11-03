#include <iostream> //Entrada e saída padrão. 
#include <stdlib.h> //Para função rand e system.
#include <conio.h>  //Para usar a função _getch.
#include <time.h>   //Para sortear números pseudoaleatórios.
#include <locale.h>
#include <Windows.h>
#include "velha.h"

#define MAX_SIZE 3

using namespace std;

//STRUCTURES
enum Play
{
    PARAR = 0,
    CONTINUAR
};

//PROTOTYPES
// Procedimento para executar jogo contra Computador.
void UmJogador(char board[][MAX_SIZE], char teclado, int vez, int rodada);

// Procedimento para executar jogo com dois jogadores
void DoisJogadores(char board[][MAX_SIZE], char teclado, int vez, int rodada);

// Imprime instruções iniciais.
int info(int tutorial);

// Função que toma a decisão da maquina
void maquina(char board[][MAX_SIZE], char* posicao);

int main()
{
    setlocale(LC_ALL, "portuguese");
    srand((unsigned int)time(NULL));

    char board[MAX_SIZE][MAX_SIZE]; //Inicializa tabuleiro com (3x3) posições.
    char teclado = CONTINUAR;
    char menu = 1; // Armazena uma caracter que codifica uma condição.
    int a = 0; // Comuta entre 0 e 1. se o valor é 1 imprime tutorial.
    int vez = 0;
    int rodada = rand() % 2;


    while (menu)
    {
        info(a);
        menu = _getch();

        switch (menu)
        {
        case '1':
            UmJogador(board, teclado, vez, rodada);
            break;

        case '2':
            DoisJogadores(board, teclado, vez, rodada);
            break;

        case '3':
            a = !a;
            break;

        case '0':
            return 0;

        default:
            break;
        }
    }
}

//PROCEDURES
void UmJogador(char board[][MAX_SIZE], char teclado, int vez, int rodada) {
    char jogador = 0, cpu = 0;

    system("cls");
    cout << "escolha seu marcador (X) ou (O).";
    do
    {
        teclado = toupper(_getch()); // A função toupper pega o caracter da entrada e se for letra deixa maiuscula
    } while (teclado != 'X' && teclado != 'O');

    jogador = teclado;
    cpu = (jogador == 'X') ? 'O' : 'X';

    system("cls");
    teclado = CONTINUAR;

    while (teclado == CONTINUAR)
    {
        int nmoves = 0; //número de movimentos.
        for (int i = 0; i < MAX_SIZE; i++) //Atribui um backspace em cada posição vazia.
            for (int j = 0; j < MAX_SIZE; j++)
                board[i][j] = ' ';

        revezamento(nmoves, &vez, &rodada);

        while (verificarVencedor(board) == ' ' && nmoves < 9)
        {
            system("cls"); //começa o jogo
            show(board);
            cout << endl << "vez ", (vez == 0) ? cout << "do jogador:" : cout << "da maquina:";
            nmoves++;

            if (vez == 0)
                do
                {
                    teclado = _getch();
                } while (teclado < '1' || teclado > '9' || !isEmpty(board, teclado)); //Limitando o domínio entre 1 e 9, usando a tabela ASCII.

            else
            {
                maquina(board, &teclado);
                Sleep(1250);
            }
            vez = fillBoard(board, teclado, vez == 0 ? 'X' : 'O');

        }
        system("cls");
        show(board);

        if (nmoves == 9 && verificarVencedor(board) == ' ') cout << "Draw";
        else
            (verificarVencedor(board) == 'X') ? cout << "X" : cout << "O", cout << " VENCEU!";

        cout << "\n\nDeseja jogar novamente? (s)sim (n)nao";
        do
        {
            teclado = _getch();
        } while (teclado != 's' && teclado != 'n');

        teclado = teclado == 's' ? 1 : 0;
    }
}

void DoisJogadores(char board[][MAX_SIZE], char teclado, int vez, int rodada) {

    while (teclado == CONTINUAR)
    {
        int nmoves = 0; //número de movimentos.
        for (int i = 0; i < MAX_SIZE; i++) //Atribui um backspace em cada posição vazia.
            for (int j = 0; j < MAX_SIZE; j++)
                board[i][j] = ' ';

        if (nmoves == 0) //compromete-se a revesar quem começa em cada partida.
        {
            vez = rodada;
            rodada = !rodada;
        }

        while (verificarVencedor(board) == ' ' && nmoves < 9)
        {
            system("cls"); //começa o jogo
            show(board);
            cout << endl << "vez: ", (vez == 0) ? cout << "X" : cout << "O";
            nmoves++;

            do
            {
                teclado = _getch();
            } while (teclado < '1' || teclado > '9' || !isEmpty(board, teclado)); //Limitando o domínio entre 1 e 9, usando a tabela ASCII.

            vez = fillBoard(board, teclado, vez == 0 ? 'X' : 'O');

        }
        system("cls");
        show(board);

        if (nmoves == 9 && verificarVencedor(board) == ' ') cout << "Draw";
        else
            (verificarVencedor(board) == 'X') ? cout << "X" : cout << "O", cout << " VENCEU!";

        cout << "\n\nDeseja jogar novamente? (s)sim (n)nao";
        do
        {
            teclado = _getch();
        } while (teclado != 's' && teclado != 'n');

        teclado = (teclado == 's') ? 1 : 0;
    }

}

//FUNCTIONS
int info(int tutorial) {
    if (!tutorial)
    {
        system("cls");
        cout << "\n\n\tEscolha o modo de jogo:\n\n\t(1)Um Jogador\n\t(2)Dois Jogadores\n\t(3)";
        cout << "Como Jogar\n\t(0)Sair\n\n";
    }
    if (tutorial)
    {
        cout << "\t     |     |     \n\t  7  |  8  |  9  \n\t_____|_____|_____";
        cout << "\n\t     |     |     \tuse o teclado numerico.";
        cout << "\n\t  4  |  5  |  6  \t\n\t_____|_____|__";
        cout << "___\n\t     |     |     \n\t  1  |  2  |  3  \n\t     |     |\n\n";
        return 0;
    }
    return 1;
}

void maquina(char board[][MAX_SIZE], char* posicao) {
    char aux[9] = { '1','2','3','4','5','6','7','8','9' };
    do
    {
        *posicao = aux[rand() % 9];
    } while (*posicao < '1' || *posicao > '9' || !isEmpty(board, *posicao)); //Limitando o domínio entre 1 e 9, usando a tabela ASCII.
}

