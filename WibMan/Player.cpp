#include <list>
#include <iostream>
#include <string>
#include "Player.h"
#include "SnakeData.h"

Player::Player(SnakeData* snakeData)
{
	this->snakeData = snakeData;
	this->direction = Direction::NONE;
}

void Player::init()
{
	this->snakeData = this->gameObject->getComponent<SnakeData*>();
}

void Player::update(int elapsed)
{
	std::cout << this->snakeData->length;
	switch (this->direction) {
	case Direction::UP:
		this->gameObject->globalPosition->y -= 10 * elapsed / 100;
		break;
	case Direction::DOWN:
		this->gameObject->globalPosition->y += 10 * elapsed / 100;
		break;
	case Direction::LEFT:
		this->gameObject->globalPosition->x -= 10 * elapsed / 100;
		break;
	case Direction::RIGHT:
		this->gameObject->globalPosition->x += 10 * elapsed / 100;
		break;
	}
}

void Player::handleInput(std::list<SDL_Keysym> keys)
{
	for (auto key : keys)
	{
		switch (key.sym) {
		case SDLK_UP:
			this->direction = Direction::UP;
			break;
		case SDLK_DOWN:
			this->direction = Direction::DOWN;
			break;
		case SDLK_LEFT:
			this->direction = Direction::LEFT;
			break;
		case SDLK_RIGHT:
			this->direction = Direction::RIGHT;
			break;
		}
	}
}
