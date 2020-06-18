#pragma once
#include "Renderer.h"
#include <string>
class SpriteRenderer : public Renderer
{
public:
    SpriteRenderer(std::string imagePath);
    void render();
};
