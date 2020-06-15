#include <memory>
#include "Game.h"

Game::Game()
{
	this->sdlInit();
}

Game::~Game()
{
}

void Game::sdlInit()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow("title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
	this->renderer = SDL_CreateRenderer(window, -1, 0);

	this->clearScreen();

	SDL_RenderPresent(renderer);

	this->gameObjects = *new std::list<GameObject*>();
}

void Game::start()
{
	this->init();
	const int fps = 60;
	const int frameDelay = 1000 / fps;

	auto frameStart = SDL_GetTicks();
	auto lastUpdate = SDL_GetTicks();
	while (this->isRunning()) {
		this->instantiateGameObjectsPendingInstantiation();
		auto runningTime = SDL_GetTicks();
		auto elapsed = runningTime - lastUpdate;
		if (elapsed >= 10) {
			this->handleInput();
			this->update(elapsed);
			destroyObjectsPendingDestruction();
			this->checkCollisions();
			destroyObjectsPendingDestruction();
			lastUpdate = SDL_GetTicks();
		}
		if (runningTime - frameStart >= frameDelay) {
			frameStart = runningTime;
			this->render();
		}
	}
}

bool Game::isRunning()
{
	return true;
}

void Game::handleInput()
{
	SDL_Event event;
	std::list<SDL_Keysym> keys;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_KEYDOWN:
			keys.push_back(event.key.keysym);
			break;
		}
	}

	for (GameObject* gameObject : this->gameObjects)
	{
		gameObject->handleInput(keys);
	}
}

void Game::update(int elapsed)
{
	for(GameObject* gameObject : this->gameObjects)
	{
		gameObject->update(elapsed);
	}
}

void Game::checkCollisions()
{
	for (GameObject* gameObject : this->gameObjects)
	{
		for (GameObject* other : this->gameObjects) {
			if (other != gameObject) {
				gameObject->checkCollision(other);
			}
		}
	}
}

void Game::render()
{
	this->clearScreen();
	for (GameObject* gameObject : this->gameObjects)
	{
		gameObject->render();
	}
	SDL_RenderPresent(renderer);
}

GameObject* Game::instantiateObject()
{
	auto object = new GameObject(this, this->renderer);
	this->gameObjectsPendingInstantiation.push_back(object);
	return object;
}

void Game::destroyObject(GameObject* object)
{
	this->gameObjectsPendingDestruction.push_back(object);
}

void Game::clearScreen()
{
	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
	SDL_RenderClear(renderer);
}

void Game::instantiateGameObjectsPendingInstantiation()
{
	for (auto object : this->gameObjectsPendingInstantiation) {
		this->gameObjects.push_back(object);
	}

	this->gameObjectsPendingInstantiation.clear();
}

void Game::destroyObjectsPendingDestruction()
{
	for (auto object : this->gameObjectsPendingDestruction) {
		this->gameObjects.remove(object);
		delete object;
	}
	this->gameObjectsPendingDestruction.clear();
}
