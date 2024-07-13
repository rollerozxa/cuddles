#include "game.h"

void game_update(void) {

}

void game_draw(SDL_Renderer *renderer) {
	SDL_SetRenderDrawColor(renderer, 0xAA, 0x22, 0x22, 0xFF);
	SDL_RenderFillRect(renderer, &(SDL_Rect){0,0,100,100});
}
