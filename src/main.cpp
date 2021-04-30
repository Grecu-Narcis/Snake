#include "Game.h"
#include "menuState.h"
#include "playState.h"

using namespace std;

int main() {
	Game game;

	game.pushState(new menuState(&game));
	game.gameLoop();

	return 0;
}