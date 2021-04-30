#pragma once
#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include <SFML/Graphics.hpp>
#include "Food.h"

using namespace std;
using namespace sf;

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

/*
	direction = 0 -> UP
	direction = 1 -> RIGHT
	direction = 2 -> DOWN
	direction = 3 -> LEFT
*/



class Snake {
private:
	int lastDirection;
	pair<int, int> lastEndOfSnakePosition;

	Texture headTexture, bodyTexture;
	Sprite  headSprite, bodySprite;

	Color generateRandomColor();

public:
	Food food;
	vector<Piece> body;

	Snake();
	void drawSquare(int x, int y, Color color, RenderWindow& window, int size) {
		RectangleShape square(Vector2f(size - 5, size - 5));
		square.setFillColor(color);
		square.setPosition(x, y);

		window.draw(square);
	}
	void drawSnake(RenderWindow& window, int size);
	void moveSnake(int direction);
	bool isEmpty(pair<int, int> cell);
	bool hasAteFood(int N, int M);
	void addPieceToBody();
	bool hasLost(RenderWindow& window, int width, int height);
};
#endif // !SNAKE_H
