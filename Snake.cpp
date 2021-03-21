#include "Snake.h"
#include "Draw.h"
#include <iostream>

using namespace std;

int dx[] = {  0, 1, 0, -1 };
int dy[] = { -1, 0, 1,  0 };

Snake::Snake() {
	lastDirection = LEFT;
	body.push_back(make_pair(0, 0));
	lastEndOfSnakePosition = make_pair(0, 0);
}

void Snake::drawSnake(RenderWindow& window, int size) {
	for (int i = 1; i < body.size(); i++) {
		drawSquare(body[i].first * size + 5, body[i].second * size + 5, Color::Blue, window, size);
	}

	drawSquare(body[0].first * size + 5, body[0].second * size + 5, Color::Green, window, size);
}

void Snake::moveSnake(int direction) {
	lastEndOfSnakePosition = body[body.size() - 1];

	for (int i = body.size() - 1; i > 0; i--) {
		body[i] = body[i - 1];
	}

	if (abs(direction - lastDirection) == 2 && body.size() > 1) {
		body[0].first  += dx[lastDirection];
		body[0].second += dy[lastDirection];
	}

	else {
		body[0].first  += dx[direction];
		body[0].second += dy[direction];

		lastDirection = direction;
	}
}

bool Snake::isEmpty(pair<int, int> cell) {
	for (int i = 0; i < body.size(); i++)
		if (body[i] == cell)
			return false;
	return true;
}

bool Snake::hasAteFood(int N, int M) {
	if (body[0] == food.getPosition()) {
		food.generateFood(body, N, M);
		return true;
	}

	return false;
}

void Snake::addPieceToBody() {
	body.push_back(lastEndOfSnakePosition);
}

bool Snake::hasLost(RenderWindow& window, int size) {
	for (int i = 1; i < body.size(); i++)
		if (body[0] == body[i])
			return true;

	Vector2u windowSize = window.getSize();
	windowSize.y -= 40;

	windowSize.x /= size;
	windowSize.y /= size;

	if (body[0].first < 0  || body[0].first >= windowSize.x)
		return true;

	if (body[0].second < 0 || body[0].second >= windowSize.y)
		return true;

	return false;
}