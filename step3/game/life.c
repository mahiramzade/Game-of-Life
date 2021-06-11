#include <stdlib.h>
#include <time.h>
#include "life.h"

/** 
 * @param min - minimum value for range
 * @param max - maximum value for range
 * @return random integer value between min and max 
*/
int randInRange(int min, int max)
{
    return min + (int)(rand() / (double)(RAND_MAX + 1.0) * (max - min + 1));
}

/** 
 * @param rows - number of rows
 * @param cols - number of columns
 * @return dynamically allocated two dimensional integer array 
*/
int **allocate2dArr(int rows, int cols)
{
    int **arr = (int **)calloc(sizeof(int *), rows);
    for (int i = 0; i < rows; i++)
        arr[i] = (int *)calloc(sizeof(int), cols);
    return arr;
}

/** 
 * @param arr - 2D integer array
 * @param rows - number of rows
 * @param cols - number of columns
 * @return dynamically allocated copy of arr 
*/
int **copy2dArr(int **arr, int rows, int cols)
{
    int **copy = allocate2dArr(rows, cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            copy[i][j] = arr[i][j];
    return copy;
}

/**
 * @param game - Pointer to the game object
 * @param row - the row of the cell
 * @param col - the column of the cell
 * @return number of the alive neighbours of the cell at row and col
 */
int _getAliveNeighbours(Game *game, int row, int col, int is_clipped)
{
    if (!game)
        return -1;

    int **board = game->board;
    int rows = game->rows;
    int cols = game->cols;
    int aliveCount = 0;

    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            if (i == j && i == 0)
                continue;
            if (is_clipped && ((row + i >= rows || col + j >= cols) ||
                               (row + i < 0 || col + j < 0)))
                continue;
            aliveCount += board[row + i][col + j];
        }
    }
    return aliveCount;
}

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

    int **board = game->board;
    for (int i = 0; i < game->rows; i++)
        for (int j = 0; j < game->cols; j++)
            board[i][j] = randInRange(0, 1) < LIVE_PROB;
}

/**
 * Creates new generation according to the game's rules
 * @param game - Pointer to the game object
 * @return void
*/
void G_live(Game *game, int is_clipped)
{
    if (!game)
        return;
    int **nextBoard = copy2dArr(game->board, game->rows, game->cols);
    for (int i = 0; i < game->rows; i++)
    {
        for (int j = 0; j < game->cols; j++)
        {
            int aliveCount = _getAliveNeighbours(game, i, j, is_clipped);
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
}
