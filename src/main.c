#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

#include "consts.h"
#include "game.h"
#include "screen.h"
#include "scene.h"

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

	SDL_RenderSetVSync(renderer, 1);
	SDL_SetWindowTitle(window, "roller <3 kittynunu");

	bool quit = false;

	add_scene((Scene){"screen", screen_update, screen_draw});
	add_scene((Scene){"game", game_update, game_draw});

	SDL_assert(switch_scene("game") == 1);
	SDL_assert(switch_scene("scene") == 1);

	while (!quit) {
		SDL_Event ev;
		while (SDL_PollEvent(&ev)) {
			switch (ev.type) {
				case SDL_QUIT:
					quit = true;
					break;
			}
		}

		run_scene_update();

		SDL_SetRenderDrawColor(renderer, 0xAA, 0xAA, 0xAA, 0xFF);

		SDL_RenderClear(renderer);

		run_scene_draw(renderer);

		SDL_RenderPresent(renderer);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	SDL_Quit();

	return 0;
}
