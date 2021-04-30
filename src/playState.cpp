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

	if (file.peek() == EOF) {
		file.close();
		return false;
	}

	file >> highScore;

	file.close();

	return true;
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
					if (direction != UP)
						moves.push(UP);
					
					direction = UP;
					break;

				case sf::Keyboard::W:
					if (direction != UP)
						moves.push(UP);

					direction = UP;
					break;
			
				case sf::Keyboard::Down:
					if (direction != DOWN)
						moves.push(DOWN);
					
					direction = DOWN;
					break;

				case sf::Keyboard::S:
					if (direction != DOWN)
						moves.push(DOWN);

					direction = DOWN;
					break;

				case sf::Keyboard::Left:
					if (direction != LEFT)
						moves.push(LEFT);

					direction = LEFT;
					break;

				case sf::Keyboard::A:
					if (direction != LEFT)
						moves.push(LEFT);

					direction = LEFT;
					break;

				case sf::Keyboard::Right:
					if (direction != RIGHT)
						moves.push(RIGHT);

					direction = RIGHT;
					break;

				case sf::Keyboard::D:
					if (direction != RIGHT)
						moves.push(RIGHT);

					direction = RIGHT;
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

	if (snake.hasLost(game->window, game->getWidthTiles(), game->getHeightTiles())) {
		if (score > highScore) {
			ofstream file("scor.txt");
			file << score;
			file.close();
		}

		game->popState();
		game->pushState(new gameOverState(game));
	}

	if (snake.hasAteFood(game->getWidthTiles(), game->getHeightTiles())) {
		snake.addPieceToBody();
		snake.food.generateFood(snake.body, game->getWidthTiles(), game->getHeightTiles());
		score++;
		scoreText.setString("Your score: " + to_string(score));

		if (score > highScore) 
			highScoreText.setString("High score: " + to_string(score));
	}
}

void playState::draw(double dt) {
	board.drawTable(game->window, game->getWidthTiles(), game->getHeightTiles(), game->getSize());
	snake.drawSnake(game->window, game->getSize());
	snake.food.drawFood(game->window, game->getSize());
	game->window.draw(scoreText);
	game->window.draw(highScoreText);
}