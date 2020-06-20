#pragma once

#include "UiRenderer.h"
#include "SDL_ttf.h"
#include "../Engine/Game.h"
#include "../Engine/Position.h"
#include "../Engine/Renderer.h"


class UiRenderer : public Renderer
{
public:
    UiRenderer(const Position position, const Size windowSize, const int *score);
    ~UiRenderer();
    void render();
private:
    const Position position;
    const Size windowSize;
    const int *score;
    TTF_Font *font;
};
