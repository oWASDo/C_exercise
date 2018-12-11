#include "header.h"

void clock_logic(Uint32 tick,  double *pointer_to_rot, int *pointer_to_timer, Uint32 *last_tick)
{
    *pointer_to_timer += tick - *last_tick;
    *last_tick = tick;

        if(*pointer_to_timer > 1200)
        {
            //SDL_Log("Timer: %i",timer);
            *pointer_to_rot += 6;
            *pointer_to_timer = 0;
        }        
}