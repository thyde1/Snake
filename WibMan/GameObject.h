#pragma once
#include "SDL.h"
#include "Position.h"
#include <list>

class Updater;
class Renderer;
class Component;

class GameObject {
public:
	GameObject(SDL_Renderer* renderer);
	void update(int elapsed);
	void handleInput(std::list<SDL_Keysym> keys);
	void render();
	GameObject* addUpdater(Updater* updater);
	GameObject* addRenderer(Renderer* renderer);
	GameObject* addComponent(Component* component);
	template <class T>
	T getComponent()
	{
		for (auto component : this->components)
		{
			T castComponent = dynamic_cast<T>(component);
			if (castComponent != NULL) {
				return castComponent;
			}
		}
	}
	Position* globalPosition;
private:
	SDL_Renderer* sdlRenderer;
	std::list<Updater*> updaters;
	std::list<Renderer*> renderers;
	std::list<Component*> components;
};
