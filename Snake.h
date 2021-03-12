#pragma once
#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Snake {
private:
	int lastDirection;
	vector<pair<int, int>> body;
	pair<int, int> lastEndOfSnakePosition;

public:
	Snake() {
		lastDirection = 3;
		body.push_back(make_pair(0, 0));
		lastEndOfSnakePosition = make_pair(0, 0);
	}

	void drawSnake(RenderWindow& window, int size);
	void moveSnake(int direction);
	bool isEmpty(pair<int, int> cell);
	bool hasAteFood(pair<int, int> Food);
	void addPieceToBody();
	bool hasLost(RenderWindow& window, int size);
};


#endif // !SNAKE_H
