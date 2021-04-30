#include <SFML/Graphics.hpp>
#include <iostream>
#include "Board.h"

using namespace std;
using namespace sf;

Board::Board() {
	boardTexture.loadFromFile("textures/white.png");
	boardSprite.setTexture(boardTexture);
	boardSprite.setScale(2, 2);
}

void Board::drawTable(RenderWindow& window, int width, int height, int size) {
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++) {
			boardSprite.setPosition(j * size, i * size);
			window.draw(boardSprite);
		}
}