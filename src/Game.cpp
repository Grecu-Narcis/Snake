#include "Game.h"
#include "State.h"
#include "menuState.h"


Game::Game() {
	height = 10, width = 20, size = 32;
	window.create(sf::VideoMode(width * size, height * size + 40), "Snake");
	window.setFramerateLimit(60);
	font.loadFromFile("fonts/NotoSans-Bold.ttf");
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

		window.clear(sf::Color(161, 161, 161));
		
		getState()->draw(dt);

		window.display();
	}
}

int Game::getSize() {
	return this->size;
}

int Game::getWidthTiles() {
	return this->width;
}

int Game::getHeightTiles() {
	return this->height;
}
