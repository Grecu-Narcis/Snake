#pragma once
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include "Draw.h"
#include "Snake.h"

class Game {
private:
	int N = 18, M = 12;
	int highScore = 0, score = 0, height, width, tileSize = 40;
	Snake snake;
	Font font;
	Text scoreText, highScoreText;
	bool gameOver = false;
	
	pair<int, int> food;

public:
	Game();
	void generateFood();
	pair<int, int> getFood();
	void displayFood(RenderWindow& window);
	void loadHighScore(string);
	void updateScore();
	void updateHighScore(string);
	void displayScores(RenderWindow& window);
	void displaySnake(RenderWindow& window);
	void updateSnake(RenderWindow&, int);
	bool getGameStatus();
	void setScoreText(string);
	void setHighScoreText(string);
	int getScore();
	int getHighScore();
};