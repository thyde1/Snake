#pragma once
#include <list>
#include "SDL.h"
#include "Component.h"

class GameObject;

class Updater : public Component {
public:
	virtual void handleInput(std::list<SDL_Keysym> keys);
	virtual void update(int elapsed) = 0;
};
