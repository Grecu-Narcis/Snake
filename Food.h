#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Food
{
private:
	std::pair<int, int> position;

public:
	std::pair<int, int> getPosition();
	void drawSquare(int x, int y, Color color, RenderWindow& window, int size) {
		RectangleShape square(Vector2f(size - 5, size - 5));
		square.setFillColor(color);
		square.setPosition(x, y);

		window.draw(square);
	}
	bool isEmpty(const std::vector<std::pair<int, int>>& body, std::pair<int, int> cell);
	void generateFood(const std::vector<std::pair<int, int>>& body, int N, int M);
	void setFood(std::pair<int, int> position);
	void drawFood(sf::RenderWindow& window, int size);
};

