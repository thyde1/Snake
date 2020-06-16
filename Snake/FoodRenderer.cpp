#include "SDL_image.h"
#include "FoodRenderer.h"

SDL_Texture* foodTexture;

void FoodRenderer::render()
{
	if (foodTexture == NULL) {
		SDL_Surface* tempFoodSurface = IMG_Load("assets/food.png");
		foodTexture = SDL_CreateTextureFromSurface(this->sdlRenderer, tempFoodSurface);
		SDL_FreeSurface(tempFoodSurface);
	}

	auto foodRect = new SDL_Rect();
	foodRect->x = this->gameObject->globalPosition->getX();
	foodRect->y = this->gameObject->globalPosition->getY();
	foodRect->w = 10;
	foodRect->h = 10;
	SDL_RenderCopy(this->sdlRenderer, foodTexture, NULL, foodRect);
	delete foodRect;
}
