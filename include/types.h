#ifndef TYPES_H_INCLUDE
#define TYPES_H_INCLUDE

#include <stdbool.h>
#include <SDL2/SDL.h>

#define MAX_NAME 20
#define MAX_PATH 50

#define MAX_FONT_CLIPS 64

#define ANIMATION_TABLE_SIZE 20
#define MAX_SPRITE_CLIPS 20

struct Vector {
	float x;
	float y;
};

struct GameObj {
	char name[MAX_NAME];
	int w;
	int h;
	struct Vector pos;
	struct Vector acc;
	struct Vector vel;
	
	char status[MAX_NAME];
	struct Sprite* sprite;
	struct GameObj* next;
};

struct Sprite {
	SDL_Renderer* renderer;
	SDL_Texture* texture;
	int clip_colums;
	int clip_rows;
	
	struct Animation* animation_table[ANIMATION_TABLE_SIZE];
};

struct Animation {
	char name[MAX_NAME];
	int frame;
	int numOfClips;
	
	bool run;
	SDL_Rect spriteClips[MAX_SPRITE_CLIPS];
	struct Animation* next;
};

struct InputState {
	int up;
	int right;
	int down;
	int left;
	int quit;
};

struct GameState {
	int window_w;
	int window_h;
	
	struct GameObj* head;
	struct Font* font;
	
	SDL_Window* window; 
	SDL_Renderer* renderer;
};

struct Font {
	SDL_Rect clips[MAX_FONT_CLIPS];

	SDL_Renderer* renderer;
	SDL_Texture* texture;
};

#endif
