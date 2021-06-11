#include <stdio.h>
#include <SDL2/SDL.h>
#include "gui.h"
#include "../config.h"

void draw_board(Game *game, SDL_Renderer *renderer)
{
    if (!game)
        return;

    SDL_Rect rect;
    rect.w = CELL_SIZE;
    rect.h = CELL_SIZE;
    for (int i = 0; i < game->rows; i++)
    {
        for (int j = 0; j < game->cols; j++)
        {
            rect.x = j * CELL_SIZE;
            rect.y = i * CELL_SIZE;

            game->board[i][j] ? SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0)
                              :SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

            SDL_RenderDrawRect(renderer, &rect);
            SDL_RenderFillRect(renderer, &rect);
        }
    }
}