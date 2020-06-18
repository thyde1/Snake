#pragma once

#include<memory>
#include "../Engine/Renderer.h"
#include "../Engine/SpriteRenderer.h"

class SnakeData;
class Position;

class SnakeRenderer : public Renderer {
public:
	SnakeRenderer(SnakeData* snakeData);
	void render();
private:
	void renderPosition(Position* position);
	void renderHead();

	std::unique_ptr<SpriteRenderer> spriteRenderer;
	SnakeData *snakeData;
};
