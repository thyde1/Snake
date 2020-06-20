#pragma once

#include "UiRenderer.h"
#include "../Engine/Game.h"
#include "../Engine/Position.h"
#include "../Engine/Renderer.h"


class UiRenderer : public Renderer
{
public:
    UiRenderer(const Position position, const Size windowSize, const int *score);
    void render();
private:
    const Position position;
    const Size windowSize;
    const int* score;
};
