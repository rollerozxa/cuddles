#pragma once

#include <SDL3/SDL.h>

// Constants for upper two rows of special ASCII symbols
#define CH_HAPPY		"\x01"
#define CH_HAPPY_FILLED	"\x02"
#define CH_HEART		"\x03"
#define CH_DIAMOND		"\x04"
#define CH_CLOVER		"\x05"
#define CH_SPADE		"\x06"
#define CH_DOT			"\x07"
#define CH_INV_DOT		"\x08"
#define CH_CIRCLE		"\x09"
#define CH_INV_CIRCLE	"\x0A"
#define CH_MALE			"\x0B"
#define CH_FEMALE		"\x0C"
#define CH_NOTE			"\x0D"
#define CH_NOTE_2		"\x0E"
#define CH_SUN			"\x0F"
#define CH_DIR_RIGHT	"\x10"
#define CH_DIR_LEFT		"\x11"
#define CH_SCALE		"\x12"
#define CH_BANGBANG		"\x13"
#define CH_PILCROW		"\x14"
#define CH_PARAGRAPH	"\x15"
#define CH_SOAPBOX		"\x16"
#define CH_FLOORSCALE	"\x17"
#define CH_ARROW_UP		"\x18"
#define CH_ARROW_DOWN	"\x19"
#define CH_ARROW_RIGHT	"\x1A"
#define CH_ARROW_LEFT	"\x1B"
#define CH_SMOL_L		"\x1C"
#define CH_DUMBBELL		"\x1D"
#define CH_UP_TRIANGLE	"\x1E"
#define CH_DOWN_TRIANGLE "\x1F"

#define CH_LIGHT_SHADE		"\xB0"
#define CH_MEDIUM_SHADE		"\xB1"
#define CH_DARK_SHADE		"\xB2"

// Box drawing characters
// Single-line
#define CH_ULCORNER      "\xDA" // ┌
#define CH_URCORNER      "\xBF" // ┐
#define CH_LLCORNER      "\xC0" // └
#define CH_LRCORNER      "\xD9" // ┘
#define CH_HLINE         "\xC4" // ─
#define CH_VLINE         "\xB3" // │
#define CH_TTEE_UP       "\xC2" // ┬
#define CH_TTEE_DOWN     "\xC1" // ┴
#define CH_TTEE_LEFT     "\xC3" // ├
#define CH_TTEE_RIGHT    "\xB4" // ┤
#define CH_CROSS         "\xC5" // ┼

// Double-line / heavy box drawing
#define CH_DBL_ULCORNER  "\xC9" // ╔
#define CH_DBL_URCORNER  "\xBB" // ╗
#define CH_DBL_LLCORNER  "\xC8" // ╚
#define CH_DBL_LRCORNER  "\xBC" // ╝
#define CH_DBL_HLINE     "\xCD" // ═
#define CH_DBL_VLINE     "\xBA" // ║
#define CH_DBL_LTEE      "\xCC" // ╠
#define CH_DBL_RTEE      "\xB9" // ╣
#define CH_DBL_TTEE      "\xCB" // ╦
#define CH_DBL_BTEE      "\xCA" // ╩
#define CH_DBL_CROSS     "\xCE" // ╬


#define CH_BOX				"\xDB"
#define CH_LOWER_HALF_BOX	"\xDC"
#define CH_LEFT_HALF_BOX	"\xDD"
#define CH_RIGHT_HALF_BOX	"\xDE"
#define CH_UPPER_HALF_BOX	"\xDF"

enum CuddlesColours {
	CLR_BLACK,
	CLR_BLUE,
	CLR_GREEN,
	CLR_CYAN,
	CLR_RED,
	CLR_MAGENTA,
	CLR_BROWN,
	CLR_WHITE,
	CLR_GREY,
	CLR_LIGHT_BLUE,
	CLR_LIGHT_GREEN,
	CLR_LIGHT_CYAN,
	CLR_LIGHT_RED,
	CLR_LIGHT_MAGENTA,
	CLR_YELLOW,
	CLR_BRIGHT_WHITE
};

SDL_Color color_to_sdl(int colour);

void screen_print_rectangle(int x, int y, int w, int h, int fg);
void screen_print_double_rectangle(int x, int y, int w, int h, int fg);
