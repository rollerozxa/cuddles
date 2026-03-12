#include "app.h"
#include "consts.h"
#include <SDL3/SDL.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

#define SDL_MAIN_USE_CALLBACKS
#include <SDL3/SDL_main.h>

SDL_Window *window;
SDL_Renderer *renderer;

SDL_AppResult SDL_AppInit(void **rustptr, int argc, char **argv) {

	SDL_Init(SDL_INIT_VIDEO);

	SDL_WindowFlags windowflags = 0;

	SDL_CreateWindowAndRenderer(
		APP_NAME,
		WINDOW_W, WINDOW_H,
		windowflags, &window, &renderer);

	if (!window || !renderer) {
		char msg[1024];
		snprintf(msg, 1023, "Failed to start the game. Error: %s", SDL_GetError());
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Game", msg, NULL);
		return SDL_APP_FAILURE;
	}

	SDL_SetRenderLogicalPresentation(renderer, SCREEN_W, SCREEN_H, SDL_LOGICAL_PRESENTATION_LETTERBOX);

	SDL_SetRenderVSync(renderer, 1);

	AppInit(window, renderer);

	return SDL_APP_CONTINUE;
}


SDL_AppResult SDL_AppEvent(void *rustptr, SDL_Event *ev) {

	if (ev->type == SDL_EVENT_QUIT
	|| (ev->type == SDL_EVENT_KEY_DOWN && ev->key.scancode == SDL_SCANCODE_Q
		&& (ev->key.mod & SDL_KMOD_CTRL) && (ev->key.mod & SDL_KMOD_SHIFT))) {
		AppQuit();
		return SDL_APP_CONTINUE;
	}

	SDL_ConvertEventToRenderCoordinates(renderer, ev);

	AppEvent(ev);

	return SDL_APP_CONTINUE;
}

extern bool exiting;

SDL_AppResult SDL_AppIterate(void *rustptr) {
	AppUpdate();

	if (exiting)
		return SDL_APP_SUCCESS;

	AppDraw(renderer);

	SDL_RenderPresent(renderer);

	return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void *rustptr, SDL_AppResult result) {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	SDL_Quit();
}
