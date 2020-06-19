#pragma once
#include "../Engine/GameObject.h"
#include "../Engine/Updater.h"
#include "../Engine/Renderer.h"
#include "../Engine/Size.h"

class SnakeData;

class Snake : public Updater {
public:
	Snake(SnakeData* snakeData, const Size worldSize, int *score);
	void init();
	void update(int elapsed);
	void handleInput(std::list<SDL_Keysym> keys);
	void handleCollision(Collider* collider);
	SnakeData* snakeData;
private:
	bool checkSelfCollision();
	bool checkOutOfBounds();
	bool checkCollision(Position* position);
	Size worldSize;
	int *score;
};
