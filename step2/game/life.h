#ifndef __LIFE_H__
#define __LIFE_H__

#define DEAD "\033[40m  "
#define LIVE "\033[46m  "
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
void G_live(Game *game);

#endif
