#pragma once

#include<memory>
#include "../Engine/Renderer.h"
#include "../Engine/Renderers/SpriteRenderer.h"

class SnakeData;
class Position;

class SnakeRenderer : public Renderer {
public:
    SnakeRenderer(SnakeData* snakeData);
    ~SnakeRenderer();
    void render();
private:
    void renderPosition(Position* position);
    void renderHead();

    std::unique_ptr<SpriteRenderer> spriteRenderer;
    SnakeData *snakeData;
};
