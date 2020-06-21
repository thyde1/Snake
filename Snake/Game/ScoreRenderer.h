#pragma once

#include "../Engine/TextRenderer.h"

class ScoreRenderer : public TextRenderer {
public:
    ScoreRenderer(int &score);
    void render();
private:
    int &score;
};
