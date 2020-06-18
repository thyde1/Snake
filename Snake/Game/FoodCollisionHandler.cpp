#include "../Engine/Collider.h"
#include "../Engine/Game.h"
#include "../Engine/GameObject.h"
#include "../Engine/GameCollider.h"
#include "../Engine/SpriteRenderer.h"
#include "FoodCollisionHandler.h"
#include "Food.h"

void FoodCollisionHandler::handleCollision(Collider* collider)
{
	this->gameObject->game->destroyObject(this->gameObject);

	auto newX = rand() % 800;
	auto newY = rand() % 600;
	Food::create(
		this->gameObject->game
			->instantiateObject()
			->setGlobalPosition(newX, newY)
	);
}
