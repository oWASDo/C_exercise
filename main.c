#define SDL_MAIN_HANDLED
#include "header.h"

int main(int argc, char const *argv[])
{
    int ret = 0;
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO))
    {
        SDL_Log("unable to init SDL: %s", SDL_GetError());
        ret = -1;
        goto cleanup;
    }

    SDL_Window *window = SDL_CreateWindow("CLC", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, HEIGHT, WIDHT, FLAGS );
    if(!window)
    {
        SDL_Log("unable to create window: %s", SDL_GetError());
        ret = -1;
        goto cleanup2;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
    if (!renderer)
	{
		SDL_Log("unable to create renderer: %s", SDL_GetError());
		ret = -1;
		goto cleanup3;
	}
    SDL_Event event;
    for(;;)
    {
        while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				goto cleanup4;
			}
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

        SDL_RenderPresent(renderer);

    }
cleanup4:
	SDL_DestroyRenderer(renderer);
cleanup3:
	SDL_DestroyWindow(window);
cleanup2:
	SDL_Quit();
cleanup:
	return ret;
}
