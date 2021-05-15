#ifndef __ANSI_H__
#define __ANSI_H__
#include "life.h"

/**
 * Gets terminal width and height and assign them
 * to the appropriate memory addresses
 * @param width - pointer to an integer
 * @param height - pointer to an integer 
 * @return void
*/
void get_terminal_size(int *width, int *height);

/**
 * Prints the game's board on the terminal
 * @param game - Pointer to the game object
 * @return void
*/
void draw_board(Game *game);

#endif