#include "GameOverTextRenderer.h"
#include <string>

GameOverTextRenderer::GameOverTextRenderer(int &score, SnakeData::State &gameState) 
    : TextRenderer({ 0, 0, 0, 255 }, TextAlignment::CENTER), score(score), gameState(gameState)
{
}

void GameOverTextRenderer::render()
{
    if (this->gameState != SnakeData::State::DEAD) {
        return;
    }

    auto gameOverString = std::string("GAME OVER");
    auto scoreString = std::string("Score: ") + std::to_string(this->score);
    auto playAgainString = std::string("Press R to play again");
    this->text = { gameOverString.c_str(), scoreString.c_str(), playAgainString.c_str() };
    TextRenderer::render();
}
