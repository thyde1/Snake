#include "Position.h"
#include <iostream>

Position::Position(int x, int y)
{
	this->x = x;
	this->y = y;
}

Position::~Position()
{
}

int Position::getX()
{
	return this->x;
}

int Position::getY()
{
	return this->y;
}
