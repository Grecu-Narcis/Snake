#define NOMINMAX

#include <iostream>
#include <Windows.h>
#include "Draw.h"
#include "Snake.cpp"
#include "Game.cpp"

using namespace sf;
using namespace std;

RenderWindow window(VideoMode(605, 405), "Snake");

Snake mySnake;

pair<int, int> Food;
bool existFood;

auto windowSize = window.getSize();

Clock myClock;
Time myTime;


int main() {
	system("pause");

	window.setFramerateLimit(60);

	myTime = myClock.getElapsedTime();
	myClock.restart();

	RectangleShape square(Vector2f(45, 45));
	square.setFillColor(Color::Blue);
	square.setPosition(Vector2f(5, 5));

	int direction = 1;
	

	drawTable(window);
	mySnake.drawSnake(window);
	window.display();

	while (window.isOpen()) {
		myTime = myClock.getElapsedTime();


		if (myTime.asSeconds() > 0.25) {
			myClock.restart();

			Event event;


			while (window.pollEvent(event)) {
				if (event.type == Event::Closed)
					window.close();

				else if (event.type == Event::KeyPressed) {
					switch (event.key.code) {
					case Keyboard::Up:
						direction = 0;
						break;

					case Keyboard::Right:
						direction = 1;
						break;

					case Keyboard::Down:
						direction = 2;
						break;

					case Keyboard::Left:
						direction = 3;						 
						break;

					
					}//end switch

				}//end if - keyPressed

			}//end while - window.PollEvent

			if (!existFood) {
				existFood = true;
				do {
					Food = generateFood();
				} while (!mySnake.isEmpty(Food));
			}
			window.clear();

			drawTable(window);
			drawFood(Food, window);
			mySnake.moveSnake(direction);
			mySnake.drawSnake(window);

			if (mySnake.hasAteFood(Food, direction)) {
				existFood = false;
			}


			window.display();


			if (mySnake.hasLost())
				system("pause");

		}//end if - time > 0.3s

	}//end while - window is open

	return 0;
}