#include "GameObject.h"
#include "Updater.h"
#include "Renderer.h"

GameObject::GameObject(SDL_Renderer* renderer)
{
	this->sdlRenderer = renderer;
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
	for (Renderer* renderer : this->renderers)
	{
		renderer->render();
	}
}

GameObject* GameObject::addUpdater(Updater* updater)
{
	updater->setGameObject(this);
	this->updaters.push_back(updater);
	return this;
}

GameObject* GameObject::addRenderer(Renderer* renderer)
{
	renderer->setGameObject(this);
	renderer->setSdlRenderer(this->sdlRenderer);
	this->renderers.push_back(renderer);
	return this;
}

GameObject* GameObject::addComponent(Component* component)
{
	component->setGameObject(this);
	this->components.push_back(component);
	return this;
}
