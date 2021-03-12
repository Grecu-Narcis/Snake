#include <SFML/Graphics.hpp>
#include <iostream>
#include "Draw.h"

using namespace std;
using namespace sf;

void drawHorizontalLine(int x, int y, RenderWindow& window) {
	RectangleShape line(Vector2f(window.getSize().x, 5));

	line.setPosition(x, y);
	line.setFillColor(Color::Red);

	window.draw(line);
}

void drawVerticalLine(int x, int y, RenderWindow& window) {
	RectangleShape line(Vector2f(5, window.getSize().y - 70));

	line.setPosition(x, y);
	line.setFillColor(Color::Red);

	window.draw(line);
}

void drawTable(RenderWindow& window, int size) {
	float scale = size / 50.;

	Vector2u windowSize = window.getSize();


	windowSize.y -= 70;

	windowSize.x /= size;
	windowSize.y /= size;

	for (int i = 0; i <= windowSize.x; i++)
		drawVerticalLine(size * i, 0, window);

	for (int i = 0; i <= windowSize.y; i++)
		drawHorizontalLine(0, size * i, window);
}

void drawSquare(int x, int y, Color color, RenderWindow& window, int size) {
	RectangleShape square(Vector2f(size - 5, size - 5));
	square.setFillColor(color);
	square.setPosition(x, y);

	window.draw(square);
}