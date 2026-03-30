#include "app.h"
#include "scene.h"
#include "scenes.h"
#include "screen.h"

bool exiting = false;

void AppInit(SDL_Window *window, SDL_Renderer *renderer) {
	scenes_register();

	screen_init();
}

void AppEvent(SDL_Event *ev) {
	scene_run_event(ev);
}

void AppUpdate(void) {

	static uint64_t last_time = 0;
	if (last_time == 0)
		last_time = SDL_GetTicksNS();

	uint64_t now = SDL_GetTicksNS();
	float dt = (now - last_time) / 1e9f;
	last_time = now;

	scene_run_update(dt);

	screen_update();
}

void AppDraw(SDL_Renderer *renderer) {

	SDL_SetRenderDrawColor(renderer, 0x11, 0x11, 0x11, 0xFF);

	SDL_RenderClear(renderer);

	scene_run_draw();

	screen_draw(renderer);
}

void AppQuit(void) {
	exiting = true;
}
