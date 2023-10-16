#include "gameobj.h"

struct GameObj* newGameObj(struct GameObj** headRef,
								char* name, 
								int w, 
								int h,
								float x,
								float y) {
										
	struct GameObj* gObj = (struct GameObj*) malloc(sizeof(struct GameObj));
	
	memset(gObj->name, '\0', sizeof(gObj->name));
	strcpy(gObj->name, name);
	memset(gObj->status, '\0', sizeof(gObj->status));
	strcpy(gObj->status, "idle");
	gObj->w = w;
	gObj->h = h;
	gObj->pos.x = x;
	gObj->pos.y = y;
	gObj->vel.x = 0.0;
	gObj->vel.y = 0.0;
	gObj->acc.x = 0.0;
	gObj->acc.y = 0.0;
	
	gObj->sprite = NULL;
	
	printf("Game object '%s' loaded.\n", gObj->name);
	
	gObj->next = *headRef;
	*headRef = gObj;
	
	return gObj;
}

struct GameObj* findGameObj(struct GameObj* head, char* name) {
	
	struct GameObj* current = head;
	
	while(current != NULL) {
		if(strcmp(name, current->name) == 0) 
			break;
		current = current->next;
	}
	
	return current;
}

void move(struct GameObj* gObj) {
	gObj->pos.x += gObj->vel.x;
	gObj->pos.y += gObj->vel.y;
}

void acclerate(struct GameObj* gObj) {
	gObj->vel.x += gObj->acc.x;
	gObj->vel.y += gObj->acc.y;
}

void applyForce(struct GameObj* gObj, float fx, float fy) {
	gObj->acc.x += fx;
	gObj->acc.y += fy;
}

void clearAccleration(struct GameObj* gObj) {
	gObj->acc.x = 0.0;
	gObj->acc.y = 0.0;	
}

void setPos(struct GameObj* gObj, float x, float y) {
	gObj->pos.x = x;
	gObj->pos.y = y;
}

void setSize(struct GameObj* gObj, int w, int h) {
	gObj->w = w;
	gObj->h = h;
}
