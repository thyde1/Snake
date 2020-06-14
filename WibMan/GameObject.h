#pragma once
#include "SDL.h"
#include "Position.h"
#include <list>

class Updater;
class Renderer;
class Collider;
class GameCollider;
enum class ColliderType;
class Component;

class GameObject {
public:
	GameObject(SDL_Renderer* renderer);
	virtual ~GameObject();
	void update(int elapsed);
	void checkCollision(GameObject* object);
	virtual void handleCollision(Collider* collider);
	void handleInput(std::list<SDL_Keysym> keys);
	void render();
	GameObject* addUpdater(Updater* updater);
	GameObject* addRenderer(Renderer* renderer);
	GameObject* addCollider(ColliderType type, Collider* collider);
	GameObject* addComponent(Component* component);
	GameObject* setGlobalPosition(int x, int y);
	template <class T>
	T getComponent()
	{
		for (auto component : this->components)
		{
			T castComponent = dynamic_cast<T>(component);
			if (castComponent != NULL) {
				return castComponent;
			}
		}

		return NULL;
	}
	Position* globalPosition;
private:
	void checkCollision(Collider* collider);
	SDL_Renderer* sdlRenderer;
	std::list<Updater*> updaters;
	std::list<Renderer*> renderers;
	std::list<GameCollider*> colliders;
	std::list<Component*> components;
};
