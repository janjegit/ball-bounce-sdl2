#include "sprite.h"

struct Sprite* newSprite(char* texturePath, 
													SDL_Renderer* renderer, 
													int clip_colums, 
													int clip_rows) {
										
	struct Sprite* sprite = (struct Sprite*) malloc(sizeof(struct Sprite));
	
	if(texturePath != NULL) {
		char path[MAX_PATH];
		memset(path, '\0', sizeof(path));
		strcpy(path, texturePath);
		sprite->texture = loadTexture(path, renderer);
	}

	sprite->renderer = renderer;
	sprite->clip_colums = clip_colums;
	sprite->clip_rows = clip_rows;
	
	init_animation_table(sprite);
	
	return sprite;
}
