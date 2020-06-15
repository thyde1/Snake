#pragma once
#include "GameObject.h"
#include "Updater.h"
#include "Renderer.h"
#include "Direction.h"

class SnakeData;

class Snake : public Updater {
public:
	Snake(SnakeData* snakeData);
	void init();
	void update(int elapsed);
	void handleInput(std::list<SDL_Keysym> keys);
	void handleCollision(Collider* collider);
	SnakeData* snakeData;
private:
	Direction direction;
	bool checkSelfCollision();
	bool checkCollision(Position* position);
};
