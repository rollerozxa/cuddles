#include "draw.h"
#include "screen.h"

SDL_Color color_to_sdl(int colour) {
	switch (colour) {
		case CLR_BLACK:         return (SDL_Color){  0,  0,  0};
		case CLR_BLUE:          return (SDL_Color){  0,  0,170};
		case CLR_GREEN:         return (SDL_Color){  0,170,  0};
		case CLR_CYAN:          return (SDL_Color){  0,170,170};
		case CLR_RED:           return (SDL_Color){170,  0,  0};
		case CLR_MAGENTA:       return (SDL_Color){170,  0,170};
		case CLR_BROWN:         return (SDL_Color){170, 85,  0};
		case CLR_WHITE:         return (SDL_Color){170,170,170};
		case CLR_GREY:          return (SDL_Color){ 85, 85, 85};
		case CLR_LIGHT_BLUE:    return (SDL_Color){ 85, 85,255};
		case CLR_LIGHT_GREEN:   return (SDL_Color){ 85,255, 85};
		case CLR_LIGHT_CYAN:    return (SDL_Color){ 85,255,255};
		case CLR_LIGHT_RED:     return (SDL_Color){255, 85, 85};
		case CLR_LIGHT_MAGENTA: return (SDL_Color){255, 85,255};
		case CLR_YELLOW:        return (SDL_Color){255,255, 85};
		case CLR_BRIGHT_WHITE:  return (SDL_Color){255,255,255};
		default:                return (SDL_Color){0,0,0};
	}
}

	// helper macro to set a cell if inside bounds
#define SET_CELL(cx, cy, ch) do { \
    if ((cx) >= 0 && (cx) < (int)CELLS_X && (cy) >= 0 && (cy) < (int)CELLS_Y) { \
        if ((fg) != -1) screen[(cx)][(cy)].fg_col = (fg); \
        screen[(cx)][(cy)].character = (ch); \
    } \
} while (0)

void screen_print_rectangle(int x, int y, int w, int h, int fg) {
	if (w <= 0 || h <= 0)
		return;

	int x0 = x;
	int x1 = x + w - 1;
	int y0 = y;
	int y1 = y + h - 1;

	// Corners
	SET_CELL(x0, y0, CH_ULCORNER[0]);
	SET_CELL(x1, y0, CH_URCORNER[0]);
	SET_CELL(x0, y1, CH_LLCORNER[0]);
	SET_CELL(x1, y1, CH_LRCORNER[0]);

	// Top and bottom horizontal lines
	for (int i = x0 + 1; i <= x1 - 1; ++i) {
		SET_CELL(i, y0, CH_HLINE[0]);
		SET_CELL(i, y1, CH_HLINE[0]);
	}

	// Left and right vertical lines
	for (int j = y0 + 1; j <= y1 - 1; ++j) {
		SET_CELL(x0, j, CH_VLINE[0]);
		SET_CELL(x1, j, CH_VLINE[0]);
	}
}

void screen_print_double_rectangle(int x, int y, int w, int h, int fg) {
	if (w <= 0 || h <= 0)
		return;

	int x0 = x;
	int x1 = x + w - 1;
	int y0 = y;
	int y1 = y + h - 1;

	// Corners
	SET_CELL(x0, y0, CH_DBL_ULCORNER[0]);
	SET_CELL(x1, y0, CH_DBL_URCORNER[0]);
	SET_CELL(x0, y1, CH_DBL_LLCORNER[0]);
	SET_CELL(x1, y1, CH_DBL_LRCORNER[0]);

	// Top and bottom horizontal lines
	for (int i = x0 + 1; i <= x1 - 1; ++i) {
		SET_CELL(i, y0, CH_DBL_HLINE[0]);
		SET_CELL(i, y1, CH_DBL_HLINE[0]);
	}

	// Left and right vertical lines
	for (int j = y0 + 1; j <= y1 - 1; ++j) {
		SET_CELL(x0, j, CH_DBL_VLINE[0]);
		SET_CELL(x1, j, CH_DBL_VLINE[0]);
	}
}
