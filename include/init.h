#ifndef INIT_H_INCLUDE
#define INIT_H_INCLUDE

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "types.h"
#include "gameobj.h"
#include "sprite.h"
#include "animation.h"
#include "font.h"

#define MAX_RAND 20

SDL_Window* initWindow(int window_w, int window_h);

SDL_Renderer* initRenderer(SDL_Window* window);

struct GameState initGame(SDL_Renderer* renderer, int window_w , int window_h);

void loadGameObj(struct GameState* game);

void loadFonts(struct GameState* game);

struct InputState initInput();

#endif
