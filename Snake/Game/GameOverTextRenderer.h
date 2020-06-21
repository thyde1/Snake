#pragma once

#include "../Engine/TextRenderer.h"
#include "SnakeData.h"

class GameOverTextRenderer : public TextRenderer {
public:
    GameOverTextRenderer(int &score, SnakeData::State &gameState);
    void render();
private:
    const int &score;
    SnakeData::State &gameState;
};
