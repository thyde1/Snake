#include "SDL.h"
#include "Game/SnakeGame.h"

int main(int argc, char* argv[]) {
	Game* game = new SnakeGame();
	game->start();

	return 0;
}
