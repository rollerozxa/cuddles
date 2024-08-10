#pragma once

// Native resolution at which the game will be rendered
#define NATIVE_WIDTH    640
#define NATIVE_HEIGHT   320

// Size of the screen (scaled up/down from native res)
#define SCREEN_WIDTH    NATIVE_WIDTH*2
#define SCREEN_HEIGHT   NATIVE_HEIGHT*2

#define GLYPH_WIDTH 8
#define GLYPH_HEIGHT 16

#define CELLS_X (NATIVE_WIDTH/GLYPH_WIDTH)
#define CELLS_Y (NATIVE_HEIGHT/GLYPH_HEIGHT)

// Colours
#include "colour.h"

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

#define CH_BOX				"\xDB"
#define CH_LOWER_HALF_BOX	"\xDC"
#define CH_LEFT_HALF_BOX	"\xDD"
#define CH_RIGHT_HALF_BOX	"\xDE"
#define CH_UPPER_HALF_BOX	"\xDF"


// Max scenes to be allocated
#define MAX_SCENES 10


// Misc helper macros

#define RECT(x,y,w,h) &((SDL_Rect){x,y,w,h})
