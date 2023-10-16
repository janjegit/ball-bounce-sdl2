#ifndef RENDERER_H_INCLUDE
#define RENDERER_H_INCLUDE

#include <SDL2/SDL.h>

#include "types.h"
#include "gameobj.h"
#include "sprite.h"
#include "animation.h"
#include "font.h"

SDL_Rect createRenderDest(struct GameObj* gObj);

void renderGameObj(struct GameObj* gObj);

void renderString(struct Font* font, int x, int y, int w, int h, char* s);
								   
void render(struct GameState* game);

#endif
