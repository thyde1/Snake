#include "../Engine/Collider.h"
#include "../Engine/Game.h"
#include "../Engine/GameObject.h"
#include "../Engine/GameCollider.h"
#include "Food.h"
#include "FoodRenderer.h"

void Food::handleCollision(Collider* collider)
{
	this->gameObject->game->destroyObject(this->gameObject);

	auto newX = rand() % 800;
	auto newY = rand() % 600;
	this->gameObject->game
		->instantiateObject()
		->setGlobalPosition(newX, newY)
		->addRenderer(new FoodRenderer())
		->addCollider(ColliderType::PASSIVE, new Collider(10, 10))
		->addUpdater(new Food());
}
