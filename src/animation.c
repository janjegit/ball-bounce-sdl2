#include "animation.h"

void newAnimation(char* name, struct Sprite* sprite, 
									int numOfClips, int row) {
	
	if(name == NULL) {
			
		printf("Error. Loading Animation. Animation name empty.\n");
									
	} else if(sprite == NULL) {
			
		printf("Error. Loading Animation '%s'. Sprite empty.\n", name);
			
	} else if(numOfClips < 1 || numOfClips > sprite->clip_colums || 
			row < 1 || row > sprite->clip_rows) {
			
		printf("Error. Loading Animation '%s'. Check clip arguments.\n", name);
		
	} else {
	
		struct Animation* animation = (struct Animation*) malloc(sizeof(struct Animation));
		
		memset(animation->name, '\0', sizeof(animation->name));
		strcpy(animation->name, name);
		
		SDL_Rect dest;
		if(sprite->texture == NULL) {  
			printf("Error. No texture found in sprite struct.\n");
		} else {
			SDL_QueryTexture(sprite->texture, NULL, NULL, &dest.w, &dest.h);
		}
		
		animation->numOfClips = numOfClips;
		animation->frame = 0;
		animation->run = false;
		
		for(int j = 0; j < numOfClips; ++j) {
			animation->spriteClips[j].x = (dest.w / sprite->clip_colums) * j;
			animation->spriteClips[j].y = dest.h * (row - 1);
			animation->spriteClips[j].w = dest.w / sprite->clip_colums;
			animation->spriteClips[j].h = dest.h / sprite->clip_rows;
		}
		
		animation_table_insert(sprite, animation);
		
		printf("Animation '%s' loaded.\n", animation->name);
	}
}
