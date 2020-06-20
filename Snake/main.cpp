#include "SDL.h"
#include "Game/SnakeGame.h"

int main(int argc, char* argv[]) {
	Game* game = new SnakeGame({ 800, 600 });
	game->start();

	return 0;
};
