#include "scenes.h"
#include "scene.h"

extern Scene game_scene;

void scenes_register(void) {
	scene_add(game_scene);

	scene_switch_instant("game");
}
