#pragma once

#include "Renderer.h"

class SnakeData;

class SnakeRenderer : public Renderer {
public:
	SnakeRenderer(SnakeData* snakeData);
	void render();
private:
	SnakeData* snakeData;
};
