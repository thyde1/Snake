#pragma once
#include "../Engine/Updater.h"
class FoodCollisionHandler : public Updater
{
	void handleCollision(Collider* collider);
};

