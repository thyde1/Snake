#include "../Engine/SpriteRenderer.h"
#include "../Engine/Collider.h"
#include "../Engine/GameCollider.h"
#include "Food.h"
#include "FoodCollisionHandler.h"

GameObject* Food::create(GameObject* gameObject) {
    return gameObject
		->addRenderer(new SpriteRenderer("assets/food.png"))
		->addCollider(ColliderType::PASSIVE, new Collider(10, 10))
		->addUpdater(new FoodCollisionHandler());
}
