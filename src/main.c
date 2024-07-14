#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

#include "consts.h"
#include "game.h"
#include "screen.h"
#include "scene.h"

bool quit = false;

int main(int argc, char* argv[]) {

	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_CreateWindowAndRenderer(
		SCREEN_WIDTH, SCREEN_HEIGHT,
		0, &window, &renderer);

	if (!window || !renderer) {
		char msg[1024];
		snprintf(msg, 1023, "Failed to start the game. Error: %s", SDL_GetError());
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Game", msg, NULL);
	}

	SDL_RenderSetLogicalSize(renderer, NATIVE_WIDTH, NATIVE_HEIGHT);

	SDL_RenderSetVSync(renderer, 1);
	SDL_SetWindowTitle(window, "roller <3 kittynunu");

	add_scene((Scene){"screen", screen_update, screen_draw});
	add_scene((Scene){"game", game_update, game_draw});

	SDL_assert(switch_scene("game") == 1);
	SDL_assert(switch_scene("screen") == 1);

	screen_init();

	while (!quit) {
		SDL_Event ev;
		while (SDL_PollEvent(&ev)) {
			if (ev.type == SDL_QUIT || (ev.type == SDL_KEYDOWN && ev.key.keysym.scancode == SDL_SCANCODE_Q)) {
				quit = true;
				break;
			}
		}

		screen_update();

		SDL_SetRenderDrawColor(renderer, 0x11, 0x11, 0x11, 0xFF);

		SDL_RenderClear(renderer);

		screen_draw(renderer);

		SDL_RenderPresent(renderer);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	SDL_Quit();

	return 0;
}
