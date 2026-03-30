#pragma once

// Native resolution at which the game will be rendered
#define SCREEN_W    1280
#define SCREEN_H   720

// Size of the screen (scaled up/down from native res)
#define WINDOW_W    SCREEN_W
#define WINDOW_H   SCREEN_H

// Shared constant for app name
#define APP_NAME "thingy"
// Shared constant for app ID
#define APP_ID "se.voxelmanip.thingy"
// Shared constant for app "org"
#define APP_ORG "ROllerozxa"

#define GLYPH_WIDTH 8
#define GLYPH_HEIGHT 16

#define CELLS_X (SCREEN_W/GLYPH_WIDTH)
#define CELLS_Y (SCREEN_H/GLYPH_HEIGHT)

// Misc helper macros

#define RECTCPY(rect) {rect.x, rect.y, rect.w, rect.h}

#define RECT(x,y,w,h) ((SDL_FRect){x,y,w,h})
#define POINT(x,y) ((SDL_FPoint){x,y})

#define FULL_RECT() RECT(0, 0, SCREEN_W, SCREEN_H)

#define CENTER(outside, inside) ((outside - inside) / 2)

#define FMT_STRING(buf, size, fmt, ...) \
	char (buf)[(size)]; \
	snprintf((buf), (size), (fmt), ##__VA_ARGS__)

#define STR(x) SDL_STRINGIFY_ARG(x)
