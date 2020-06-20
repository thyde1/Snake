#include "GameState.h"
#include <algorithm>
#include "../Engine/Game.h"

void GameState::handleInput(std::list<SDL_Keysym> keys)
{
    if (std::find_if(keys.begin(), keys.end(), [](SDL_Keysym key) { return key.sym == SDLK_r; }) != keys.end()) {
        this->gameObject->game->init();
    }
}
