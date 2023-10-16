#ifndef ANIMATION_TABLE_H_INCLUDE
#define ANIMATION_TABLE_H_INCLUDE

#include <stdbool.h>
#include <SDL2/SDL.h>
#include "types.h"

unsigned int hash(char* name);

bool init_animation_table(struct Sprite* sprite);

bool animation_table_insert(struct Sprite* sprite, struct Animation* animation);

struct Animation* animation_table_lookup(struct Sprite* sprite, char* name);

#endif
