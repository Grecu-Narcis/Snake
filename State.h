#pragma once
#include "Game.h"

class State {
public:
	Game* game;

	virtual void handleInput() = 0;
	virtual void update(double) = 0;
	virtual void draw(double) = 0;
};
