#include "font.h"
#include "font_bitmap.h"
#include "consts.h"

SDL_Texture* font_tex;

SDL_Texture* load_font(SDL_Renderer *renderer) {
	SDL_Surface *surface = SDL_CreateRGBSurface(0, FONT_WIDTH, FONT_HEIGHT, 32,
	0x00FF0000, 0x0000FF00, 0x000000FF, 0xFF000000);

	Uint32 white = SDL_MapRGB(surface->format, 255, 255, 255);
	Uint32 black = SDL_MapRGBA(surface->format, 0, 0, 0, 0);

	for (int y = 0; y < FONT_HEIGHT; ++y) {
		for (int x = 0; x < FONT_WIDTH; ++x) {
			Uint32 color = font_bitmap[y][x] ? white : black;
			((Uint32 *)surface->pixels)[y * FONT_WIDTH + x] = color;
		}
	}

	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);

	return texture;
}

#define FGRID_WIDTH (FONT_WIDTH/GLYPH_WIDTH)
#define FGRID_HEIGHT (FONT_HEIGHT/GLYPH_HEIGHT)

void draw_char(SDL_Renderer *renderer, char character, int cx, int cy) {
	int cell_x = character % FGRID_WIDTH;
	int cell_y = character / FGRID_WIDTH;

	if (font_tex == NULL) {
		font_tex = load_font(renderer);
	}

	SDL_RenderCopy(
		renderer, font_tex,
		RECT(cell_x*GLYPH_WIDTH, cell_y*GLYPH_HEIGHT, GLYPH_WIDTH, GLYPH_HEIGHT),
		RECT(cx, cy, GLYPH_WIDTH, GLYPH_HEIGHT)
	);
}

void draw_text(SDL_Renderer *renderer, const char* text, int x, int y) {
	for (size_t i = 0; text[i] != '\0'; i++) {
		draw_char(renderer, text[i], x+i*GLYPH_WIDTH, y);
	}
}
