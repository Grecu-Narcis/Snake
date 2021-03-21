#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Board {
public:
	void drawHorizontalLine(int x, int y, RenderWindow& window);
	void drawVerticalLine(int x, int y, RenderWindow& window);
	void drawTable(RenderWindow& window, int tileSize);
};