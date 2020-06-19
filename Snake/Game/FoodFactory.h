#pragma once

#include "FoodFactory.h"
#include "../Engine/GameObject.h"
#include "../Engine/Size.h"

class FoodFactory
{
public:
    FoodFactory(Size size);
    GameObject* create(GameObject *gameObject);
private:
    Size size;
};

