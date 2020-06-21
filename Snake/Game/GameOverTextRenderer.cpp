#include "GameOverTextRenderer.h"
#include <string>

GameOverTextRenderer::GameOverTextRenderer(int &score, SnakeData::State &gameState) : score(score), gameState(gameState)
{
}

void GameOverTextRenderer::render()
{
    if (this->gameState != SnakeData::State::DEAD) {
        return;
    }

    auto gameOverString = std::string("GAME OVER\nScore: ");
    auto scoreString = std::to_string(this->score);
    auto playAgainString = std::string("\nPress R to play again");
    auto fullString = gameOverString + scoreString + playAgainString;
    this->text = fullString.c_str();
    TextRenderer::render();
}
