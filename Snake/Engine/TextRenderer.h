#pragma once

#include "SDL_ttf.h"
#include "../Engine/Renderer.h"
#include"Position.h"

class TextRenderer : public Renderer {
public:
    TextRenderer();
    TextRenderer(SDL_Color color);
    TextRenderer(const char *text, SDL_Color color);
    ~TextRenderer();
    virtual void render();
    const char *text;
private:
    TTF_Font *font;
    SDL_Color color;
};
