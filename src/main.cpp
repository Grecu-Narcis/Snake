#include "Game.h"
#include "menuState.h"
#include "playState.h"

int main() {
	Game game;

	game.pushState(new menuState(&game));
	game.gameLoop();

	return 0;
}