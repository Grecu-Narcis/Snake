#include "Button.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

void Button::display(RenderWindow& window) {
	RectangleShape button;

	button.setPosition(Vector2f(x, y));
	button.setSize(Vector2f(width, height));
	button.setFillColor(Color::Green);
	button.setOutlineColor(Color::Yellow);
	button.setOutlineThickness(3);

	window.draw(button);
	window.draw(this->buttonText);
}

bool Button::isClicked(RenderWindow& window) {
	if (Mouse::isButtonPressed(Mouse::Left) == 0) {
		return false;
	}

	Vector2i position = Mouse::getPosition(window);

	if (position.x > x && position.x < x + width && position.y > y && position.y < y + height)
		return true;

	return false;
}


void Button::setText(String text) {
	buttonText.setString(text);
}


void Button::setPosition(double x, double y) {
	this->x = x;
	this->y = y;
}


void Button::setSize(double width, double height) {
	this->width = width;
	this->height = height;
}