#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "board_drawer.h"
#include "life.h"

#define MAX_GEN 10000

int main()
{
    int width, height;
    get_terminal_size(&width, &height);
    Game *game = G_new(height, width);
    G_generate(game);

    for (int i = 0; i < MAX_GEN; i++)
    {
        draw_board(game);
        G_live(game);
        usleep(100000);
    }

    return 0;
}