#include "TextRenderer.h"
#include <string>


TextRenderer::TextRenderer(const char *text, SDL_Color color) : text(text), color(color), font(TTF_OpenFont("verdana.ttf", 20))
{
}

TextRenderer::TextRenderer(SDL_Color color) : TextRenderer("", color)
{
}

TextRenderer::TextRenderer() : TextRenderer({ 0, 0, 0, 255 })
{
}

TextRenderer::~TextRenderer()
{
    TTF_CloseFont(this->font);
}

void TextRenderer::render()
{
    auto textSurface = TTF_RenderText_Blended_Wrapped(this->font, this->text, this->color, 400);
    auto textTexture = SDL_CreateTextureFromSurface(this->sdlRenderer, textSurface);
    int w, h;
    SDL_QueryTexture(textTexture, NULL, NULL, &w, &h);
    SDL_FreeSurface(textSurface);
    SDL_Rect uiRect = { this->gameObject->globalPosition->x, this->gameObject->globalPosition->y, w, h };
    SDL_RenderCopy(this->sdlRenderer, textTexture, NULL, &uiRect);
    SDL_DestroyTexture(textTexture);
}
