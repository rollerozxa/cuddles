#include "screen.h"
#include "consts.h"
#include "font.h"

void screen_update(void) {

}

void screen_draw(SDL_Renderer *renderer) {
	SDL_SetRenderDrawColor(renderer, 0x22, 0x22, 0xFF, 0xFF);
	for (size_t x = 0; x < 60; x++) {
		for (size_t y = 0; y < 60; y++) {
			SDL_RenderFillRect(renderer, RECT(16*x, 32*y, 8, 16));
			SDL_RenderFillRect(renderer, RECT(16*x+8, 32*y+16, 8, 16));
		}
	}

	//draw_char(renderer, 'O', 400, 400);
	draw_text(renderer, "cuddles with kittynunu " CH_BANGBANG " " CH_HEART CH_HAPPY, 0, 0);
}
