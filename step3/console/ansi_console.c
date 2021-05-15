#include <stdio.h>
#include "board_drawer.h"

/**
 * Gets terminal width and height and assign them
 * to the appropriate memory addresses
 * @param width address of an integer
 * @param height address of an integer 
 * @return void
*/
void get_terminal_size(int *width, int *height)
{
    // Clear entire screen
    printf("\033[2J");
    puts("Enter twice to start the game");

    // Puts cursor to the right bottom of the terminal
    printf("\033[30m\033[10000000;10000000H");
    // Reports cursor's position as \033[<row>;<column>R
    printf("\033[6n");

    // Gets the cursor position
    int returned = scanf("\033[%d;%dR", height, width);

    // Cursor is half width of the block, thus to get the width
    // we divide it by two and in case of odd number we add 1
    *width = *width / 2 + *width % 2;
}

void draw_board(Game *game)
{
    if (!game)
        return;
    // Clear entire screen
    printf("\033[2J");
    for (int i = 0; i < game->rows; i++)
    {
        printf("\033[%d;0H  ", i);
        for (int j = 0; j < game->cols; j++)
            printf(game->board[i][j] ? LIVE : DEAD);
    }
}