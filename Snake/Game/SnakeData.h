#pragma once

#include <list>
#include "../Engine/Component.h"
#include "Direction.h"

class Position;

class SnakeData : public Component {
public:
	Direction direction = Direction::NONE;
	enum class State { DEAD, ALIVE };
	State state;
	SnakeData();
	int girth = 10;
	int length = 20;
	void addPosition(Position* position);
	std::list<Position*> positions;
};
