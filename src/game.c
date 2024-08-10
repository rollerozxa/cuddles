#include "game.h"
#include "consts.h"
#include "screen.h"

void game_update(void) {
	screen_clear(CLR_BLUE);
	srand(10);

	for (size_t x = 0; x < 80; x++) {
		for (size_t y = 0; y < 20; y++) {
			screen_printc(x, y, -1, rand()%16, " ");
		}
	}

	screen_printc(2, 2, CLR_BRIGHT_WHITE, CLR_BLACK, "roller and kittynunu sitting in a tree");
	screen_printc(2, 4, CLR_BRIGHT_WHITE, CLR_BLACK, "C-U-D-D-L-I-N-G" CH_BANGBANG " " CH_HAPPY " " CH_HEART " " CH_HAPPY);
}

void game_draw(SDL_Renderer *renderer) {
	//SDL_SetRenderDrawColor(renderer, 0xAA, 0x22, 0x22, 0xFF);
	//SDL_RenderFillRect(renderer, &(SDL_Rect){0,0,100,100});
}
