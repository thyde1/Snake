#pragma once

#include <list>
#include "Component.h"

class Position;

class SnakeData : public Component {
public:
	SnakeData();
	int girth = 10;
	int length = 20;
	void addPosition(Position* position);
	std::list<Position*> positions;
};
