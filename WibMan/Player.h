#pragma once
#include <string>
#include "GameObject.h"
#include "Updater.h"
#include "Renderer.h"
#include "Direction.h"

class Player : public Updater {
public:
	void update(int elapsed);
	void handleInput(std::list<SDL_Keysym> keys);
	std::string myThing;
private:
	Direction direction;
};
