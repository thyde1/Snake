#include <list>
#include <iostream>
#include <string>
#include "Game.h"
#include "Position.h"
#include "Snake.h"
#include "SnakeData.h"
#include "Collider.h"
#include "Direction.h"

const int speed = 2;

Snake::Snake(SnakeData* snakeData)
{
	this->snakeData = snakeData;
	this->snakeData->direction = Direction::NONE;
}

void Snake::init()
{
	this->snakeData = this->gameObject->getComponent<SnakeData*>();
}

void Snake::update(int elapsed)
{
	if (this->snakeData->state == SnakeData::State::DEAD) {
		return;
	}

	auto currentPosition = this->gameObject->globalPosition;
	switch (this->snakeData->direction) {
	case Direction::UP:
		this->gameObject->globalPosition = new Position(currentPosition->getX(), currentPosition->getY() - (int)(elapsed * speed * 0.1));
		break;
	case Direction::DOWN:
		this->gameObject->globalPosition = new Position(currentPosition->getX(), currentPosition->getY() + (int)(elapsed * speed * 0.1));
		break;
	case Direction::LEFT:
		this->gameObject->globalPosition = new Position(currentPosition->getX() - (int)(elapsed * speed * 0.1), currentPosition->getY());
		break;
	case Direction::RIGHT:
		this->gameObject->globalPosition = new Position(currentPosition->getX() + (int)(elapsed * speed * 0.1), currentPosition->getY());
		break;
	default:
		this->gameObject->globalPosition = new Position(currentPosition->getX(), currentPosition->getY());
	}

	if (this->checkSelfCollision() || this->checkOutOfBounds()) {
		this->snakeData->state = SnakeData::State::DEAD;
	}

	this->snakeData->addPosition(this->gameObject->globalPosition);
}

void Snake::handleInput(std::list<SDL_Keysym> keys)
{
	for (auto key : keys)
	{
		switch (key.sym) {
		case SDLK_UP:
			if (this->snakeData->direction != Direction::DOWN) {
				this->snakeData->direction = Direction::UP;
			}
			break;
		case SDLK_DOWN:
			if (this->snakeData->direction != Direction::UP) {
				this->snakeData->direction = Direction::DOWN;
			}
			break;
		case SDLK_LEFT:
			if (this->snakeData->direction != Direction::RIGHT) {
				this->snakeData->direction = Direction::LEFT;
			}
			break;
		case SDLK_RIGHT:
			if (this->snakeData->direction != Direction::LEFT) {
				this->snakeData->direction = Direction::RIGHT;
			}
			break;
		}
	}
}

void Snake::handleCollision(Collider* collider)
{
	this->snakeData->length += 10;
}

bool Snake::checkSelfCollision() {
	auto currentPosition = this->gameObject->globalPosition;
	switch (this->snakeData->direction) {
	case Direction::UP:
		for (Position* position : this->snakeData->positions) {
			if (position->getY() < currentPosition->getY() && checkCollision(position))
			{
				return true;
			}
		}
		break;
	case Direction::DOWN:
		for (Position* position : this->snakeData->positions) {
			if (position->getY() > currentPosition->getY() && checkCollision(position))
			{
				return true;
			}
		}
		break;
	case Direction::LEFT:
		for (Position* position : this->snakeData->positions) {
			if (position->getX() < currentPosition->getX() && checkCollision(position))
			{
				return true;
			}
		}
		break;
	case Direction::RIGHT:
		for (Position* position : this->snakeData->positions) {
			if (position->getX() > currentPosition->getX() && checkCollision(position))
			{
				return true;
			}
		}
		break;
	}
	return false;
}

bool Snake::checkOutOfBounds()
{
	auto girth = this->snakeData->girth;
	auto windowSize = this->gameObject->game->windowSize;
	if (this->gameObject->globalPosition->getX() < 0) {
		return true;
	}

	if (this->gameObject->globalPosition->getX() + girth > windowSize.w) {
		return true;
	}

	if (this->gameObject->globalPosition->getY() < 0) {
		return true;
	}

	if (this->gameObject->globalPosition->getY() + girth > windowSize.h) {
		return true;
	}

	return false;
}

bool Snake::checkCollision(Position* position)
{
	auto currentPosition = this->gameObject->globalPosition;
	auto girth = this->snakeData->girth;
	return Collider::checkCollision(girth, girth, currentPosition->getX(), currentPosition->getY(), girth, girth, position->getX(), position->getY());
}
