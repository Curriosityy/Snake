#include "snakePart.h"



snakePart::snakePart()
{
	rect.setSize(sf::Vector2f(10, 10));
	rect.setPosition(sf::Vector2f(100, 100));
	direction = RIGHT;
}


snakePart::~snakePart()
{
}
