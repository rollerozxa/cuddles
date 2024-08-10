#pragma once

#include "colour.h"
#include <SDL2/SDL.h>

typedef struct {
	int bg_col;
	int fg_col;
	char character;
} Cell;

void screen_init(void);

void screen_print(int x, int y, const char* str);
void screen_printc(int x, int y, int fg, int bg, const char* str);

void screen_clear(enum CuddlesColours bg);

void screen_update(void);
void screen_draw(SDL_Renderer *renderer);
