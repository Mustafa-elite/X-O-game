#include <stdio.h>
#include <stdlib.h>
#include "prototypes.h"

enum {
    top_left = 1, top_middle, top_right,
    middle_left, middle_middle, middle_right,
    bottom_left, bottom_middle, bottom_right
};
enum { player_1 = 1, player_2 };

void Draw_table(char table[][11])
{
    char square_num = '1';
    printf("each player should choose the num where he wants to play\n\n");
    for (int row = 0; row < 11; row++)
    {
        for (int col = 0; col < 11; col++)
        {
            if (col == 3 || col == 7)
            {
                table[row][col] = '|';
                continue;
            }
            if (row == 3 || row == 7)
            {
                table[row][col] = '_';
                continue;
            }
            table[row][col] = ' ';

        }
    }
    for (int row = 0; row < 11; row += 4)
    {
        for (int col = 0; col < 11; col += 4)
        {
            table[row][col] = square_num++;
        }
    }

}
void print_table(char table[][11])
{
    for (int row = 0; row < 11; row++)
    {
        printf("\t");
        for (int col = 0; col < 11; col++)
        {
            printf("%c", table[row][col]);
        }
        printf("\n");
    }

}
void modify_table(char table[][11], int square_num, int player)
{
    char X_O;
    if (player == player_1)
        X_O = 'X';
    else
        X_O = 'O';
    switch (square_num)
    {
    case(top_left):
        table[1][1] = X_O;
        break;
    case(top_middle):
        table[1][5] = X_O;
        break;
    case(top_right):
        table[1][9] = X_O;
        break;
    case(middle_left):
        table[5][1] = X_O;
        break;
    case(middle_middle):
        table[5][5] = X_O;
        break;
    case(middle_right):
        table[5][9] = X_O;
        break;
    case(bottom_left):
        table[9][1] = X_O;
        break;
    case(bottom_middle):
        table[9][5] = X_O;
        break;
    case(bottom_right):
        table[9][9] = X_O;
        break;
    }
}
int take_input(int Player)
{
    int square_num;
    if (Player == player_1)
    {
        printf("player 1:");
        scanf_s("%d", &square_num);
    }
    if (Player == player_2)
    {
        printf("player 2:");
        scanf_s("%d", &square_num);
    }
    printf("\n");
    return square_num;
}
void check_winner(char table[][11])
{
    for (int row = 1; row < 11; row += 4)
    {
        if (table[row][1] == table[row][5] && table[row][5] == table[row][9] && table[row][1] != ' ')
        {
            if (table[row][1] == 'X')
            {
                printf("player 1 is winner\n");
                exit(1);
            }
            else
            {
                printf("player 2 is winner\n");
                exit(1);
            }
        }
    }
    for (int col = 1; col < 11; col += 4)
    {
        if (table[1][col] == table[5][col] && table[5][col] == table[9][col] && table[1][col] != ' ')
        {
            if (table[1][col] == 'X')
            {
                printf("player 1 is winner\n");
                exit(1);
            }
            else
            {
                printf("player 2 is winner\n");
                exit(1);
            }
        }

    }
    if (table[1][1] == table[5][5] && table[5][5] == table[9][9] && table[1][1] != ' ')
    {
        if (table[1][1] == 'X')
        {
            printf("player 1 is winner\n");
            exit(1);
        }
        else
        {
            printf("player 2 is winner\n");
            exit(1);
        }
    }
    if (table[1][9] == table[5][5] && table[5][5] == table[9][1] && table[1][9] != ' ')
    {
        if (table[1][9] == 'X')
        {
            printf("player 1 is winner\n");
            exit(1);
        }
        else
        {
            printf("player 2 is winner\n");
            exit(1);
        }
    }

}