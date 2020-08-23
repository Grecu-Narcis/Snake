#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Draw.h"

using namespace std;

pair<int, int> generateFood() {
	srand(time(0));
	int x, y;

	x = rand() % 12;
	y = rand() % 8;

	return make_pair(x, y);
}

void drawFood(pair<int, int> Food, RenderWindow& window) {
	drawSquare(Food.first * 50 + 5, Food.second * 50 + 5, Color::Green, window);
}