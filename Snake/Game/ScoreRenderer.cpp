#include "ScoreRenderer.h"
#include <string>

ScoreRenderer::ScoreRenderer(int &score) : score(score)
{
}

void ScoreRenderer::render()
{
    auto scoreString = std::to_string(score);
    this->text = scoreString.c_str();
    TextRenderer::render();
}
