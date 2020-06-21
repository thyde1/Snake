#pragma once

#include "../Engine/GameObject.h"
#include "../Engine/Position.h"
#include "../Engine/Size.h"

namespace ScoreBar {
    GameObject* create(GameObject *gameObject, int &score, Position position, Size size);
}
