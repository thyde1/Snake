#include "GameObject.h"
#include "Updater.h"

GameObject::GameObject(SDL_Renderer* renderer)
{
	this->renderer = renderer;
	this->globalPosition = new Position();
}

void GameObject::handleInput(std::list<SDL_Keysym> keys)
{
	for (Updater* updater : this->updaters)
	{
		updater->handleInput(keys);
	}
}

void GameObject::update(int elapsed)
{
	for (Updater* updater : this->updaters)
	{
		updater->update(elapsed);
	}
}

void GameObject::render()
{
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_Rect rect = *new SDL_Rect();
	rect.x = this->globalPosition->x;
	rect.y = this->globalPosition->y;
	rect.w = 10;
	rect.h = 10;
	SDL_RenderDrawRect(renderer, &rect);
}

GameObject* GameObject::addUpdater(Updater* updater)
{
	updater->setGameObject(this);
	this->updaters.push_back(updater);
	return this;
}
