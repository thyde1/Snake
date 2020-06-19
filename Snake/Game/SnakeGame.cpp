#include "../Engine/Game.h"
#include "../Engine/GameCollider.h"
#include "../Engine/Collider.h"
#include "SnakeGame.h"
#include "SnakeRenderer.h"
#include "SnakeData.h"
#include "Snake.h"
#include "FoodFactory.h"
#include "UiRenderer.h"

void SnakeGame::init() {
	SnakeData *snakeData = new SnakeData();
	int *score = new int;
	*score = 0;

	Size worldSize = { this->windowSize.w, this->windowSize.h - 100 };
	this->instantiateObject()
		->setGlobalPosition(400, 300)
		->addComponent(snakeData)
		->addCollider(ColliderType::ACTIVE, new Collider(10, 10))
		->addUpdater(new Snake(snakeData, worldSize, score))
		->addRenderer(new SnakeRenderer(snakeData));

	auto foodFactory = new FoodFactory(worldSize);
	foodFactory->create(this->instantiateObject());

	this->instantiateObject()->addRenderer(new UiRenderer(Position(0, 500), { 800, 100 }, score));
}
