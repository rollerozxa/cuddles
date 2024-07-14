#pragma once

#include <SDL2/SDL.h>

typedef struct {
	SDL_Color bg_col;
	SDL_Color fg_col;
	char character;
} Cell;

void screen_init(void);
void screen_update(void);
void screen_draw(SDL_Renderer *renderer);
