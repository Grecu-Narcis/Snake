#include "Game.h"
#include "State.h"
#include "menuState.h"


Game::Game() {
	N = 20, M = 10, size = 40;
	window.create(sf::VideoMode(N * size + 5, M * size + 5 + 40), "Snake");
	window.setFramerateLimit(60);
	font.loadFromFile("NotoSans-Bold.ttf");
}

void Game::pushState(State* state) {
	states.push(state);
}

void Game::popState() {
	if (!states.empty())
		states.pop();
}

void Game::changeState(State* state) {
	if (!states.empty())
		states.pop();

	pushState(state);
}

State* Game::getState() {
	if (!states.empty())
		return states.top();
	return NULL;
}

void Game::gameLoop() {
	sf::Clock clock;

	while (window.isOpen()) {
		sf::Time elapsed = clock.restart();

		double dt = elapsed.asSeconds();

		if (getState() == NULL) {
			continue;
		}

		getState()->handleInput();
		getState()->update(dt);

		window.clear();
		
		getState()->draw(dt);

		window.display();
	}
}

int Game::getSize() {
	return this->size;
}

int Game::getWidthTiles() {
	return this->N;
}

int Game::getHeightTiles() {
	return this->M;
}
