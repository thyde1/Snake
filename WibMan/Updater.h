#pragma once
#include <list>
#include "Keys.h"
#include "SDL.h"

class GameObject;

class Updater {
public:
	void setGameObject(GameObject* gameObject);
	virtual void handleInput(std::list<SDL_Keysym> keys);
	virtual void update() = 0;

protected:
	GameObject* gameObject;
};
