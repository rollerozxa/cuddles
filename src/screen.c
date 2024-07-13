#include "screen.h"

void screen_update(void) {

}

void screen_draw(SDL_Renderer *renderer) {
	SDL_SetRenderDrawColor(renderer, 0x22, 0x22, 0xFF, 0xFF);
	SDL_RenderFillRect(renderer, &(SDL_Rect){0,0,100,100});
}
