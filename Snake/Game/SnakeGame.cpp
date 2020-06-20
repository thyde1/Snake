#include "../Engine/Game.h"
#include "../Engine/GameCollider.h"
#include "../Engine/Collider.h"
#include "SnakeGame.h"
#include "SnakeRenderer.h"
#include "SnakeData.h"
#include "Snake.h"
#include "FoodFactory.h"
#include "UiRenderer.h"

SnakeGame::SnakeGame(Size windowSize) : Game(windowSize), worldSize({ windowSize.w, windowSize.h - 100 }), foodFactory(FoodFactory(worldSize))
{
}

void SnakeGame::init() {
	SnakeData *snakeData = new SnakeData();
	int *score = new int;
	*score = 0;

	this->instantiateObject()
		->setGlobalPosition(400, 300)
		->addComponent(snakeData)
		->addCollider(ColliderType::ACTIVE, new Collider(10, 10))
		->addUpdater(new Snake(snakeData, worldSize, score))
		->addRenderer(new SnakeRenderer(snakeData));

	auto foodFactory = new FoodFactory(worldSize);
	foodFactory->create(this->instantiateObject());

	Size uiHeight = { this->windowSize.w, this->windowSize.h - this->worldSize.h };
	Position uiPosition = Position(0, this->worldSize.h);
	this->instantiateObject()->addRenderer(new UiRenderer(uiPosition, uiHeight, score));
}
