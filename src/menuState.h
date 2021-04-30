#pragma once
#include "State.h"

class menuState : public State
{
private:
	sf::Text playText, exitText;
	bool isPressedPlay, isPressedExit;
	bool isSelectedPlay, isSelectedExit;

public:
	menuState(Game* game);
	void handleInput() override;
	void update(double) override;
	void draw(double) override;
};

