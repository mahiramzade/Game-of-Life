#ifndef LIFE_H
#define LIFE_H

#define LIVE_PROB 0.6

/** structure of the game */
typedef struct game
{
    /** current generation of the game*/
    int generation;
    /** number of rows of the game board */
    int rows;
    /** number of cols of the game board */
    int cols;
    /** two dimensional array representing game board */
    int **board;
} Game;

/**
 * @param rows - number of rows of the board
 * @param cols - number of columns of the board
 * @return pointer to the dynamically allocated game object with the board of size rows and cols
*/
Game *G_new(int rows, int cols);

/**
 * Randomly initializes the cells of the game's board
 * @param game - pointer to the game object
 * @return void
*/
void G_generate(Game *game);

/**
 * Creates new generation according to the game's rules
 * @param game - Pointer to the game object
 * @return void
*/
void G_live(Game *game, int is_clipped);

/**
 * @param game - Pointer to the game object
 * @param row - the row of the cell
 * @param col - the column of the cell
 * @return number of the alive neighbours of the cell at row and col
 */
int _getAliveNeighbours(Game *game, int row, int col, int is_clipped);

#endif
