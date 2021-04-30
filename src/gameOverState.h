#pragma once
#include "State.h"


class gameOverState : public State
{
private:
	sf::Text gameOverText, playAgainText, quitGameText;
	bool isPressedPlayAgain, isPressedQuitGame;
	bool isSelectedPlayAgain, isSelectedQuitGame;

public:
	gameOverState(Game* game);
	void handleInput() override;
	void update(double) override;
	void draw(double) override;
};

