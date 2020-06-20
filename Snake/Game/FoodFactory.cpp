#include "FoodFactory.h"
#include "../Engine/SpriteRenderer.h"
#include "../Engine/Collider.h"
#include "../Engine/GameCollider.h"
#include "../Engine/Size.h"
#include "FoodCollisionHandler.h"

FoodFactory::FoodFactory(Size size) : size{ size }
{
}

GameObject* FoodFactory::create(GameObject* gameObject) {
    auto newX = rand() % this->size.w;
    auto newY = rand() % this->size.h;
    return gameObject
        ->setGlobalPosition(newX, newY)
        ->addRenderer(new SpriteRenderer("assets/food.png"))
        ->addCollider(ColliderType::PASSIVE, new Collider(10, 10))
        ->addUpdater(new FoodCollisionHandler(*this));
}
