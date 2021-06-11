#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <SDL.h>

#include "gui.h"
#include "life.h"
#include "config.h"

#define MAX_GEN 10000

#ifdef IS_CLIPPED

int is_clipped = 1;

#else

int is_clipped = 0;

#endif

int main()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        perror("SDL_Init failed");
        exit(EXIT_FAILURE);
    }

    SDL_Window *window = SDL_CreateWindow("Game of Life",
                                          SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                          WINDOW_SIZE, WINDOW_SIZE, SDL_WINDOW_SHOWN | SDL_WINDOW_ALLOW_HIGHDPI);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    Game *game = G_new(WINDOW_SIZE, WINDOW_SIZE);
    G_generate(game);

    SDL_Event event;
    int quit = 0;

    for (int i = 0; i < MAX_GEN && !quit; i++)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                quit = 1;
        }

        SDL_RenderClear(renderer);
        draw_board(game, renderer);
        G_live(game, is_clipped);
        SDL_RenderPresent(renderer);
    }
    
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
