#pragma once

#include <SDL2/SDL.h>

typedef struct {
	const char* name;
    void (*update)(void);
	void (*draw)(SDL_Renderer*);
} Scene;

int add_scene(Scene scene);

int switch_scene(const char* name);

void run_scene_update(void);
void run_scene_draw(SDL_Renderer *renderer);
