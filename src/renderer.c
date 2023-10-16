#include "renderer.h"

SDL_Rect createRenderDest(struct GameObj* gObj) {
	SDL_Rect dest;
	dest.x = gObj->pos.x;
	dest.y = gObj->pos.y;
	dest.w = gObj->w;
	dest.h = gObj->h;
	
	return dest;
}

void renderGameObj(struct GameObj* gObj) {

		SDL_Rect dest = createRenderDest(gObj);
		struct Animation* animation =	animation_table_lookup(gObj->sprite, gObj->status);
		
		if(animation->run) {
			++animation->frame;
			
			if(animation->frame / animation->numOfClips >= animation->numOfClips) {
					strcpy(gObj->status, "idle");
					animation->frame = 0;
					animation->run = false;
			}
		} else {
			animation->frame = 0;
		}

		SDL_RenderCopy(gObj->sprite->renderer, gObj->sprite->texture, &animation->spriteClips[animation->frame], &dest);

}

void renderString(struct Font* font, int x, int y, int w, int h, char* s) {
	SDL_Rect dest;
	dest.x = x;
	dest.y = y;
	dest.w = w;
	dest.h = h;
	SDL_Rect clip;
	for(size_t i = 0; i < strlen(s); ++i) {
		clip = getCharacterClip(font, s[i]);
		dest.x += dest.w + 2;
		SDL_RenderCopy(font->renderer, font->texture, &clip, &dest);
	}
}

void render(struct GameState* game) {

	struct GameObj* current = game->head;
	
	while(current != NULL) {
		renderGameObj(current);
		current = current->next;
	}
	
	struct GameObj* gObj = findGameObj(game->head, "ball");
	char str[10];
	renderString(game->font, 10, 10, 12, 20, "X: ");
	snprintf(str, 10, "%.1f", gObj->pos.x);
	renderString(game->font, 10, 26, 12, 20, str);
	
	renderString(game->font, 10, 42, 12, 20, "Y: ");
	snprintf(str, 10, "%.1f", gObj->pos.y);
	renderString(game->font, 10, 58, 12, 20, str);
																
	SDL_RenderPresent(game->renderer);
}
