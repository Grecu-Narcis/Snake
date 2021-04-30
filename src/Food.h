#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

extern vector <Texture> textures;

struct Piece {
	pair<int, int> position;
	Sprite sprite;
};

class Food
{
private:
	Piece food;
	Texture foodTexture;

public:
	Food();

	std::pair<int, int> getPosition();
	bool isEmpty(const std::vector<Piece>& body, std::pair<int, int> cell);
	void generateFood(const std::vector<Piece>& body, int N, int M);
	void setFood(std::pair<int, int> position);
	void drawFood(sf::RenderWindow& window, int size);
	Color getColor();
};

