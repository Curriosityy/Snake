#pragma once
#include <SFML\Graphics.hpp>
#include "snakePart.h"
#include "GameInfo.h"
#include <deque>

class snake: 
	public sf::Drawable, sf::Transformable
{
public:

	snake(); 
	std::deque<snakePart> snakePartArray;
	std::deque<snakePart>::const_iterator snakePartIterator;
	snakePart part;
	int points;
	int snakeSize;
	void addSnakePart();
	void moveSnake();
	void changeDirection(int a);
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	~snake();
};

