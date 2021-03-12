#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

class Button
{
private:
	double x = 100, y = 100, width = 150, height = 50;


public:
	Text buttonText;
	Font font;
	Button() {
		font.loadFromFile("arial.ttf");

		buttonText.setFont(font);
		buttonText.setPosition(Vector2f(x + 10, y + 4));
		buttonText.setFillColor(Color::Red);
		buttonText.setCharacterSize(30);
		buttonText.setStyle(Text::Bold);
	}

	Button(double x, double y, double width, double height, String text) {
		font.loadFromFile("arial.ttf");

		buttonText.setFont(font);
		buttonText.setPosition(Vector2f(x + 10, y + 4));
		buttonText.setFillColor(Color::Red);
		buttonText.setCharacterSize(30);
		buttonText.setString(text);
		buttonText.setStyle(Text::Bold);

		this->x = x;
		this->y = y;
		this->width = width;
		this->height = height;
	}

	void display(RenderWindow& window);
	bool isClicked(RenderWindow& window);
	void setText(String text);
	void setPosition(double x, double y);
	void setSize(double width, double height);

};