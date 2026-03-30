#include "render.h"
#include <stddef.h>

bool render_line(float x1, float y1, float x2, float y2) {
	return SDL_RenderLine(renderer, x1, y1, x2, y2);
}

bool render_rect(const SDL_FRect *rect) {
	return SDL_RenderRect(renderer,rect);
}

bool render_fill_rect(const SDL_FRect *rect) {
	return SDL_RenderFillRect(renderer,rect);
}

bool render_texture(SDL_Texture *texture, const SDL_FRect *src, const SDL_FRect *dst) {
	return SDL_RenderTexture(renderer, texture, src, dst);
}

/**
 * Convenience function for the most common used form of alpha blending.
 */
void render_set_blend(bool blend) {
	SDL_SetRenderDrawBlendMode(renderer, blend ? SDL_BLENDMODE_BLEND : SDL_BLENDMODE_NONE);
}

void render_set_color(unsigned int color) {
	SDL_SetRenderDrawColor(renderer,
		(color >> 16) & 0xFF,
		(color >> 8)  & 0xFF,
		color & 0xFF,
		SDL_ALPHA_OPAQUE);
}

void render_set_color_alpha(unsigned int color) {
	SDL_SetRenderDrawColor(renderer,
		(color >> 24) & 0xFF,
		(color >> 16) & 0xFF,
		(color >> 8)  & 0xFF,
		color & 0xFF);
}

void render_set_alpha(unsigned char alpha) {
	SDL_Color color;
	SDL_GetRenderDrawColor(renderer, &color.r, &color.g, &color.b, &color.a);
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, alpha);
}
