#include "texture.h"

SDL_Texture* loadTexture(char* path, SDL_Renderer* renderer) {
	SDL_Texture* newTexture = NULL;
	
	SDL_Surface* loadedSurface = IMG_Load(path);
	if(loadedSurface == NULL) {
		printf("Unable to load image %s. SDL_Image Error: %s\n", path, IMG_GetError());
	} else {
		
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

		newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		if (newTexture == NULL) {
			printf("Unable to create texture from %s! SDL Error: %s\n", path, SDL_GetError());	
		} 
		
		SDL_FreeSurface(loadedSurface);
	}
	
	return newTexture;
}
