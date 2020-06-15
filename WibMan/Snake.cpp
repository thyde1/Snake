#include <list>
#include <iostream>
#include <string>
#include "Position.h"
#include "Snake.h"
#include "SnakeData.h"

const auto speed = 1;

Snake::Snake(SnakeData* snakeData)
{
	this->snakeData = snakeData;
	this->direction = Direction::NONE;
}

void Snake::init()
{
	this->snakeData = this->gameObject->getComponent<SnakeData*>();
}

void Snake::update(int elapsed)
{
	auto currentPosition = this->gameObject->globalPosition;
	switch (this->direction) {
	case Direction::UP:
		this->gameObject->globalPosition = new Position(currentPosition->getX(), currentPosition->getY() - 10 * elapsed * speed * 0.01);
		break;
	case Direction::DOWN:
		this->gameObject->globalPosition = new Position(currentPosition->getX(), currentPosition->getY() + 10 * elapsed * speed * 0.01);
		break;
	case Direction::LEFT:
		this->gameObject->globalPosition = new Position(currentPosition->getX() - 10 * elapsed * speed * 0.01, currentPosition->getY());
		break;
	case Direction::RIGHT:
		this->gameObject->globalPosition = new Position(currentPosition->getX() + 10 * elapsed * speed * 0.01, currentPosition->getY());
		break;
	default:
		this->gameObject->globalPosition = new Position(currentPosition->getX(), currentPosition->getY());
	}
	this->snakeData->addPosition(this->gameObject->globalPosition);
}

void Snake::handleInput(std::list<SDL_Keysym> keys)
{
	for (auto key : keys)
	{
		switch (key.sym) {
		case SDLK_UP:
			if (this->direction != Direction::DOWN) {
				this->direction = Direction::UP;
			}
			break;
		case SDLK_DOWN:
			if (this->direction != Direction::UP) {
				this->direction = Direction::DOWN;
			}
			break;
		case SDLK_LEFT:
			if (this->direction != Direction::RIGHT) {
				this->direction = Direction::LEFT;
			}
			break;
		case SDLK_RIGHT:
			if (this->direction != Direction::LEFT) {
				this->direction = Direction::RIGHT;
			}
			break;
		}
	}
}
