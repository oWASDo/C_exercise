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

    SDL_Texture* texture_clock = load_texture("clock.bmp", renderer);
    SDL_Texture* texture_pointer = load_texture("pointer.bmp", renderer);

    

    int timer = 0;
    Uint32 last_tick = SDL_GetTicks();

    SDL_Rect rect;
    rect.w = 500;
    rect.h = 500;
    rect.x = 50;
    rect.y = 50;

    SDL_Rect rect_pointer;
    rect_pointer.w = 21;
    rect_pointer.h = 182;
    rect_pointer.x = (rect.x - POINTER_X) + (rect.w / 2);
    rect_pointer.y = (rect.y - POINTER_Y) + (rect.h / 2);

    SDL_RendererFlip renderFlip = SDL_FLIP_NONE;


    SDL_Point point;
    point.x = POINTER_X;
    point.y = POINTER_Y;

    double rot = 0;
    for(;;)
    {
        SDL_Event event;
        Uint32 current_tick = SDL_GetTicks();
        // timer += current_tick - last_tick;
        // last_tick = current_tick;

        // if(timer > 1200)
        // {
        //     //SDL_Log("Timer: %i",timer);
        //     rot += 6;
        //     timer = 0;
        // }       

        clock_logic(current_tick, &rot, &timer, &last_tick);

        while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				goto cleanup4;
			}
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

        render_image(texture_clock, renderer, NULL, &rect, 0, NULL, renderFlip);
        render_image(texture_pointer, renderer, NULL, &rect_pointer, rot, &point, renderFlip);

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
