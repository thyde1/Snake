#pragma once

#include "SDL.h"
#include <stdio.h>
#include <list>
#include "GameObject.h"

class Game {
public:
	Game();
	~Game();
	void sdlInit();
	virtual void init() = 0;
	void start();
	bool isRunning();
	void handleInput();
	void update(int elapsed);
	void render();
	GameObject* instantiateObject();

private:
	SDL_Renderer* renderer;
	std::list<GameObject*> gameObjects;
	void clearScreen();
};
