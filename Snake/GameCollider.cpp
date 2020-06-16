#include "GameCollider.h"
#include "Collider.h"

GameCollider::GameCollider(ColliderType type, Collider* collider) {
	this->type = type;
	this->collider = collider;
};
