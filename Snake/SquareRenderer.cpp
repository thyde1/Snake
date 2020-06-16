#include "SquareRenderer.h"

void SquareRenderer::render() {
	SDL_SetRenderDrawColor(this->sdlRenderer, 255, 0, 0, 255);
	SDL_Rect* rect = new SDL_Rect();
	rect->x = this->gameObject->globalPosition->getX();
	rect->y = this->gameObject->globalPosition->getY();
	rect->w = 10;
	rect->h = 10;
	SDL_RenderDrawRect(this->sdlRenderer, rect);
	delete rect;
}
