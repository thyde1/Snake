#pragma once

#include <list>
#include "Component.h"

class Position;

class SnakeData : public Component {
public:
	enum class State { DEAD, ALIVE };
	State state;
	SnakeData();
	int girth = 10;
	int length = 20;
	void addPosition(Position* position);
	std::list<Position*> positions;
};
