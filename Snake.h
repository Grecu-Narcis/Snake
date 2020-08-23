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

public:
	Snake() {
		body.push_back(make_pair(0, 0));
	}

	void drawSnake(RenderWindow& window);
	void moveSnake(int direction);
	bool isEmpty(pair<int, int> cell);
	bool hasAteFood(pair<int, int> Food, int direction);
	bool hasLost();
};


#endif // !SNAKE_H
