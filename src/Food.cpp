#include "Food.h"

Food::Food() {
	foodTexture.loadFromFile("pink.png");
	
	food.sprite.setTexture(foodTexture);
	food.sprite.scale(2, 2);
}

std::pair<int, int> Food::getPosition() {
	return this->food.position;
}

bool Food::isEmpty(const std::vector<Piece>& body, std::pair<int, int> cell) {
	for (int i = 0; i < body.size(); i++)
		if (body[i].position == cell)
			return false;

	return true;
}

void Food::generateFood(const std::vector<Piece>& body, int N, int M) {
	std::pair<int, int> position;

	do {
		position.first = rand() % N, position.second = rand() % M;
	} while (!isEmpty(body, position));

	this->food.position = position;
	
}

void Food::drawFood(sf::RenderWindow& window, int size) {
	food.sprite.setPosition(food.position.first * size, food.position.second * size);
	window.draw(food.sprite);
}