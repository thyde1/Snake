#include "Game.h"
#include "SnakeGame.h"
#include "SquareRenderer.h"
#include "PointRenderer.h"
#include "SnakeData.h"
#include "Player.h"

void SnakeGame::init() {
	SnakeData* snakeData = new SnakeData();

	this->instantiateObject()
		->addComponent(snakeData)
		->addComponent(new Component())
		->addUpdater(new Player(snakeData))
		->addRenderer(new SquareRenderer())
		->addRenderer(new PointRenderer());
}
