#pragma once

#include "SDL_ttf.h"
#include "../Engine/Renderer.h"
#include"Position.h"

class TextRenderer : public Renderer {
public:
    TextRenderer();
    TextRenderer(const char *text);
    ~TextRenderer();
    virtual void render();
    const char *text;
private:
    TTF_Font *font;
};
