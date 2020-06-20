#pragma once

#include "../Engine/Updater.h"
#include "../Engine/GameObject.h"

class GameState : public Updater {
public:
    void handleInput(std::list<SDL_Keysym> keys);
};
