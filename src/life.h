#ifndef __LIFE_H__
#define __LIFE_H__

/** Escape seqeunce for dead cell color */
#define DEAD "\033[40m  "
/** Escape seqeunce for alive cell color */
#define LIVE "\033[46m  "
/** Probability for the cell to be alive at  */
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

#endif
