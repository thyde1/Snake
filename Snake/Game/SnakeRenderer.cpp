#include<memory>
#include "SDL_image.h"
#include "../Engine/Position.h"
#include "SnakeRenderer.h"
#include "SnakeData.h"
#include "Snake.h"
#include "Direction.h"

SDL_Texture* faceTexture;

SnakeRenderer::SnakeRenderer(SnakeData *snakeData) : snakeData{ snakeData }, spriteRenderer { std::unique_ptr<SpriteRenderer>() }
{}

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
    auto rect = SDL_Rect();
    rect.w = 10;
    rect.h = 10;
    rect.x = position->getX();
    rect.y = position->getY();
    SDL_RenderFillRect(this->sdlRenderer, &rect);
}

void SnakeRenderer::renderHead() {
    if (this->spriteRenderer == NULL) {
        this->spriteRenderer = std::make_unique<SpriteRenderer>("assets/snakeFace.png");
        this->spriteRenderer->setSdlRenderer(this->sdlRenderer);
        this->spriteRenderer->setGameObject(this->gameObject);
    }
    auto headPosition = this->snakeData->positions.back();
    auto girth = this->snakeData->girth;
    SDL_SetRenderDrawColor(this->sdlRenderer, 255, 127, 127, 255);
    switch (this->snakeData->direction)
    {
    case Direction::UP:
        this->spriteRenderer->render(0);
        SDL_RenderDrawLine(
            this->sdlRenderer,
            (int)(headPosition->getX() + girth * 0.5), headPosition->getY(),
            (int)(headPosition->getX() + girth * 0.5), headPosition->getY() - 5
        );
        break;
    case Direction::DOWN:
        this->spriteRenderer->render(180);
        SDL_RenderDrawLine(
            this->sdlRenderer,
            (int)(headPosition->getX() + girth * 0.5), headPosition->getY() + girth,
            (int)(headPosition->getX() + girth * 0.5), headPosition->getY() + girth + 5
        );
        break;
    case Direction::LEFT:
        this->spriteRenderer->render(-90);
        SDL_RenderDrawLine(
            this->sdlRenderer,
            headPosition->getX(), (int)(headPosition->getY() + girth * 0.5),
            headPosition->getX() - 5, (int)(headPosition->getY() + girth * 0.5)
        );
        break;
    case Direction::RIGHT:
        this->spriteRenderer->render(90);
        SDL_RenderDrawLine(
            this->sdlRenderer,
            headPosition->getX() + girth, (int)(headPosition->getY() + girth * 0.5),
            headPosition->getX() + girth + 5, (int)(headPosition->getY() + girth * 0.5)
        );
        break;
    default:
        this->spriteRenderer->render(0);
        SDL_RenderDrawLine(
            this->sdlRenderer,
            (int)(headPosition->getX() + girth * 0.5), headPosition->getY(),
            (int)(headPosition->getX() + girth * 0.5), headPosition->getY() - 5
        );
        break;
    }
}
