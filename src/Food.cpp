#include "Food.h"

std::pair<int, int> Food::getPosition() {
	return this->position;
}

bool Food::isEmpty(const std::vector<std::pair<int, int>>& body, std::pair<int, int> cell) {
	for (int i = 0; i < body.size(); i++)
		if (body[i] == cell)
			return false;

	return true;
}

void Food::generateFood(const std::vector<std::pair<int, int>>& body, int N, int M) {
	std::pair<int, int> position;

	do {
		position.first = rand() % N, position.second = rand() % M;
	} while (!isEmpty(body, position));

	this->position = position;
}

void Food::setFood(std::pair<int, int> position) {
	this->position = position;
}

void Food::drawFood(sf::RenderWindow& window, int size) {
	drawSquare(position.first * size + 5, position.second * size + 5, sf::Color::Yellow, window, size);
}