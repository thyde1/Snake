#include "UiRenderer.h"
#include <string>

UiRenderer::UiRenderer(Position position, Size windowSize) : position(position), windowSize(windowSize)
{
}

UiRenderer::~UiRenderer()
{
}

void UiRenderer::render()
{
    SDL_Rect uiRect = { this->position.x, this->position.y, this->windowSize.w, this->windowSize.h };
    SDL_SetRenderDrawColor(this->sdlRenderer, 0, 0, 0, 255);
    SDL_RenderFillRect(this->sdlRenderer, &uiRect);
}
