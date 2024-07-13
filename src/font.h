#pragma once

#include <SDL2/SDL.h>

SDL_Texture* load_font(SDL_Renderer *renderer);

void draw_char(SDL_Renderer *renderer, char character, int cx, int cy);
void draw_text(SDL_Renderer *renderer, const char* text, int x, int y);
