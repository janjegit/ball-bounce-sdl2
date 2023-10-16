#include "animation_table.h"

unsigned int hash(char* name) {
	int len = strnlen(name, MAX_NAME);
	unsigned int hash_value = 0;
	
	for(int i = 0; i < len; ++i) {
		hash_value += name[i];
		hash_value = (hash_value * name[i]) % ANIMATION_TABLE_SIZE;
	}
	
	return hash_value;
}


bool init_animation_table(struct Sprite* sprite) {
	for(int i = 0; i < ANIMATION_TABLE_SIZE; ++i) {
		sprite->animation_table[i] = NULL;
	}
	
	return true;
}

bool animation_table_insert(struct Sprite* sprite, struct Animation* animation) {
	if(animation == NULL) return false;
	
	int index = hash(animation->name);
	animation->next = sprite->animation_table[index];
	sprite->animation_table[index] = animation;
	
	return true;
}

struct Animation* animation_table_lookup(struct Sprite* sprite, char* name) {
	int index = hash(name);
	struct Animation* tmp = sprite->animation_table[index];
	struct Animation* prev = NULL;
	while(tmp != NULL && strcmp(tmp->name, name) != 0) {
		prev = tmp;
		tmp = tmp->next;
	}
	
	return tmp;
}
