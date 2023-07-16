#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>

#define MAX_SIZE 10

char continuar;
int i, ind, fim;
char teclado;
int indice=0,vez=0;

void tecla(); //converte caracter em inteiro.
void info(); //imprime instruções.
void imprimir(char* wjogo); //imprime a tabela em cada instância.

int main(){
    setlocale(LC_ALL,"portuguese");
    info();

    do{
        continuar=_getch();
    } while (continuar!='s' && continuar!='n'); //garante que não haja entrada inválida.

    while (continuar=='s')
    {
        char jogo[MAX_SIZE];
        for (int j = 0; j < MAX_SIZE; j++, jogo[j] = ' ');

        for (i = 0; i < MAX_SIZE; i++)
        {
            system("cls");
            imprimir(jogo);

            if (jogo[7]=='x' && jogo[4]=='x' && jogo[1]=='x')
            {
                printf("x venceu na primeira coluna.");
                break;
            }
            if (jogo[8]=='x' && jogo[5]=='x' && jogo[2]=='x')
            {
                printf("x venceu na segunda coluna.");
                break;
            }
            if (jogo[9]=='x' && jogo[6]=='x' && jogo[3]=='x')
            {
                printf("x venceu na terceira coluna.");
                break;
            }
            if (jogo[7]=='x' && jogo[8]=='x' && jogo[9]=='x')
            {
                printf("x venceu  na terceira linha");
                break;
            }
            if (jogo[4]=='x' && jogo[5]=='x' && jogo[6]=='x')
            {
                printf("x venceu na segunda linha.");
                break;
            }
            if (jogo[1]=='x' && jogo[2]=='x' && jogo[3]=='x')
            {
                printf("x venceu na primeira linha.");
                break;
            }
            if (jogo[7]=='x' && jogo[5]=='x' && jogo[3]=='x')
            {
                printf("x venceu na diagonal.");
                break;
            }
            if (jogo[1]=='x' && jogo[5]=='x' && jogo[9]=='x')
            {
                printf("x venceu na diagonal secundária.");
                break;
            }

            if (jogo[7]=='O' && jogo[4]=='O' && jogo[1]=='O')
            {
                printf("(o) venceu na primeira coluna.");
                break;
            }
            if (jogo[8]=='O' && jogo[5]=='O' && jogo[2]=='O')
            {
                printf("(o) venceu na segunda coluna.");
                break;
            }
            if (jogo[9]=='O' && jogo[6]=='O' && jogo[3]=='O')
            {
                printf("(o) venceu na terceira coluna.");
                break;
            }
            if (jogo[7]=='O' && jogo[8]=='O' && jogo[9]=='O')
            {
                printf("(o) venceu na terceira linha.");
                break;
            }
            if (jogo[4]=='O' && jogo[5]=='O' && jogo[6]=='O')
            {
                printf("(o) venceu na segunda linha.");
                break;
            }
            if (jogo[1]=='O' && jogo[2]=='O' && jogo[3]=='O')
            {
                printf("(o) venceu na primeira linha.");
                break;
            }
            if (jogo[7]=='O' && jogo[5]=='O' && jogo[3]=='O')
            {
                printf("(o) venceu na diagonal.");
                break;
            }
            if (jogo[9]=='O' && jogo[5]=='O' && jogo[1]=='O')
            {
                printf("(o) venceu na diagonal secundária.");
                break;
            }
             if(fim==45)
            {
                //system("color 7C");
                printf("VELHA!!");
                break;
            }
            if (indice%2 == 0)
            {
                printf(" vez do xis(x)\n\n");
                do
                {
                    teclado=_getch();
                    tecla(teclado);

                    if (jogo[ind] == 'x'|| jogo[ind] =='O')
                    {
                        ind = 10; //para fazer novamente o laço.
                    }
                } while (ind < 1 || ind > 9);

                jogo[ind]='x';
                fim=fim+ind;
            }
            if (indice%2 != 0)
            {
                printf(" vez da bolinha(o)\n\n");
                do{
                    teclado=_getch();
                    tecla();
                    if (jogo[ind] == 'O'|| jogo[ind] == 'x')
                    {
                        ind = 10; //para fazer novamente o laço.
                    }
                } while (ind < 1 || ind > 9);
                jogo[ind]='O';
                fim=fim+ind;
            }
            ind=0;
            indice++;
        }
        fim=0;
        vez++;
        vez%2 != 0 ? indice= 1 : 0;
        printf("\n\n\tjogar novamente?\n\t(s)sim  (n)não");
        
        do{
        continuar=_getch();
        } while (continuar!='s' && continuar!='n');
    } 
}

void tecla()
{
    switch (teclado)
    {
    case '1':
        ind=1;
        break;

    case '2':
        ind=2;
        break;

    case '3':
        ind=3;
        break;

    case '4':
        ind=4;
        break;

    case '5':
        ind=5;
        break;

    case '6':
        ind=6;
        break;

    case '7':
        ind=7;
        break;

    case '8':
        ind=8;
        break;

    case '9':
        ind=9;
        break;
    } 
}

void info() {
    printf("\n\tJogo da velha. #1\n\n\tComo jogar: \n\n");
    printf("\t     |     |     \n\t  7  |  8  |  9  \n\t_____|_____|_____");
    printf("\n\t     |     |     \t*use o teclado numérico para seleciona");
    printf("r\n\t  4  |  5  |  6  \ta posição desejada.\n\t_____|_____|__");
    printf("___\n\t     |     |     \n\t  1  |  2  |  3  \n\t     |     |");
    printf("     \n\n\tJogar? (s)sim (n)não");
}

void imprimir(char* wjogo) {
    printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t     |     |     \n");
    printf("\t\t\t\t\t\t  %c  |  %c  |  %c  \n", wjogo[7], wjogo[8], wjogo[9]);
    printf("\t\t\t\t\t\t_____|_____|_____\n\t\t\t\t\t\t     |     |     \n");
    printf("\t\t\t\t\t\t  %c  |  %c  |  %c  \n", wjogo[4], wjogo[5], wjogo[6]);
    printf("\t\t\t\t\t\t_____|_____|_____\n\t\t\t\t\t\t     |     |     \n");
    printf("\t\t\t\t\t\t  %c  |  %c  |  %c  \n", wjogo[1], wjogo[2], wjogo[3]);
    printf("\t\t\t\t\t\t     |     |     \n");
}
