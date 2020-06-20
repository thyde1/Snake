#include "GameObject.h"
#include "Game.h"
#include "Updater.h"
#include "Renderer.h"
#include "Collider.h"
#include "GameCollider.h"
#include "Updater.h"

GameObject::GameObject(Game* game, SDL_Renderer* renderer)
{
	this->game = game;
	this->sdlRenderer = renderer;
	this->globalPosition = new Position(0, 0);
}

GameObject::~GameObject()
{
	for (auto updater : this->updaters)
	{
		delete updater;
	}
	for (auto gameCollider : this->colliders) {
		delete gameCollider;
	}
	for (auto renderer : this->renderers)
	{
		delete renderer;
	}
}

void GameObject::handleInput(std::list<SDL_Keysym> keys)
{
	for (Updater *updater : this->updaters)
	{
		updater->handleInput(keys);
	}
}

void GameObject::update(int elapsed)
{
	for (Updater *updater : this->updaters)
	{
		updater->update(elapsed);
	}
	for (auto gameCollider : this->colliders) {
		gameCollider->collider->x = this->globalPosition->getX();
		gameCollider->collider->y = this->globalPosition->getY();
	}
}

void GameObject::checkCollision(GameObject* object)
{
	for (auto gameCollider : this->colliders)
	{
		if (gameCollider->type == ColliderType::ACTIVE) {
			object->checkCollision(gameCollider->collider);
		}
	}
}

void GameObject::checkCollision(Collider* collider)
{
	for (auto gameCollider : this->colliders)
	{
		auto thisCollider = gameCollider->collider;
		if (thisCollider->checkCollision(collider)) {
			this->handleCollision(collider);
			collider->getGameObject()->handleCollision(thisCollider);
		}
	}
}

void GameObject::handleCollision(Collider *collider)
{
	for (Updater *updater : this->updaters)
	{
		updater->handleCollision(collider);
	}
}

void GameObject::render()
{
	for (Renderer *renderer : this->renderers)
	{
		renderer->render();
	}
}

GameObject *GameObject::addUpdater(Updater *updater)
{
	this->addComponent(updater);
	this->updaters.push_back(updater);
	return this;
}

GameObject *GameObject::addRenderer(Renderer *renderer)
{
	this->addComponent(renderer);
	renderer->setSdlRenderer(this->sdlRenderer);
	this->renderers.push_back(renderer);
	return this;
}

GameObject *GameObject::addCollider(ColliderType type, Collider *collider) {

	this->addComponent(collider);
	GameCollider* gameCollider = new GameCollider(type, collider);
	this->colliders.push_back(gameCollider);
	return this;
}

GameObject *GameObject::addComponent(Component *component)
{
	component->setGameObject(this);
	this->components.push_back(component);
	return this;
}

GameObject *GameObject::setGlobalPosition(int x, int y)
{
	this->globalPosition = new Position(x, y);
	return this;
}
