#include "Snake.h"
#include "Board.h"
#include <iostream>

using namespace std;

int dx[] = {  0, 1, 0, -1 };
int dy[] = { -1, 0, 1,  0 };

Snake::Snake() {
	lastDirection = LEFT;
	
	Piece head;
	head.position.first = head.position.second = 0;
	head.sprite.setTexture(headTexture);

	body.push_back(head);

	lastEndOfSnakePosition = make_pair(0, 0);

	headTexture.loadFromFile("textures/green.png");
	bodyTexture.loadFromFile("textures/red.png");

	headSprite.setTexture(headTexture);
	headSprite.setScale(2, 2);

	bodySprite.setTexture(bodyTexture);
	bodySprite.setScale(2, 2);
}

void Snake::drawSnake(RenderWindow& window, int size) {
	for (int i = 1; i < body.size(); i++) {
		body[i].sprite.setPosition(body[i].position.first * size, body[i].position.second * size);
		window.draw(body[i].sprite);

	}

	headSprite.setPosition(body[0].position.first * size, body[0].position.second * size);
	window.draw(headSprite);
}

void Snake::moveSnake(int direction) {
	lastEndOfSnakePosition = body[body.size() - 1].position;

	for (int i = body.size() - 1; i > 0; i--) {
		body[i].position = body[i - 1].position;
	}

	if (abs(direction - lastDirection) == 2 && body.size() > 1) {
		body[0].position.first  += dx[lastDirection];
		body[0].position.second += dy[lastDirection];
	}

	else {
		body[0].position.first  += dx[direction];
		body[0].position.second += dy[direction];

		lastDirection = direction;
	}
}

bool Snake::isEmpty(pair<int, int> cell) {
	for (int i = 0; i < body.size(); i++)
		if (body[i].position == cell)
			return false;
	return true;
}

bool Snake::hasAteFood(int N, int M) {
	if (body[0].position == food.getPosition())
		return true;

	return false;
}

void Snake::addPieceToBody() {
	Piece newPiece;

	newPiece.position = lastEndOfSnakePosition;
	newPiece.sprite.setTexture(bodyTexture);
	newPiece.sprite.setScale(2, 2);

	body.push_back(newPiece);
}

bool Snake::hasLost(RenderWindow& window, int width, int height) {
	for (int i = 1; i < body.size(); i++)
		if (body[0].position == body[i].position)
			return true;

	if (body[0].position.first < 0  || body[0].position.first >= width)
		return true;

	if (body[0].position.second < 0 || body[0].position.second >= height)
		return true;

	return false;
}

Color Snake::generateRandomColor() {
	int r, g, b;
	r = rand() % 256;
	g = rand() % 256;
	b = rand() % 256;

	return Color(r, g, b);
}

