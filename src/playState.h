#pragma once
#include "State.h"
#include "Board.h"
#include "Snake.h"
#include <queue>

class playState : public State
{
private:
	Board board;
	Snake snake;
	int direction, score, highScore;
	double timeElapsed;
	queue<int> moves;
	sf::Text scoreText, highScoreText;

public:
	playState(Game* game);
	~playState();

	bool loadFromFile();

	void handleInput() override;
	void update(double) override;
	void draw(double) override;
};

