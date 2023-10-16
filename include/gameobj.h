#ifndef GAMEOBJ_H_INCLUDE
#define GAMEOBJ_H_INCLUDE

#include "types.h"
#include "texture.h"

void move(struct GameObj* gObj);

void acclerate(struct GameObj* gObj);

void applyForce(struct GameObj* gObj, float fx, float fy);

void clearAccleration(struct GameObj* gObj);

void setPos(struct GameObj* gObj, float x, float y);

void setSize(struct GameObj* gObj, int w, int h);

struct GameObj* newGameObj(struct GameObj** headRef,
								char* name, 
								int w, 
								int h,
								float x,
								float y);
										
struct GameObj* findGameObj(struct GameObj* head, char* name);

#endif
