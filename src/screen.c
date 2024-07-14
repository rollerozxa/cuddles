#include "screen.h"
#include "consts.h"
#include "font.h"

Cell screen[CELLS_X][CELLS_Y];

void screen_init(void) {
	for (size_t x = 0; x < CELLS_X; x++) {
		for (size_t y = 0; y < CELLS_Y; y++) {
			Cell cell = {
				(SDL_Color){0,0,0,255},
				(SDL_Color){255,255,255,255},
				' '
			};
			screen[x][y] = cell;
		}
	}
}

int screen_print(int x, int y, const char* str) {
	for (size_t i = 0; str[i] != '\0'; i++) {
		screen[x+i%CELLS_X][y].character = str[i];

	}

	return 0;
}

void screen_update(void) {
	screen_print(2, 2, "roller and kittynunu sitting in a tree");
	screen_print(2, 4, "C-U-D-D-L-I-N-G" CH_BANGBANG " " CH_HAPPY " " CH_HEART " " CH_HAPPY);
}

void screen_draw(SDL_Renderer *renderer) {

	SDL_SetRenderDrawColor(renderer, 0x11, 0x11, 0x66, 0xFF);

	SDL_RenderFillRect(renderer, RECT(0, 0, NATIVE_WIDTH, NATIVE_HEIGHT));

	SDL_SetRenderDrawColor(renderer, 0x22, 0x22, 0xDD, 0xFF);
	for (size_t x = 0; x < 60; x++) {
		for (size_t y = 0; y < 60; y++) {
			SDL_RenderFillRect(renderer, RECT(16*x, 32*y, 8, 16));
			SDL_RenderFillRect(renderer, RECT(16*x+8, 32*y+16, 8, 16));
		}
	}

	//draw_char(renderer, 'O', 400, 400);
	//draw_text(renderer, "cuddles with kittynunu " CH_BANGBANG " " CH_HEART CH_HAPPY, 0, 0);

	for (size_t x = 0; x < CELLS_X; x++) {
		for (size_t y = 0; y < CELLS_Y; y++) {
			draw_char(renderer, screen[x][y].character, x*GLYPH_WIDTH, y*GLYPH_HEIGHT);
		}
	}
}
