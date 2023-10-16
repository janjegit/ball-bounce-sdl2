#include "update.h"

void update(struct InputState* input, struct GameState* game) {

	updateObjMovement(input, game, game->head);

}

void updateObjMovement(struct InputState* input, 
											 struct GameState* game, 
											 struct GameObj* head) {
											 
	struct GameObj* current = head;
	
	while(current != NULL) {
				
		struct Vector thrust = {1, 1};	
		if(input->up && !input->down) {
			applyForce(current, 0, -thrust.y);
		}
		if(!input->up && input->down) {
			applyForce(current, 0, thrust.y);
		}
		if(input->left && !input->right) {
			applyForce(current, -thrust.x, 0);
		}
		if(!input->left && input->right) {
			applyForce(current, thrust.x, 0);
		}
		
		applyForce(current, 0.0, 0.7);
		acclerate(current);
		clearAccleration(current);
		move(current);

		//Check ball hitting bottom boundry
		if(current->h + current->pos.y >= game->window_h) {
			setPos(current, current->pos.x, game->window_h - current->w);
			current->vel.y *= -0.8;
			current->vel.x *= 0.8;
		}
		
		//Check ball hitting upper boundry
		if(current->pos.y <= 0.0) {
			setPos(current, current->pos.x, 0.0);
			current->vel.y *= -0.8;
			current->vel.x *= 0.8;
		}
		
		//Check ball hitting right boundry	
		if(current->w + current->pos.x >= game->window_w) {
			setPos(current, game->window_w - current->w, current->pos.y);
			current->vel.x *= -0.8;
		}
		
		//Check ball hitting left boundry	
		if(current->pos.x <= 0.0) {
			setPos(current, 0.0, current->pos.y);
			current->vel.x *= -0.8;
		
		}
		
		current = current->next;
	}	
}
