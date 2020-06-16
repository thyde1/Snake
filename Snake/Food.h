#pragma once
#include "Updater.h"
class Food : public Updater
{
	void handleCollision(Collider* collider);
};

