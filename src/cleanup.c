#include "cleanup.h"

void cleanupWindow(SDL_Window* window) {
	if(window != NULL) {
		SDL_DestroyWindow(window);
	}
}

void cleanupRenderer(SDL_Renderer* renderer) {
	if(renderer != NULL) {
		SDL_DestroyRenderer(renderer);
	}
}

void cleanupTexture(SDL_Texture* texture) {
	if(texture != NULL) {
		SDL_DestroyTexture(texture);
	}
}

void cleanupAllGameObjects(struct GameObj* head) {
	struct GameObj* current = head;
	struct GameObj* tmp = NULL;
	
	while(current != NULL) {
		tmp = current;
		current = current->next;
		
		cleanupAnimations(tmp->sprite);
		cleanupTexture(tmp->sprite->texture);
		//Clean up current game object's sprite.
		free(tmp->sprite);
		
		//Clean up current game object.
		free(tmp);
	}
}

void cleanupAnimations(struct Sprite* sprite) {
	struct Animation* tmp = NULL;
	struct Animation* prev = NULL;
	
	for(int i = 0; i < ANIMATION_TABLE_SIZE; ++i) {
		tmp = sprite->animation_table[i];
	
		while(tmp != NULL) {
			prev = tmp;
			tmp = tmp->next;
			free(prev);
		}
	}
}
