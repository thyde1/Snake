#pragma once

#include "SDL.h"
#include <stdio.h>
#include <list>
#include "GameObject.h"

class Game {
public:
	Game();
	~Game();
	void init();
	bool isRunning();
	void handleInput();
	void update();
	void render();
	GameObject* instantiateObject();

private:
	SDL_Renderer* renderer;
	std::list<GameObject*> gameObjects;
};
