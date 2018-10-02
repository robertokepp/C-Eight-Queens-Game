#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int size=8, queens, points=0, count;

char board2[10]= {-1};

void print(char board[size][size])
{
    int i,j;

    printf("\n\t 1c      2c      3c      4c      5c      6c      7c      8c");
    printf("\n");

    for (i=0; i<size; i++)
    {
        printf("\n");
        printf("     %df", i+1);

        for (j=0; j<size; j++)
        {
            printf("\t");
            printf(" %c", board[i][j]);
        }

        printf("\n");
    }
}

void fill(char board[size][size])
{
    int i,j;

    for(i=0; i<size; i++)
        for(j=0; j<size; j++)
            board[i][j]='+';
}

void sides(char board[size][size], int row, int column)
{
    int i,j;

    for(i=0; i<size; i++)
    {
        board[row][i]='+';
        board[i][column]='+';
    }
}

void diagonals(char board[size][size], int row, int column) //Funcion que cambia las queens que esten a los diagonalses de la ultima reina colocada
{
    int i,j;

    i=row;
    j=column;

    while((i<size)&&(j<size))
    {
        board[i][j]='+';
        i++;
        j++;
    }

    i=row;
    j=column;

    while((i>=0)&&(j<size))
    {
        board[i][j]='*';
        i--;
        j++;
    }

    i=row;
    j=column;

    while((i>=0)&&(j>=0))
    {
        board[i][j]='+';
        i--;
        j--;
    }

    i=row;
    j=column;

    while((i<size)&&(j>=0))
    {
        board[i][j]='+';
        i++;
        j--;
    }
}

void counts(char board[size][size])
{
    int i, j;

    queens=0;

    for(i=0; i<size; i++)
    {
        for(j=0; j<size; j++)
        {
            if(board[i][j]=='R')
            {
                queens++;
            }
        }
    }
}

void position(char board[size][size], int row, int column) //Funcion para colocar las queens
{
    int i;

    board[row][column]='R';

    for(i=0; i<10; i++)
    {
        points++;
    }
}

void moves() //Funcion para counts los moves realizados
{
    int i, j;

    for(i=0; i<1; i++)
    {
        count++;
    }

    printf("\n\nmoves realizados: %d\n", count);
}

void resolve(int Valor)
{
    for(board2[Valor]=1; board2[Valor]<=size; board2[Valor]++)
    {
        if(result2(Valor))
        {
            if(Valor==size)
            {
                printResult();
                exit(0);
            }
            else
            {
                resolve(Valor+1);
            }
        }
    }
}

int result2(int Valor)
{
    int i=1;

    while(board2[size]!=board2[i] && abs(board2[Valor]-board2[i])!=(Valor-i) && i<size)
    {
        i++;
    }
    return ((Valor==i)?1:0);
}

void printResult()
{
    int i;

    for(i=1; i<=size; i++)
    {
        printf("\nrows: #%d column: #%d\n", i, board2[i]);
    }
}

int main()
{
    int i, row, column, Numero=8, Menu, Submenu;
    char board[size][size];


    do
    {
        printf("*****Menu*****\n");
        printf("\n- 1. Play\n");
        printf("\n- 2. Instructions\n");
        printf("\n- 3. Solution\n");
        printf("\n- 4. Salir\n");
        printf("\n- Choose an option: #");
        scanf("%d", &Menu);

        printf("\n");
        system("pause");
        system("cls");

        switch(Menu)
        {
        case 1:

            printf("\n- 1. Play\n");
            fill(board);
            print(board);

            do
            {
                do
                {
                    printf("\nPosition to put a queen (row, column): ", 162);
                    scanf("%d,%d", &row, &column);

                    if(row<=0 || column<=0 || row>8 || column>8)
                    {
                        printf("\nThe row and column must be greater than 0 and lesser than 9\n");
                    }
                }
                while(row<=0 || column<=0 || row>8 || column>8);

                row--;
                column--;

                sides(board, row, column);
                diagonals(board, row, column);
                position(board, row, column);
                print(board);
                counts(board);
                moves();

                points=(points-count)+queens;

                printf("\nqueens in the board: %d\n", queens);
                printf("\npoints: %d\n", 162, points);

                //printf("\n");
                //system("pause");
                //system("cls");
            }
            while(queens!=8);

            printf("\n\t\t\tYou Won!!!\n");

            points=0;

            printf("\n");
            system("pause");
            system("cls");

            break;

        case 2:

            printf("\n- 2. Intructions\n");

            printf("\n- The game of the 8 queens consists of placing on a chess board \n\neight queens without these being threatened between them.\n");

            printf("\n");
            system("pause");
            system("cls");

            break;

        case 3:

            printf("\n- 3. Solution\n");

            resolve(1);

            printf("\n");
            system("pause");
            system("cls");

            break;

        case 4:

            printf("\n- 4. Exit\n");

            return 0;
        }
    }
    while(Menu!=4);

    return 0;
}
