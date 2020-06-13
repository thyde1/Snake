#pragma once
#include "GameObject.h"
#include "Updater.h"
#include "Direction.h"

class Player : public Updater {
public:
	void update();
	void handleInput(std::list<SDL_Keysym> keys);
private:
	Direction direction;
};
