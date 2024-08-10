#include "colour.h"

SDL_Color colour_to_sdl(int colour) {
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
