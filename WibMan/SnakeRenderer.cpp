#include "SnakeRenderer.h"
#include "SnakeData.h"
#include "Snake.h"
#include "Position.h"
#include "Direction.h"

SnakeRenderer::SnakeRenderer(SnakeData* snakeData) {
	this->snakeData = snakeData;
}

void SnakeRenderer::render()
{
	struct Color { int r; int g; int b; int a; };
	const Color aliveColor = { 0, 0, 255, 255 };
	const Color deadColor = { 255, 0, 0, 255 };
	auto snakeColor = this->snakeData->state == SnakeData::State::ALIVE ? aliveColor : deadColor;
	SDL_SetRenderDrawColor(this->sdlRenderer, snakeColor.r, snakeColor.g, snakeColor.b, snakeColor.a);
	for (auto position : this->snakeData->positions) {
		renderPosition(position);
	}
	this->renderHead();
}

void SnakeRenderer::renderPosition(Position* position)
{
	auto rect = new SDL_Rect();
	rect->w = 10;
	rect->h = 10;
	rect->x = position->getX();
	rect->y = position->getY();
	SDL_RenderFillRect(this->sdlRenderer, rect);
	delete rect;
}

void SnakeRenderer::renderHead() {
	auto headPosition = this->snakeData->positions.back();
	SDL_SetRenderDrawColor(this->sdlRenderer, 255, 127, 127, 255);
	switch (this->snakeData->direction)
	{
	case Direction::UP:
		SDL_RenderDrawLine(
			this->sdlRenderer,
			headPosition->getX() + this->snakeData->girth * 0.5, headPosition->getY(),
			headPosition->getX() + this->snakeData->girth * 0.5, headPosition->getY() - 5
		);
		break;
	case Direction::DOWN:
		SDL_RenderDrawLine(
			this->sdlRenderer,
			headPosition->getX() + this->snakeData->girth * 0.5, headPosition->getY() + this->snakeData->girth,
			headPosition->getX() + this->snakeData->girth * 0.5, headPosition->getY() + this->snakeData->girth + 5
		);
		break;
	case Direction::LEFT:
		SDL_RenderDrawLine(
			this->sdlRenderer,
			headPosition->getX(), headPosition->getY() + this->snakeData->girth * 0.5,
			headPosition->getX() - 5, headPosition->getY() + this->snakeData->girth * 0.5
		);
		break;
	case Direction::RIGHT:
		SDL_RenderDrawLine(
			this->sdlRenderer,
			headPosition->getX() + this->snakeData->girth, headPosition->getY() + this->snakeData->girth * 0.5,
			headPosition->getX() + this->snakeData->girth + 5, headPosition->getY() + this->snakeData->girth * 0.5
		);
		break;
	default:
		SDL_RenderDrawPoint(this->sdlRenderer, headPosition->getX() + this->snakeData->girth * 0.5, headPosition->getY());
		break;
	}
}
