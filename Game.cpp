#include "Game.h"

using namespace std;

Game::Game() {
	width = N * tileSize, height = M * tileSize + 70;
	generateFood();
	loadHighScore("scor.txt");
	font.loadFromFile("arial.ttf");
	scoreText.setFillColor(Color::White);
	scoreText.setFont(font);
	scoreText.setCharacterSize(30);
	scoreText.setPosition(Vector2f(0, height - 70));
	scoreText.setString("Your score: " + to_string(score));

	highScoreText = scoreText;
	highScoreText.setPosition(Vector2f(width - 240, height - 70));
	highScoreText.setString("High score: " + to_string(highScore));
}



void Game::generateFood() {
	srand(time(0));
	int x, y;

	do {
		x = rand() % 12;
		y = rand() % 8;
	} while (!snake.isEmpty({ x, y }));

	food = make_pair(x, y);
}

pair<int, int> Game::getFood() {
	return food;
}

void Game::displayFood(RenderWindow& window) {
	drawSquare(food.first * tileSize + 5, food.second * tileSize + 5, Color::Yellow, window, tileSize);
}

void Game::loadHighScore(string path) {
	ifstream file(path);
	if (file.peek() == EOF)
		highScore = 0;
	else
		file >> highScore;

	file.close();
}

void Game::updateScore() {
	score++;

	setScoreText("Your score: " + to_string(score));

	if (score > highScore) {
		highScore = score;
		setHighScoreText("High score: " + to_string(highScore));
	}
}

void Game::updateHighScore(string path) {
	ofstream file(path);
	file << highScore;
	file.close();
}

void Game::displayScores(RenderWindow& window) {
	window.draw(scoreText);
	window.draw(highScoreText);
}


void Game::displaySnake(RenderWindow& window) {
	snake.drawSnake(window, tileSize);
}

void Game::updateSnake(RenderWindow& window, int direction) {
	snake.moveSnake(direction);

	if (snake.hasLost(window, tileSize))
		gameOver = true;

	else if (snake.hasAteFood(food)) {
		snake.addPieceToBody();
		generateFood();
		updateScore();
	}
}

bool Game::getGameStatus() {
	return gameOver;
}

void Game::setScoreText(string s) {
	scoreText.setString(s);
}

void Game::setHighScoreText(string s) {
	highScoreText.setString(s);
}

int Game::getScore() {
	return score;
}

int Game::getHighScore() {
	return highScore;
}
