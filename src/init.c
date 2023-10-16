#include "init.h"

SDL_Window* initWindow(int window_w, int window_h) {
	if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER) != 0) {
		printf("Error initializing SDL: %s\n", SDL_GetError());
		SDL_Quit();	
	}
	
	SDL_Window* window = SDL_CreateWindow("Template", 
																				 SDL_WINDOWPOS_CENTERED,
																				 SDL_WINDOWPOS_CENTERED,
																				 window_w, window_h, 0);
	
	if(!window) {
		printf("Error creating window: %s\n", SDL_GetError());
		SDL_Quit();
	}
	
	return window;
}

SDL_Renderer* initRenderer(SDL_Window* window) {
	Uint32 render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, render_flags);
	if(renderer == NULL) {
		printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
		SDL_DestroyWindow(window);
		SDL_Quit();
	} else {
			//Initialize renderer color
		SDL_SetRenderDrawColor(renderer, 0x0, 0x0, 0x0, 0x0);

		//Initialize PNG loading
		int imgFlags = IMG_INIT_PNG;
		if(!(IMG_Init(imgFlags) & imgFlags ) ) {
				printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
		}
	}
	
	return renderer;
}

struct GameState initGame(SDL_Renderer* renderer, int window_w , int window_h) {

	struct GameState game;
	game.renderer = renderer;
	game.window_w = window_w;
	game.window_h = window_h;

	game.head = NULL;

	
	loadGameObj(&game);
	loadFonts(&game);

	
	return game;
}

void loadGameObj(struct GameState* game) {
		srand(time(NULL));
		int r = (rand() % (MAX_RAND - 0 + 1)) + 0;
	
		char ball_name[] = "ball";
		int ball_w = 32;
		int ball_h = 32;
		int ball_x = game->window_w / 2;
		int ball_y = game->window_h / 2;		
		struct GameObj* ball = newGameObj(&game->head, 
																			 ball_name, 
																			 ball_w, 
																			 ball_h, 
																			 ball_x, 
																			 ball_y);
		applyForce(ball, r, 0.7);
		
		ball->sprite = newSprite("rec/ball.png", game->renderer, 4, 2);
		newAnimation("idle", ball->sprite, 1, 1);
		newAnimation("bounce", ball->sprite, 4, 2);
}

void loadFonts(struct GameState* game) {
	loadFont("rec/font.png", 8, 8, 12, 20, game);
}

struct InputState initInput(){
	struct InputState input;
	input.up = 0;
	input.right = 0;
	input.down = 0;
	input.left = 0;
	input.quit = 0;
	
	return input;
}
