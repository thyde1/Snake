#include "SnakeRenderer.h"
#include "SnakeData.h"
#include "Snake.h"
#include "Position.h"

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
