#include <stdlib.h>
#include <time.h>
#include "life.h"

int randInRange(int min, int max)
{
    return min + (int)(rand() / (double)(RAND_MAX + 1.0) * (max - min + 1));
}

int **allocate2dArr(int rows, int cols)
{
    int **arr = (int **)calloc(sizeof(int *), rows);
    for (int i = 0; i < rows; i++)
        arr[i] = (int *)calloc(sizeof(int), cols);
    return arr;
}

int **copy2dArr(int **arr, int rows, int cols)
{
    int **copy = allocate2dArr(rows, cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            copy[i][j] = arr[i][j];
    return copy;
}

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

            int r = row + i < 0 ? rows - 1 : row + i;
            r = row + i >= rows ? 0 : r;
            int c = col + j < 0 ? cols - 1 : col + j;
            c = col + j >= cols ? 0 : c;
            aliveCount += board[r][c];
        }
    }
    return aliveCount;
}

Game *G_new(int rows, int cols)
{
    Game *game = (Game *)malloc(sizeof(Game));
    game->generation = 0;
    game->rows = rows;
    game->cols = cols;
    game->board = allocate2dArr(rows, cols);
    return game;
}

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
