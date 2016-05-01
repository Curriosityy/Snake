#pragma once
#include <SFML\Graphics.hpp>
class snakePart
{
public:
	sf::RectangleShape rect;
	enum propablyDirection {UP,DOWN,LEFT,RIGHT};
	propablyDirection direction;
	snakePart();
	~snakePart();
};

