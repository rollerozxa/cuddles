#include "screen.h"
#include "consts.h"
#include "font.h"
#include "scene.h"

Cell screen[CELLS_X][CELLS_Y];

void screen_init(void) {
	for (size_t x = 0; x < CELLS_X; x++) {
		for (size_t y = 0; y < CELLS_Y; y++) {
			Cell cell = {
				CLR_BLACK,
				CLR_WHITE,
				' '
			};
			screen[x][y] = cell;
		}
	}
}

void screen_print(int x, int y, const char* str) {
	for (size_t i = 0; str[i] != '\0'; i++) {
		screen[x+i%CELLS_X][y].character = str[i];
	}
}

void screen_printc(int x, int y, int fg, int bg, const char* str) {
	for (size_t i = 0; str[i] != '\0'; i++) {
		if (bg != -1)
			screen[x+i%CELLS_X][y].bg_col = bg;

		if (fg != -1)
			screen[x+i%CELLS_X][y].fg_col = fg;

		screen[x+i%CELLS_X][y].character = str[i];
	}
}

void screen_clear(enum CuddlesColours bg) {
	for (size_t x = 0; x < CELLS_X; x++) {
		for (size_t y = 0; y < CELLS_Y; y++) {
			screen[x][y].bg_col = bg;
		}
	}
}

void screen_update(void) {
	run_scene_update();
}

void screen_draw(SDL_Renderer *renderer) {

	SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0xFF, 0xFF);

	for (size_t x = 0; x < CELLS_X; x++) {
		for (size_t y = 0; y < CELLS_Y; y++) {
			Cell cell = screen[x][y];

			SDL_Color bg_col = colour_to_sdl(cell.bg_col);

			SDL_SetRenderDrawColor(renderer, bg_col.r, bg_col.g, bg_col.b, 255);
			SDL_RenderFillRect(renderer, RECT(GLYPH_WIDTH*x, GLYPH_HEIGHT*y, GLYPH_WIDTH, GLYPH_HEIGHT));

			if (cell.character != ' ') {
				SDL_Color fg_col = colour_to_sdl(cell.fg_col);
				draw_char(renderer, screen[x][y].character, x*GLYPH_WIDTH, y*GLYPH_HEIGHT, fg_col);
			}
		}
	}

	run_scene_draw(renderer);
}
