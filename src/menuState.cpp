#include "menuState.h"
#include "playState.h"

menuState::menuState(Game* game) {
	this->game = game;
	this->isSelectedPlay = true;
	
	playText.setFont(this->game->font);
	playText.setString("Play");
	playText.setFillColor(sf::Color::Blue);
	playText.setCharacterSize(40);
	
	playText.setOrigin(playText.getLocalBounds().width / 2,
					   playText.getLocalBounds().height / 2);
	
	playText.setPosition(this->game->window.getSize().x / 2,
						 this->game->window.getSize().y / 2 - 25);

	exitText = playText;
	exitText.setOrigin(exitText.getLocalBounds().width / 2,
					   exitText.getLocalBounds().height / 2);
	
	exitText.setPosition(this->game->window.getSize().x / 2 + 3,
						 this->game->window.getSize().y / 2 + 25);

	exitText.setString("Exit");
}

void menuState::handleInput() {
	sf::Event event;

	while (game->window.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			game->window.close();

		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Enter) {
				if (isSelectedPlay)
					isPressedPlay = true;

				else isPressedExit = true;
			}

			else if (event.key.code == sf::Keyboard::Down && isSelectedPlay) {
				isSelectedPlay = false;
				isSelectedExit = true;
			}

			else if (event.key.code == sf::Keyboard::Up && isSelectedExit) {
				isSelectedPlay = true;
				isSelectedExit = false;
			}
		}

		break;
	}
}

void menuState::update(double dt) {
	playText.setFillColor(sf::Color::White);
	exitText.setFillColor(sf::Color::White);

	if (isSelectedPlay)
		playText.setFillColor(sf::Color::Blue);

	if (isSelectedExit)
		exitText.setFillColor(sf::Color::Blue);

	if (isPressedPlay) {
		isPressedPlay = 0;
		game->pushState(new playState(game));
	}
	if (isPressedExit)
		game->window.close();
}

void menuState::draw(double dt) {
	game->window.draw(playText);
	game->window.draw(exitText);
}