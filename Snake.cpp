#include <iostream>
#include "Snake.h"
#include "Draw.h"

using namespace std;

int dx[] = {  0, 1, 0, -1 };
int dy[] = { -1, 0, 1,  0 };

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

void Snake::drawSnake(RenderWindow& window) {
	for (int i = 1; i < body.size(); i++) {
		drawSquare(body[i].first * 50 + 5, body[i].second * 50 + 5, Color::Blue, window);
	}

	drawSquare(body[0].first * 50 + 5, body[0].second * 50 + 5, Color::Magenta, window);

}

void Snake::moveSnake(int direction) {
	for (int i = body.size() - 1; i > 0; i--) {
		body[i] = body[i - 1];
	}
	if ((direction - lastDirection == 2 || direction - lastDirection == -2) && body.size() > 1) {
		body[0].first += dx[lastDirection];
		body[0].second += dy[lastDirection];
	}
	else {
		body[0].first += dx[direction];
		body[0].second += dy[direction];

		lastDirection = direction;
	}
}

bool Snake::isEmpty(pair<int, int> cell) {
	for (int i = 0; i < body.size(); i++)
		if (body[i] == cell)
			return 0;
	return 1;
}

bool Snake::hasAteFood(pair<int, int> Food, int direction) {
	pair<int, int> endOfSnake = body[body.size() - 1];

	if (body[0] == Food) {
		switch (direction) {
		case UP:
			body.push_back(make_pair(endOfSnake.first + dx[DOWN], endOfSnake.second + dy[DOWN]));
			break;

		case RIGHT:
			body.push_back(make_pair(endOfSnake.first + dx[LEFT], endOfSnake.second + dy[LEFT]));
			break;

		case DOWN:
			body.push_back(make_pair(endOfSnake.first + dx[UP], endOfSnake.second + dy[UP]));
			break;

		case LEFT:
			body.push_back(make_pair(endOfSnake.first + dx[RIGHT], endOfSnake.second + dy[RIGHT]));
			break;
		} //end switch

		return true;
	} //end if

	return false;
}

bool Snake::hasLost() {
	for (int i = 1; i < body.size(); i++)
		if (body[0] == body[i])
			return true;

	if (body[0].first < 0 || body[0].first > 12)
		return true;

	if (body[0].second < 0 || body[0].second > 8)
		return true;

	return false;
}