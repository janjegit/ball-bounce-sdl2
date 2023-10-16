#ifndef SPRITE_H_INCLUDE
#define SPRITE_H_INCLUDE

#include <SDL2/SDL.h>
#include "texture.h"
#include "animation_table.h"
#include "types.h"

struct Sprite* newSprite(char* texturePath, 
													SDL_Renderer* renderer, 
													int clip_colums, 
													int clip_rows);

#endif
