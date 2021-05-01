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

/**
 * @param game - Pointer to the game object
 * @param row - the row of the cell
 * @param col - the column of the cell
 * @return number of the alive neighbours of the cell at row and col
 */
int _getAliveNeighbours(Game *game, int row, int col)
{
    if (!game)
        return -1;

    int aliveCount = 0;
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            if (
                (i == j && i == 0) ||
                (row + i >= game->rows || col + j >= game->cols) ||
                (row + i < 0 || col + j < 0))
                continue;
            aliveCount += game->board[row + i][col + j];
        }
    }
    return aliveCount;
}

/**
 * Creates new generation according to the game's rules
 * @param game - Pointer to the game object
 * @return void
*/
void G_live(Game *game)
{
    if (!game)
        return;
    int **nextBoard = copy2dArr(game->board, game->rows, game->cols);
    for (int i = 0; i < game->rows; i++)
    {
        for (int j = 0; j < game->cols; j++)
        {
            int aliveCount = _getAliveNeighbours(game, i, j);
            if (game->board[i][j])
            {
                nextBoard[i][j] = !(aliveCount < 2 || aliveCount > 3);
            }
            else if (!game->board[i][j])
            {
                nextBoard[i][j] = aliveCount == 3;
            }
        }
    }
    free(game->board);
    game->board = nextBoard;
    game->generation++;
}
