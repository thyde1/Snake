#include "SnakeRenderer.h"
#include "SnakeData.h"
#include "Snake.h"
#include "Position.h"

SnakeRenderer::SnakeRenderer(SnakeData* snakeData) {
	this->snakeData = snakeData;
}

void SnakeRenderer::render()
{
	SDL_SetRenderDrawColor(this->sdlRenderer, 255, 0, 0, 255);
	for (auto position : *this->snakeData->positions) {
		renderPosition(position);
	}
}

void SnakeRenderer::renderPosition(Position* position)
{
	auto rect = new SDL_Rect();
	rect->w = 10;
	rect->h = 10;
	rect->x = position->getX() - 5;
	rect->y = position->getY() - 5;
	SDL_RenderFillRect(this->sdlRenderer, rect);
}
