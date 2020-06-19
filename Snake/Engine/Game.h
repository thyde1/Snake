#pragma once

#include "SDL.h"
#include "SDL_TTF.h"
#include <stdio.h>
#include <list>
#include "GameObject.h"
#include "TextureManager.h"

struct WindowSize { int w; int h; };

class Game {
public:
	Game();
	~Game();
	TextureManager textureManager;
	WindowSize windowSize = { 800, 600 };
	void sdlInit();
	virtual void init() = 0;
	void start();
	bool isRunning();
	void handleInput();
	void update(int elapsed);
	void checkCollisions();
	void render();
	GameObject* instantiateObject();
	void destroyObject(GameObject* object);

private:
	SDL_Renderer* renderer;
	std::list<GameObject*> gameObjects;
	void clearScreen();
	std::list<GameObject*> gameObjectsPendingInstantiation;
	void instantiateGameObjectsPendingInstantiation();
	std::list<GameObject*> gameObjectsPendingDestruction;
	void destroyObjectsPendingDestruction();
};
