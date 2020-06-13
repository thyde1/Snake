#include <list>
#include "Updater.h"
#include "GameObject.h"
#include "SDL.h"
#include "Keys.h"

void Updater::setGameObject(GameObject* gameObject)
{
	this->gameObject = gameObject;
}

void Updater::handleInput(std::list<SDL_Keysym> keys)
{
}
