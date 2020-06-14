#include "PointRenderer.h"

void PointRenderer::render()
{
	SDL_SetRenderDrawColor(this->sdlRenderer, 255, 0, 0, 255);
	SDL_RenderDrawPoint(this->sdlRenderer, this->gameObject->globalPosition->x, this->gameObject->globalPosition->y);
}
