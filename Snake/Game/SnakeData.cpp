#include <list>
#include "../Engine/Position.h"
#include "SnakeData.h"

SnakeData::SnakeData() {
	this->positions = std::list<Position*>();
	this->state = SnakeData::State::ALIVE;
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
