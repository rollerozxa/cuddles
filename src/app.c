#include "app.h"
#include "game.h"
#include "scene.h"
#include "screen.h"

bool exiting = false;

void AppInit(SDL_Window *window, SDL_Renderer *renderer) {

	add_scene((Scene){"game", game_update, game_draw});

	screen_init();
}

void AppEvent(SDL_Event *ev) {

}

void AppUpdate(void) {

	run_scene_update();

	screen_update();
}

void AppDraw(SDL_Renderer *renderer) {

	SDL_SetRenderDrawColor(renderer, 0x11, 0x11, 0x11, 0xFF);

	SDL_RenderClear(renderer);

	screen_draw(renderer);

	run_scene_draw(renderer);
}

void AppQuit(void) {
	exiting = true;
}
