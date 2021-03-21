#include "gameOverState.h"
#include "playState.h"

gameOverState::gameOverState(Game* game) {
	this->game = game;
	isPressedPlayAgain = false, isPressedQuitGame = false;
	isSelectedPlayAgain = true, isSelectedQuitGame = false;

	gameOverText.setFont(game->font);
	gameOverText.setFillColor(sf::Color::White);
	gameOverText.setString("Game over!");
	gameOverText.setCharacterSize(50);
	gameOverText.setOrigin(gameOverText.getLocalBounds().width / 2,
						   gameOverText.getLocalBounds().height / 2);
	gameOverText.setPosition(game->window.getSize().x / 2,
							 game->window.getSize().y / 2 - 100);

	playAgainText.setFont(game->font);
	playAgainText.setFillColor(sf::Color::White);
	playAgainText.setString("Play again");
	playAgainText.setCharacterSize(40);
	playAgainText.setOrigin(playAgainText.getLocalBounds().width / 2, 
							playAgainText.getLocalBounds().height / 2);
	playAgainText.setPosition(game->window.getSize().x / 2,
							  game->window.getSize().y / 2);

	quitGameText.setFont(game->font);
	quitGameText.setFillColor(sf::Color::White);
	quitGameText.setString("Quit game");
	quitGameText.setCharacterSize(40);
	quitGameText.setOrigin(quitGameText.getLocalBounds().width / 2,
						   quitGameText.getLocalBounds().height / 2);
	quitGameText.setPosition(game->window.getSize().x / 2,
							  game->window.getSize().y / 2 + 50);
}

void gameOverState::handleInput() {
	sf::Event event;
	while (game->window.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			game->window.close();

		if (event.type == sf::Event::KeyPressed) {
			switch (event.key.code) {
				case sf::Keyboard::Up:
					if (isSelectedQuitGame) {
						isSelectedQuitGame = false;
						isSelectedPlayAgain = true;
					}
					break;

				case sf::Keyboard::Down:
					if (isSelectedPlayAgain) {
						isSelectedQuitGame = true;
						isSelectedPlayAgain = false;
					}
					break;

				case sf::Keyboard::Enter:
					if (isSelectedPlayAgain)
						isPressedPlayAgain = true;
					else
						isPressedQuitGame = true;
					break;
			}
		}

		break;
	}
}

void gameOverState::update(double dt) {
	playAgainText.setFillColor(sf::Color::White);
	quitGameText.setFillColor(sf::Color::White);
	
	if (isSelectedPlayAgain) {
		playAgainText.setFillColor(sf::Color::Blue);
	}

	if (isSelectedQuitGame) {
		quitGameText.setFillColor(sf::Color::Blue);
	}

	if (isPressedPlayAgain) {
		game->popState();
		game->pushState(new playState(game));
	}

	if (isPressedQuitGame) {
		game->window.close();
	}
}

void gameOverState::draw(double dt) {
	game->window.draw(gameOverText);
	game->window.draw(playAgainText);
	game->window.draw(quitGameText);
}