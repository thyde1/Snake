#include <iostream>
#include "Food.h"
#include "Collider.h"
#include "Game.h"
#include "GameObject.h"
#include "SquareRenderer.h"
#include "GameCollider.h"

void Food::handleCollision(Collider* collider)
{
	std::cout << "Collision!";
	this->gameObject->game->destroyObject(this->gameObject);

	auto newX = rand() % 800;
	auto newY = rand() % 600;

	this->gameObject->game
		->instantiateObject()
		->setGlobalPosition(newX, newY)
		->addRenderer(new SquareRenderer())
		->addCollider(ColliderType::PASSIVE, new Collider(10, 10))
		->addUpdater(new Food());
}
