#include "input.h"

void processEvents(struct InputState* input) {
	SDL_Event event;
	
	// process events
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_QUIT:
			input->quit = 1;
			break;
			case SDL_KEYDOWN:
			switch (event.key.keysym.scancode) {
				case SDL_SCANCODE_W:
				case SDL_SCANCODE_UP:
					input->up = 1;
					break;
				case SDL_SCANCODE_A:
				case SDL_SCANCODE_LEFT:
					input->left = 1;
					break;
				case SDL_SCANCODE_S:
				case SDL_SCANCODE_DOWN:
					input->down = 1;
					break;
				case SDL_SCANCODE_D:
				case SDL_SCANCODE_RIGHT:
					input->right = 1;
					break;
				default:
					break;
			}
			break;
			case SDL_KEYUP:
			switch (event.key.keysym.scancode) {
				case SDL_SCANCODE_W:
				case SDL_SCANCODE_UP:
					input->up = 0;
					break;
				case SDL_SCANCODE_A:
				case SDL_SCANCODE_LEFT:
					input->left = 0;
					break;
				case SDL_SCANCODE_S:
				case SDL_SCANCODE_DOWN:
					input->down = 0;
					break;
				case SDL_SCANCODE_D:
				case SDL_SCANCODE_RIGHT:
					input->right = 0;
					break;
				default:
					break;	            
			}
			break;
		}
	}
}
