#include <SFML/Graphics.hpp>
#include "Draw.h"

using namespace sf;

void drawHorizontalLine(int x, int y, RenderWindow& window) {
	RectangleShape line(Vector2f(605, 5));

	line.setPosition(x, y);
	line.setFillColor(Color::Red);

	window.draw(line);
}

void drawVerticalLine(int x, int y, RenderWindow& window) {
	RectangleShape line(Vector2f(5, 405));

	line.setPosition(x, y);
	line.setFillColor(Color::Red);

	window.draw(line);
}

void drawTable(RenderWindow &window) {
	for (int i = 0; i < 13; i++)
		drawVerticalLine(50 * i, 0, window);

	for (int i = 0; i < 9; i++)
		drawHorizontalLine(0, 50 * i, window);
}

void drawSquare(int x, int y, Color color, RenderWindow& window) {
	RectangleShape square(Vector2f(45, 45));
	square.setFillColor(color);
	square.setPosition(x, y);

	window.draw(square);
}