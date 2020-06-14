#include "Game.h"
#include "SnakeGame.h"
#include "SnakeRenderer.h"
#include "PointRenderer.h"
#include "SquareRenderer.h"
#include "SnakeData.h"
#include "Snake.h"
#include "Food.h"
#include "GameCollider.h"
#include "Collider.h"

void SnakeGame::init() {
	SnakeData* snakeData = new SnakeData();

	this->instantiateObject()
		->setGlobalPosition(400, 300)
		->addComponent(snakeData)
		->addComponent(new Component())
		->addCollider(ColliderType::ACTIVE, new Collider(10, 10))
		->addUpdater(new Snake(snakeData))
		->addRenderer(new SnakeRenderer(snakeData));

	this->instantiateObject()
		->setGlobalPosition(100, 100)
		->addRenderer(new SquareRenderer())
		->addCollider(ColliderType::PASSIVE, new Collider(10, 10))
		->addUpdater(new Food());
}
