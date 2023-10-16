#ifndef UPDATE_H_INCLUDE
#define UPDATE_H_INCLUDE

#include "types.h"
#include "gameobj.h"

void update(struct InputState* input, struct GameState* game);

void updateObjMovement(struct InputState* input, 
											 struct GameState* game, 
											 struct GameObj* head);

#endif
