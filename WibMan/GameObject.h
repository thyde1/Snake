#pragma once
#include "SDL.h"
#include "Position.h"
#include <list>

class Updater;
class Renderer;
class InputHandler;

class GameObject {
public:
	GameObject(SDL_Renderer* renderer);
	void update(int elapsed);
	void handleInput(std::list<SDL_Keysym> keys);
	void render();
	GameObject* addUpdater(Updater* updater);
	GameObject* addRenderer(Renderer* renderer);
	Position* globalPosition;
private:
	SDL_Renderer* sdlRenderer;
	std::list<Updater*> updaters;
	std::list<Renderer*> renderers;
	std::list<InputHandler*> inputHandlers;
};
