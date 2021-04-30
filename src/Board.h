#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Board {
private:
	Texture boardTexture;
	Sprite boardSprite;

public:
	Board();
	void drawHorizontalLine(int x, int y, RenderWindow& window);
	void drawVerticalLine(int x, int y, RenderWindow& window);
	void drawTable(RenderWindow& window, int width, int height, int size);
};