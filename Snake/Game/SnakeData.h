#pragma once

#include <list>
#include "../Engine/Component.h"
#include "Direction.h"

class Position;

class SnakeData : public Component {
public:
    SnakeData();
    static const int startLength = 10;
    Direction direction = Direction::NONE;
    enum class State { DEAD, ALIVE };
    State state;
    int girth = 10;
    int length = SnakeData::startLength;
    void addPosition(Position* position);
    std::list<Position*> positions;
};
