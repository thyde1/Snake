#pragma once

class Collider;

enum class ColliderType
{
	ACTIVE, PASSIVE
};

class GameCollider {
public:
	GameCollider(ColliderType type, Collider* collider);
	ColliderType type;
	Collider* collider;
};
