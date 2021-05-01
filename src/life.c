#include <stdlib.h>
#include <time.h>
#include "life.h"
#include "utils.h"

/**
 * @param rows - number of rows of the board
 * @param cols - number of columns of the board
 * @return pointer to the dynamically allocated game object with the board of size rows and cols
*/
Game *G_new(int rows, int cols)
{
    Game *game = (Game *)malloc(sizeof(Game));
    game->generation = 0;
    game->rows = rows;
    game->cols = cols;
    game->board = allocate2dArr(rows, cols);
    return game;
}

/**
 * Randomly initializes the cells of the game's board
 * @param game - pointer to the game object
 * @return void
*/
void G_generate(Game *game)
{
    if (!game)
        return;

    srand(time(NULL));

    for (int i = 0; i < game->rows; i++)
        for (int j = 0; j < game->cols; j++)
            game->board[i][j] = randInRange(0, 1) < LIVE_PROB;
}