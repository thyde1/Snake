#include "UiRenderer.h"
#include <string>;

UiRenderer::UiRenderer(Position position, Size windowSize, const int *score) : position(position), windowSize(windowSize), score(score), font(TTF_OpenFont("verdana.ttf", 20))
{
}

UiRenderer::~UiRenderer()
{
    TTF_CloseFont(this->font);
}

void UiRenderer::render()
{
    SDL_Rect uiRect = { this->position.x, this->position.y, this->windowSize.w, this->windowSize.h };
    SDL_SetRenderDrawColor(this->sdlRenderer, 0, 0, 0, 255);
    SDL_RenderFillRect(this->sdlRenderer, &uiRect);

    auto textSurface = TTF_RenderText_Solid(this->font, std::to_string(*this->score).c_str(), { 255, 255, 255, 255 });
    auto textTexture = SDL_CreateTextureFromSurface(this->sdlRenderer, textSurface);
    SDL_FreeSurface(textSurface);
    uiRect = { this->position.x + 10, this->position.y + 10, 150, this->windowSize.h - 20 };
    SDL_RenderCopy(this->sdlRenderer, textTexture, NULL, &uiRect);
    SDL_DestroyTexture(textTexture);
}
