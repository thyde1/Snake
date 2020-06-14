#include "Game.h"
#include "SnakeGame.h"
#include "SnakeRenderer.h"
#include "PointRenderer.h"
#include "SnakeData.h"
#include "Snake.h"

void SnakeGame::init() {
	SnakeData* snakeData = new SnakeData();

	this->instantiateObject()
		->setGlobalPosition(400, 300)
		->addComponent(snakeData)
		->addComponent(new Component())
		->addUpdater(new Snake(snakeData))
		->addRenderer(new SnakeRenderer(snakeData));
}
