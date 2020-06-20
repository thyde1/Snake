#include "../Engine/Game.h"
#include "../Engine/GameCollider.h"
#include "../Engine/Collider.h"
#include "SnakeGame.h"
#include "SnakeRenderer.h"
#include "Snake.h"
#include "FoodFactory.h"
#include "GameState.h"
#include "UiRenderer.h"

SnakeGame::SnakeGame(Size windowSize) : Game("Snake", windowSize), worldSize({ windowSize.w, windowSize.h - SnakeGame::uiHeight }), foodFactory(FoodFactory(worldSize))
{
}

void SnakeGame::init()
{
    this->destroyEverything();

    this->score = 0;
    this->snakeData.length = SnakeData::startLength;

    this->instantiateObject()
        ->setGlobalPosition(worldSize.w / 2, worldSize.h / 2)
        ->addComponent(&this->snakeData)
        ->addCollider(ColliderType::ACTIVE, new Collider(10, 10))
        ->addUpdater(new Snake(&this->snakeData, worldSize, &this->score))
        ->addRenderer(new SnakeRenderer(&this->snakeData));

    this->foodFactory.create(this->instantiateObject());

    Size uiHeight = { this->windowSize.w, this->windowSize.h - this->worldSize.h };
    Position uiPosition = Position(0, this->worldSize.h);
    this->instantiateObject()->addRenderer(new UiRenderer(uiPosition, uiHeight, &this->score));
    this->instantiateObject()->addUpdater(new GameState());
}

void SnakeGame::destroyEverything()
{
    for (auto object : this->gameObjects) {
        this->destroyObject(object);
    }
}
