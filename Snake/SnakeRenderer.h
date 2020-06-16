#pragma once

#include "Renderer.h"

class SnakeData;
class Position;

class SnakeRenderer : public Renderer {
public:
	SnakeRenderer(SnakeData* snakeData);
	void render();
private:
	void renderPosition(Position* position);
	void renderHead();
	SnakeData* snakeData;
};
