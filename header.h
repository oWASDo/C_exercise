
#include ".\SDL\SDL.h"


#define HEIGHT 800
#define WIDHT 600
#define FLAGS 0
#define POINTER_X 10
#define POINTER_Y 171



SDL_Texture* load_texture(const char *file, SDL_Renderer *renderer);
void render_image(SDL_Texture *texture, SDL_Renderer *renderer, const SDL_Rect *s_rect, const SDL_Rect *d_rect, const double angel, const SDL_Point *center,const SDL_RendererFlip flip);

void clock_logic(Uint32 tick,  double *pointer_to_rot, int *pointer_to_timer, Uint32 *last_tick);
