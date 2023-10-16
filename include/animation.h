#ifndef ANIMATION_H_INCLUDE
#define ANIMATION_H_INCLUDE

#include <SDL2/SDL.h>
#include "types.h"
#include "animation_table.h"

void newAnimation(char* name, struct Sprite* sprite, int numOfClips, int starting_row);

#endif
