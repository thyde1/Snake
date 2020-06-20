#pragma once
#include "../Engine/Game.h"
#include "../Engine/Size.h"
#include "FoodFactory.h"
#include "SnakeData.h"
class SnakeGame : public Game
{
public:
    SnakeGame(Size worldSize);
    void init() override;
private:
    static const int uiHeight = 50;
    int score = 0;
    SnakeData snakeData;
    Size worldSize;
    FoodFactory foodFactory;
    void destroyEverything();
};

