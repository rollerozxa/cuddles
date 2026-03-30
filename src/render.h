#pragma once

#include <SDL3/SDL.h>
#include <stdbool.h>

extern SDL_Renderer *renderer;

bool render_line(float x1, float y1, float x2, float y2);
bool render_rect(const SDL_FRect *rect);
bool render_fill_rect(const SDL_FRect *rect);
bool render_texture(SDL_Texture *texture, const SDL_FRect *src, const SDL_FRect *dst);

void render_set_blend(bool blend);

void render_set_color(unsigned int color);
void render_set_color_alpha(unsigned int color);
void render_set_alpha(unsigned char alpha);
