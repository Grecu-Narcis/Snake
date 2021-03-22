#include "playState.h"
#include "gameOverState.h"
#include <fstream>

playState::playState(Game* game) {
	score = 1;

	if (!loadFromFile())
		highScore = 1;
	
	this->game = game;
	direction = RIGHT;
	snake.food.generateFood(snake.body, game->getWidthTiles(), game->getHeightTiles());
	
	scoreText.setFont(game->font);
	scoreText.setString("Your score: " + to_string(score));
	scoreText.setCharacterSize(30);
	scoreText.setFillColor(sf::Color::White);
	scoreText.setPosition(5, game->window.getSize().y - 42);

	highScoreText = scoreText;
	highScoreText.setString("High score: " + to_string(highScore));
	highScoreText.setPosition(game->window.getSize().x - 235, game->window.getSize().y - 42);
}

playState::~playState() {
}

bool playState::loadFromFile() {
	ifstream file("scor.txt");

	if (file.peek() == EOF)
		return false;

	file >> highScore;

	file.close();
}

void playState::handleInput() {
	Event event;

	while (game->window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			game->window.close();
			break;
		}

		if (event.type == sf::Event::KeyPressed) {
			switch (event.key.code) {
				case sf::Keyboard::Up:
					direction = UP;
					moves.push(UP);
					break;

				case sf::Keyboard::W:
					direction = UP;
					moves.push(UP);
					break;
			
				case sf::Keyboard::Down:
					direction = DOWN;
					moves.push(DOWN);
					break;

				case sf::Keyboard::S:
					direction = DOWN;
					moves.push(DOWN);
					break;

				case sf::Keyboard::Left:
					direction = LEFT;
					moves.push(LEFT);
					break;

				case sf::Keyboard::A:
					direction = LEFT;
					moves.push(LEFT);
					break;

				case sf::Keyboard::Right:
					direction = RIGHT;
					moves.push(RIGHT);
					break;

				case sf::Keyboard::D:
					direction = RIGHT;
					moves.push(RIGHT);
					break;
			}
		}

		break;
	}
}

void playState::update(double dt) {
	timeElapsed += dt;

	if (timeElapsed > 0.15) {
		if (!moves.empty()) {
			direction = moves.front();
			moves.pop();
		}

		snake.moveSnake(direction);
		timeElapsed = 0;
	}

	if (snake.hasLost(game->window, game->getSize())) {
		ofstream file("scor.txt");
		file << highScore;
		file.close();

		game->popState();
		game->pushState(new gameOverState(game));
	}

	if (snake.hasAteFood(game->getWidthTiles(), game->getHeightTiles())) {
		snake.addPieceToBody();
		score++;
		scoreText.setString("Your score: " + to_string(score));

		if (score > highScore)
			highScoreText.setString("High score: " + to_string(score));
	}
}

void playState::draw(double dt) {
	board.drawTable(game->window, game->getSize());
	snake.drawSnake(game->window, game->getSize());
	snake.food.drawFood(game->window, game->getSize());
	game->window.draw(scoreText);
	game->window.draw(highScoreText);
}