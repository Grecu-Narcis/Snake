//Creator Narcis Grecu

#define NOMINMAX

#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
#include "Draw.h"
#include "Snake.cpp"
#include "Game.cpp"
#include "Button.cpp"

using namespace sf;
using namespace std;

char filename[100] = "scor.txt";

int N = 18, M = 12;
int tileSize = 40;

int width = N * tileSize, height = M * tileSize + 70;

RenderWindow window(VideoMode(width + 5, height + 5), "Snake");

bool hasPressedStartButton, ok;

Clock myClock;

float timer;

int main(){
	Game game;

	window.setFramerateLimit(60);
	window.setKeyRepeatEnabled(false);

	int direction = 1;

	Button startButton = Button(300, 225, 100, 50, "Start");

	while (window.isOpen()) {
		Event event;

		if (!hasPressedStartButton) {
			while (window.pollEvent(event)) {
				if (event.type == Event::Closed)
					window.close();

				window.clear();
				startButton.display(window);

				if (startButton.isClicked(window)) {
					Sleep(200);
					hasPressedStartButton = 1;
				}

				window.display();
			}
		}

		else {

			timer += myClock.getElapsedTime().asSeconds();
			myClock.restart();


			while (window.pollEvent(event)) {
				if (event.type == Event::Closed)
					window.close();

				if (!game.getGameStatus()) {
					if (event.type == Event::KeyPressed) {
						switch (event.key.code) {
						case Keyboard::Up:
							if (direction != 0) {
								direction = 0;
								game.updateSnake(window, direction);
								game.displaySnake(window);
								timer = 0;
							}
							break;

						case Keyboard::Right:
							if (direction != 1) {
								direction = 1;
								game.updateSnake(window, direction);
								game.displaySnake(window);
								timer = 0;
							}
							break;

						case Keyboard::Down:
							if (direction != 2) {
								direction = 2;
								game.updateSnake(window, direction);
								game.displaySnake(window);
								timer = 0;
							}
							break;

						case Keyboard::Left:
							if (direction != 3) {
								direction = 3;
								game.updateSnake(window, direction);
								game.displaySnake(window);
								timer = 0;
							}
							break;


						}//sfarsit switch

					}//sfarsit if - keyPressed
				}
			}//sfarsit while - window.PollEvent

			if (!game.getGameStatus()) {
				if (timer > 0.2) {
					timer = 0;
					game.updateSnake(window, direction);
				}
			}
			window.clear();

			drawTable(window, tileSize);
			game.displayFood(window);
			game.displaySnake(window);
			game.displayScores(window);

			window.display();


			if (game.getGameStatus()) {
				game.setScoreText("You lost!");
				game.setHighScoreText("Your score: " + to_string(game.getScore())
									+ "\nHigh score: " + to_string(game.getHighScore()));

				game.updateHighScore(filename);
			}
		}
	}//sfarsit while - window is open

	return 0;
}
