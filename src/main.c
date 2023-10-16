#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>

#include "types.h"
#include "init.h"
#include "input.h"
#include "update.h"
#include "renderer.h"
#include "cleanup.h"

#define SCREEN_WIDTH	800
#define SCREEN_HEIGHT	600

int main(void) {
	int window_w = SCREEN_WIDTH;
	int window_h = SCREEN_HEIGHT;

	SDL_Window* window      = initWindow(window_w, window_h);
	SDL_Renderer* renderer  = initRenderer(window);
	struct GameState game   = initGame(renderer, window_w, window_h);
	struct InputState input = initInput();
	
	while(!input.quit) {
		
		SDL_RenderClear(renderer);
		
		processEvents(&input);
		update(&input, &game);
		render(&game);

		SDL_Delay(1000/60);
	}

	cleanupAllGameObjects(game.head);
	free(game.font);
	cleanupRenderer(renderer);
	cleanupWindow(window);

	return 0;
}
