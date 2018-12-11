#include "SDL.h"





SDL_Texture load_texture(const char *file, SDL_Renderer *renderer);
void render_image(SDL_Texture *texture, SDL_Renderer *renderer, const SDL_Rect s_rect, const SDL_Rect d_rect, const double angel, const SDL_Point center,const SDL_RendererFlip flip);