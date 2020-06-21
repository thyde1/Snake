#include "SnakeGame.h"
#include "../Engine/Game.h"
#include "../Engine/GameCollider.h"
#include "../Engine/Collider.h"
#include "SnakeRenderer.h"
#include "Snake.h"
#include "FoodFactory.h"
#include "GameState.h"
#include "ScoreBar.h"
#include "UiRenderer.h"
#include "GameOverTextRenderer.h"

SnakeGame::SnakeGame(Size windowSize) : Game("Snake", windowSize), worldSize({ windowSize.w, windowSize.h - SnakeGame::uiHeight }), foodFactory(FoodFactory(worldSize))
{
}

void SnakeGame::init()
{
    this->destroyEverything();

    // Game State
    this->instantiateObject()->addUpdater(new GameState());

    this->score = 0;
    this->snakeData = SnakeData();

    // Snake
    GameObject *snake = this->instantiateObject()
        ->setGlobalPosition(worldSize.w / 2, worldSize.h / 2)
        ->addComponent(&this->snakeData)
        ->addCollider(ColliderType::ACTIVE, new Collider(10, 10))
        ->addUpdater(new Snake(&this->snakeData, worldSize, &this->score))
        ->addRenderer(new SnakeRenderer(&this->snakeData));
    this->snakeData.positions.push_back(snake->globalPosition);

    this->foodFactory.create(this->instantiateObject());

    Size uiSize = { this->windowSize.w, this->windowSize.h - this->worldSize.h };
    Position uiPosition = Position(0, this->worldSize.h);

    // UI
    ScoreBar::create(this->instantiateObject(), this->score, uiPosition, uiSize);
    this->instantiateObject()
        ->addRenderer(new GameOverTextRenderer(this->score, this->snakeData.state))
        ->setGlobalPosition(snake->globalPosition->x, snake->globalPosition->y);
}

void SnakeGame::destroyEverything()
{
    for (auto object : this->gameObjects) {
        this->destroyObject(object);
    }
    for (auto position : this->snakeData.positions) {
        delete position;
    }
}
