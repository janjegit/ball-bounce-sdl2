#ifndef FONT_H_INCLUDE
#define FONT_H_INCLUDE

#include <stdio.h>
#include "types.h"
#include "texture.h"

void loadFont(char* texturePath, 
							int charColmns, 
							int charRows, 
							int charWidth, 
							int charHeight, 
							struct GameState* game);

SDL_Rect getCharacterClip(struct Font* font, char c);

#endif
