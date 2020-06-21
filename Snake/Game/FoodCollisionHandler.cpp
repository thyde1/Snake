#include "../Engine/Collider.h"
#include "../Engine/Game.h"
#include "../Engine/GameObject.h"
#include "../Engine/GameCollider.h"
#include "../Engine/Renderers/SpriteRenderer.h"
#include "FoodCollisionHandler.h"
#include "FoodFactory.h"

FoodCollisionHandler::FoodCollisionHandler(FoodFactory& foodFactory) : foodFactory(foodFactory)
{
}

void FoodCollisionHandler::handleCollision(Collider* collider)
{
    this->gameObject->game->destroyObject(this->gameObject);

    foodFactory.create(
        this->gameObject->game
            ->instantiateObject()
    );
}
