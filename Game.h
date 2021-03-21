#pragma once
#include <stack>
#include <SFML/Graphics.hpp>
#include <iostream>

class State;

class Game
{
private:
	std::stack<State*> states;
	int N, M, size;

public:
	sf::Font font;
	sf::RenderWindow window;
	Game();
	void pushState(State*);
	void popState();
	void changeState(State*);
	State* getState();

	void gameLoop();
	int getSize();
	int getWidthTiles();
	int getHeightTiles();
};

