#include <stdio.h>  //Entrada e saída padrão.
#include <stdlib.h> //Para função rand e system.
#include <conio.h>  //Para usar a função _getch.
#include <time.h>   //Para sortear números pseudoaleatórios.
#include <locale.h>

#define MAX_SIZE 3

//STRUCTURES
enum Play
{
    PARAR = 0,
    CONTINUAR
};

//PROTOTYPES

//Procedimento para executar jogo com dois jogadores
void DoisJogadores();

//Imprime instruções iniciais.
int info(int tutorial); 

//Imprime a tabela em cada instância da partida.
void show(char board[][MAX_SIZE]); 

//Verificar se a posição no tabuleiro está vazia.
int isEmpty(char board[][MAX_SIZE],char tecla);

//Preenche as marcações no tabuleiro.
int fillBoard(char(*board)[3], char teclado, char marcador);  

//Função que retorna o resultado da partida.
int verificarVencedor(char board[][MAX_SIZE]); 

int main()
{
    setlocale(LC_ALL, "portuguese");
    srand((unsigned int)time(NULL));

    char menu = 1; // Armazena uma caracter que codifica uma condição.
    int a = 0; //comuta entre 0 e 1. se o valor é 1 imprime tutorial.

    
    while (menu)
    {
        info(a);
        menu = _getch();

        switch (menu)
        {
        case '1':
            break;

        case '2':
            DoisJogadores();
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
void DoisJogadores() {
        char board[MAX_SIZE][MAX_SIZE]; //Inicializa tabuleiro com (3x3) posições.
        char teclado = CONTINUAR;
        int vez = rand() % 2;

        while (teclado == CONTINUAR)
        {
            int nmoves = 0; //número de movimentos.
            for (int i = 0; i < MAX_SIZE; i++) //Atribui um backspace em cada posição vazia.
                for (int j = 0; j < MAX_SIZE; j++)
                    board[i][j] = ' ';

            while (verificarVencedor(board) == ' ' && nmoves < 9)
            {
                system("cls"); //começa o jogo
                show(board);
                printf("\nvez: (%s)", vez == 0 ? "X" : "O");
                nmoves++;

                do
                {
                    teclado = _getch();
                } while (teclado < '1' || teclado > '9' || !isEmpty(board, teclado)); //Limitando o domínio entre 1 e 9, usando a tabela ASCII.

                vez = fillBoard(board, teclado, vez == 0 ? 'X' : 'O');
                
            }
            system("cls");
            show(board);

            if (nmoves == 9 && verificarVencedor(board) == ' ') printf("Draw");
            else
                printf("\n\n%s VENCEU!", verificarVencedor(board) == 'X' ? "X" : "O");

            printf("\n\nDeseja jogar novamente? (s)sim (n)nao");
            do
            {
                teclado = _getch();
            } while (teclado !='s' && teclado != 'n');

            teclado = (teclado == 's') ? CONTINUAR : PARAR;
        }
       
}

//FUNCTIONS
int isEmpty(char board[][MAX_SIZE], char tecla) {
    switch (tecla)
    {
    case '1':
        return board[2][2] == ' '; // Retorna verdadeiro (1) se a posição estiver vazia.
    case '2':
        return board[2][1] == ' '; //funciona como condição
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

int info(int tutorial) {
    if (!tutorial)
    {
        system("cls");
        printf("\n\n\tEscolha o modo de jogo:\n\n\t(1)Um Jogador\n\t(2)Dois Jogadores\n\t(3)");
        printf("Como Jogar\n\t(0)Sair\n\n");
    }
        if (tutorial)
        {
            printf("\t     |     |     \n\t  7  |  8  |  9  \n\t_____|_____|_____");
            printf("\n\t     |     |     \tuse o teclado numerico.");
            printf("\n\t  4  |  5  |  6  \t\n\t_____|_____|__");
            printf("___\n\t     |     |     \n\t  1  |  2  |  3  \n\t     |     |\n\n");
            return 0;
        }
        return 1;
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