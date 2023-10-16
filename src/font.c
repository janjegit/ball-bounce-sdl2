#include "font.h"

void loadFont(char* texturePath, int charColmns, int charRows, int charWidth, int charHeight, struct GameState* game) {

	struct Font* font = (struct Font*) malloc(sizeof(struct Font));
	
	if(texturePath != NULL) {
		char path[50];
		memset(path, '\0', sizeof(path));
		strncpy(path, texturePath, 49);
		font->texture = loadTexture(path, game->renderer);
		
		SDL_Rect dest;
		SDL_QueryTexture(font->texture, NULL, NULL, &dest.w, &dest.h);
		
		int index = 0;
		for(int i = 0; i < charRows; ++i) {
			for(int j = 0; j < charColmns; ++j) {
				font->clips[index].x = (dest.w / charColmns) * j;
				font->clips[index].y = (dest.h / charRows) * i;
				font->clips[index].w = charWidth;
				font->clips[index].h = charHeight;
				++index;
			}
		}
				
		game->font = font;
		font->renderer = game->renderer;
	} else {
		printf("Font bitmap could not be loaded.");
	}	
}

SDL_Rect getCharacterClip(struct Font* font, char c) {
	if(c >= ' ' && c <= '_') {
 	return font->clips[c - 32];
	} else {
	return font->clips[0];
	}
}
