#pragma once

#include <list>
#include "Component.h"

class Position;

class SnakeData : public Component {
public:
	SnakeData();
	int length = 300;
	void addPosition(Position* position);
	std::list<Position*>* positions;
};
