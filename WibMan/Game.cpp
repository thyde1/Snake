#include "Game.h"
#include "Player.h"
#include "SquareRenderer.h"
#include "PointRenderer.h"
#include "SnakeData.h"

Game::Game()
{
	this->init();
}

Game::~Game()
{
}

void Game::init()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow("title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_SHOWN);
	this->renderer = SDL_CreateRenderer(window, -1, 0);

	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);

	SDL_RenderClear(renderer);

	SDL_RenderPresent(renderer);

	this->gameObjects = *new std::list<GameObject*>();

	this->instantiateObject()
		->addUpdater(new Player())
		->addRenderer(new SquareRenderer())
		->addRenderer(new PointRenderer())
		->addComponent(new SnakeData())
		->addComponent(new Component());

	const int fps = 60;
	const int frameDelay = 1000 / fps;

	auto frameStart = SDL_GetTicks();
	auto lastUpdate = SDL_GetTicks();
	while (isRunning()) {
		auto runningTime = SDL_GetTicks();
		auto elapsed = runningTime - lastUpdate;
		if (elapsed >= 10) {
			handleInput();
			update(elapsed);
			lastUpdate = SDL_GetTicks();
		}
		if (runningTime - frameStart >= frameDelay) {
			frameStart = runningTime;
			render();
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

void Game::render()
{
	for (GameObject* gameObject : this->gameObjects)
	{
		gameObject->render();
	}
	SDL_RenderPresent(renderer);
}

GameObject* Game::instantiateObject()
{
	GameObject* object = new GameObject(this->renderer);
	this->gameObjects.push_back(object);
	return object;
}
