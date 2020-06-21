#include "FoodFactory.h"
#include "../Engine/Renderers/SpriteRenderer.h"
#include "../Engine/Collider.h"
#include "../Engine/GameCollider.h"
#include "../Engine/Size.h"
#include "FoodCollisionHandler.h"

FoodFactory::FoodFactory(Size worldSize) : worldSize{ worldSize }
{
}

GameObject* FoodFactory::create(GameObject* gameObject) {
    const Size foodSize = { 10, 10 };
    auto newX = rand() % (this->worldSize.w - foodSize.w);
    auto newY = rand() % (this->worldSize.h - foodSize.h);
    return gameObject
        ->setGlobalPosition(newX, newY)
        ->addRenderer(new SpriteRenderer("assets/food.png"))
        ->addCollider(ColliderType::PASSIVE, new Collider(foodSize))
        ->addUpdater(new FoodCollisionHandler(*this));
}
