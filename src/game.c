#include "consts.h"
#include "scene.h"
#include "screen.h"

void game_update(float dt) {

}

void game_draw(void) {
	screen_clear(CLR_BLUE);
	SDL_srand(10);

	screen_print_double_rectangle(10, 10, 20, 10, CLR_LIGHT_RED);
	for (size_t x = 11; x < 29; x++) {
		for (size_t y = 11; y < 19; y++) {
			screen_printc(x, y, -1, SDL_rand(16), " ");
		}
	}

	screen_printc(2, 2, CLR_BRIGHT_WHITE, -1, "roller and bl\x86haj sitting in a tree");
	screen_printc(2, 4, CLR_BRIGHT_WHITE, -1, "C-U-D-D-L-I-N-G" CH_BANGBANG " " CH_HAPPY " " CH_HEART " " CH_HAPPY);

	screen_print_rectangle(1, 1, 40, 5, CLR_YELLOW);

	screen_print_double_rectangle(0, 0, SCREEN_W / GLYPH_WIDTH, SCREEN_H / GLYPH_HEIGHT, CLR_YELLOW);
}

Scene game_scene = {
	"game",
	NULL,
	NULL,
	game_update,
	game_draw,
	0x000077
};
