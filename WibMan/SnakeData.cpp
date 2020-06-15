#include <list>
#include "SnakeData.h"
#include "Position.h"

SnakeData::SnakeData() {
	this->positions = std::list<Position*>();
}

void SnakeData::addPosition(Position* position)
{
	if (this->positions.size() >= this->length) {
		auto lastPosition = this->positions.front();
		this->positions.pop_front();
		delete lastPosition;
	}
	this->positions.push_back(position);
}
