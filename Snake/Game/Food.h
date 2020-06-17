#pragma once
#include "../Engine/Updater.h"
class Food : public Updater
{
	void handleCollision(Collider* collider);
};

