#pragma once

#include <list>
#include "../Engine/Component.h"

class Position;
enum class Direction;

class SnakeData : public Component {
public:
	Direction direction;
	enum class State { DEAD, ALIVE };
	State state;
	SnakeData();
	int girth = 10;
	int length = 20;
	void addPosition(Position* position);
	std::list<Position*> positions;
};
