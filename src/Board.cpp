#include <SFML/Graphics.hpp>
#include <iostream>
#include "Board.h"

using namespace std;
using namespace sf;

void Board::drawHorizontalLine(int x, int y, RenderWindow& window) {
	RectangleShape line(Vector2f(window.getSize().x, 5));

	line.setPosition(x, y);
	line.setFillColor(Color::Red);

	window.draw(line);
}

void Board::drawVerticalLine(int x, int y, RenderWindow& window) {
	RectangleShape line(Vector2f(5, window.getSize().y - 40));

	line.setPosition(x, y);
	line.setFillColor(Color::Red);

	window.draw(line);
}

void Board::drawTable(RenderWindow& window, int size) {
	Vector2u windowSize = window.getSize();
	windowSize.y -= 40;

	windowSize.x /= size;
	windowSize.y /= size;

	for (int i = 0; i <= windowSize.x; i++)
		drawVerticalLine(size * i, 0, window);

	for (int i = 0; i <= windowSize.y; i++)
		drawHorizontalLine(0, size * i, window);
}