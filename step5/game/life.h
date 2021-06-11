#ifndef LIFE_H
#define LIFE_H

#define LIVE_PROB 0.6

typedef struct game
{
    int generation;
    int rows, cols;
    int **board;
} Game;

Game *G_new(int rows, int cols);

void G_generate(Game *game);

void G_live(Game *game, int is_clipped);

#endif
