#pragma once
#include <list>
#include "SDL.h"
#include "Component.h"

class GameObject;
class Collider;

class Updater : public Component {
public:
    virtual void handleInput(std::list<SDL_Keysym> keys);
    virtual void handleCollision(Collider* collider);
    virtual void update(int elapsed);
};
