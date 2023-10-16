#ifndef CLEANUP_H_INCLUDE
#define CLEANUP_H_INCLUDE

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "types.h"

void cleanupWindow(SDL_Window* window);

void cleanupRenderer(SDL_Renderer* renderer);

void cleanupTexture(SDL_Texture* texture);

void cleanupAllGameObjects(struct GameObj* head);

void cleanupAnimations(struct Sprite* sprite);

#endif
