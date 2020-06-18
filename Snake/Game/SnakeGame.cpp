#include "../Engine/Game.h"
#include "../Engine/GameCollider.h"
#include "../Engine/Collider.h"
#include "SnakeGame.h"
#include "SnakeRenderer.h"
#include "SnakeData.h"
#include "Snake.h"
#include "Food.h"

void SnakeGame::init() {
	SnakeData* snakeData = new SnakeData();

	this->instantiateObject()
		->setGlobalPosition(400, 300)
		->addComponent(snakeData)
		->addCollider(ColliderType::ACTIVE, new Collider(10, 10))
		->addUpdater(new Snake(snakeData))
		->addRenderer(new SnakeRenderer(snakeData));

	Food::create(
		this->instantiateObject()->setGlobalPosition(100, 100)
	);
}
