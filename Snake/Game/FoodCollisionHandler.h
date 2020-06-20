#pragma once
#include "../Engine/Updater.h"
#include "FoodFactory.h"

class FoodCollisionHandler : public Updater
{
public:
    FoodCollisionHandler(FoodFactory& foodFactory);
    void handleCollision(Collider* collider);
private:
    FoodFactory& foodFactory;
};
