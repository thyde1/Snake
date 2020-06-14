#include "SnakeRenderer.h"
#include "SnakeData.h"
#include "Player.h"

SnakeRenderer::SnakeRenderer(SnakeData* snakeData) {
	this->snakeData = snakeData;
}

void SnakeRenderer::render()
{
	SDL_SetRenderDrawColor(this->sdlRenderer, 255, 0, 0, 255);
	auto rect = new SDL_Rect();
	rect->w = 10;
	rect->h = 10;
	rect->x = this->gameObject->globalPosition->x - 5;
	rect->y = this->gameObject->globalPosition->y - 5;
	SDL_RenderFillRect(this->sdlRenderer, rect);
}
