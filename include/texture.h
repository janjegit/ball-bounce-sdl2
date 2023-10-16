#ifndef TEXTURE_H_INCLUDE
#define TEXTURE_H_INCLUDE

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "types.h"

SDL_Texture* loadTexture(char* path, SDL_Renderer* renderer);

#endif
