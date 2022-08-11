#include <stdio.h>
#include <stdlib.h>
#include "prototypes.h"
//#include "X-O functions.c"
enum { player_1 = 1, player_2 };
int main()
{
    char table[11][11];
    Draw_table(table);
    print_table(table);
    int player=player_1,square_num;
    for (int i = 0; i < 9; i++)
    {
        square_num=take_input(player);
        modify_table(table, square_num, player);
        print_table(table);
        check_winner(table);
        if (player == player_1)
            player = player_2;
        else
            player = player_1;

    }
    printf("draw");
    return 0;
}
