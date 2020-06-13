#pragma once
#include "SDL.h"
#include "Position.h"
#include <list>

class Updater;
class InputHandler;

class GameObject {
public:
	GameObject(SDL_Renderer* renderer);
	void update();
	void handleInput(std::list<SDL_Keysym> keys);
	void render();
	GameObject* addUpdater(Updater* updater);
	Position* globalPosition;
private:
	SDL_Renderer* renderer;
	std::list<Updater*> updaters;
	std::list<InputHandler*> inputHandlers;
};
