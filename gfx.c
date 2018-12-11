#include "header.h"

SDL_Texture* load_texture(const char *file, SDL_Renderer *renderer)
{
    SDL_Surface *surface = SDL_LoadBMP(file);
    if (surface == NULL)
    {
        SDL_Log(SDL_GetError());
        return NULL;
    }
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);

    if (texture == NULL)
    {
        SDL_Log(SDL_GetError());
        return NULL;
    }
    return texture;
}
void render_image(SDL_Texture *texture, SDL_Renderer *renderer, const SDL_Rect *s_rect, const SDL_Rect *d_rect, const double angel, const SDL_Point *center,const SDL_RendererFlip flip)
{

    SDL_RenderCopyEx(renderer, texture, s_rect, d_rect, angel, center, flip);
}
