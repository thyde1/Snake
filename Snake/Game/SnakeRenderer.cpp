#include "SDL_image.h"
#include "../Engine/Position.h"
#include "SnakeRenderer.h"
#include "SnakeData.h"
#include "Snake.h"
#include "Direction.h"

SDL_Texture* faceTexture;

SnakeRenderer::SnakeRenderer(SnakeData* snakeData) {
	this->snakeData = snakeData;
}

void SnakeRenderer::render()
{
	if (faceTexture == NULL) {
		SDL_Surface* tempFaceSurface = IMG_Load("assets/snakeFace.png");
		faceTexture = SDL_CreateTextureFromSurface(this->sdlRenderer, tempFaceSurface);
		SDL_FreeSurface(tempFaceSurface);
	}

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
	auto girth = this->snakeData->girth;
	SDL_SetRenderDrawColor(this->sdlRenderer, 255, 127, 127, 255);
	auto faceRect = new SDL_Rect();
	faceRect->x = headPosition->getX();
	faceRect->y = headPosition->getY();
	faceRect->w = girth;
	faceRect->h = girth;
	auto faceCenter = new SDL_Point();
	faceCenter->x = 5;
	faceCenter->y = 5;
	switch (this->snakeData->direction)
	{
	case Direction::UP:
		SDL_RenderCopy(this->sdlRenderer, faceTexture, NULL, faceRect);
		SDL_RenderDrawLine(
			this->sdlRenderer,
			headPosition->getX() + girth * 0.5, headPosition->getY(),
			headPosition->getX() + girth * 0.5, headPosition->getY() - 5
		);
		break;
	case Direction::DOWN:
		SDL_RenderCopyEx(this->sdlRenderer, faceTexture, NULL, faceRect, 0, faceCenter, SDL_RendererFlip::SDL_FLIP_VERTICAL);
		SDL_RenderDrawLine(
			this->sdlRenderer,
			headPosition->getX() + girth * 0.5, headPosition->getY() + girth,
			headPosition->getX() + girth * 0.5, headPosition->getY() + girth + 5
		);
		break;
	case Direction::LEFT:
		SDL_RenderCopyEx(this->sdlRenderer, faceTexture, NULL, faceRect, -90, faceCenter, SDL_RendererFlip::SDL_FLIP_NONE);
		SDL_RenderDrawLine(
			this->sdlRenderer,
			headPosition->getX(), headPosition->getY() + girth * 0.5,
			headPosition->getX() - 5, headPosition->getY() + girth * 0.5
		);
		break;
	case Direction::RIGHT:
		SDL_RenderCopyEx(this->sdlRenderer, faceTexture, NULL, faceRect, 90, faceCenter, SDL_RendererFlip::SDL_FLIP_NONE);
		SDL_RenderDrawLine(
			this->sdlRenderer,
			headPosition->getX() + girth, headPosition->getY() + girth * 0.5,
			headPosition->getX() + girth + 5, headPosition->getY() + girth * 0.5
		);
		break;
	default:
		SDL_RenderCopy(this->sdlRenderer, faceTexture, NULL, faceRect);
		SDL_RenderDrawLine(
			this->sdlRenderer,
			headPosition->getX() + girth * 0.5, headPosition->getY(),
			headPosition->getX() + girth * 0.5, headPosition->getY() - 5
		);
		break;
	}
	delete faceRect;
	delete faceCenter;
}
