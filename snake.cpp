#include "snake.h"


snake::snake()
{
	snakeSize = 1;
	part.rect.setFillColor(sf::Color::Green);
	snakePartArray.push_back(part);
	addSnakePart();	
	addSnakePart();
	points = 0;
}
void snake::addSnakePart()
{
	
	snakePartArray.push_back(part);
	snakeSize++;
	switch (snakePartArray[snakeSize -2].direction)
	{
	case snakePart::LEFT:
		snakePartArray[snakeSize - 1].direction = snakePartArray[snakeSize - 2].direction;
		snakePartArray[snakeSize - 1].rect.setPosition(snakePartArray[snakeSize - 2].rect.getPosition().x + GameInfo::SizeOnePart, snakePartArray[snakeSize - 2].rect.getPosition().y);
		break;
	case snakePart::RIGHT:
		snakePartArray[snakeSize - 1].direction = snakePartArray[snakeSize - 2].direction;
		snakePartArray[snakeSize - 1].rect.setPosition(snakePartArray[snakeSize - 2].rect.getPosition().x - GameInfo::SizeOnePart, snakePartArray[snakeSize - 2].rect.getPosition().y);
		break;
	case snakePart::UP:
		snakePartArray[snakeSize - 1].direction = snakePartArray[snakeSize - 2].direction;
		snakePartArray[snakeSize - 1].rect.setPosition(snakePartArray[snakeSize - 2].rect.getPosition().x, snakePartArray[snakeSize - 2].rect.getPosition().y + GameInfo::SizeOnePart);

		break;
	case snakePart::DOWN:
		snakePartArray[snakeSize - 1].direction = snakePartArray[snakeSize - 2].direction;
		snakePartArray[snakeSize - 1].rect.setPosition(snakePartArray[snakeSize - 2].rect.getPosition().x, snakePartArray[snakeSize - 2].rect.getPosition().y - GameInfo::SizeOnePart);
		break;
	}
}

void snake::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	for (size_t i = 0; i < snakeSize; i++)
	{
		target.draw(snakePartArray[i].rect);
	}
}
void snake::changeDirection(int a)
{
	switch (a)
	{
	case 1:		
		if (snakePartArray[1].direction != snakePart::RIGHT)
		{
			snakePartArray[0].direction = snakePart::LEFT;
		}
		break;
	case 2:
		if (snakePartArray[1].direction != snakePart::LEFT)
		{
			snakePartArray[0].direction = snakePart::RIGHT;
		}
		break;
	case 3:
		if (snakePartArray[1].direction != snakePart::DOWN)
		{
			snakePartArray[0].direction = snakePart::UP;
		}
		break;
	case 4:
		if (snakePartArray[1].direction != snakePart::UP)
		{
			snakePartArray[0].direction = snakePart::DOWN;
		}
		break;
	}
}
void snake::moveSnake()
{
/*	for (size_t i = snakeSize - 1; i > 0; --i)
	{
		snakePartArray[i] = snakePartArray[i - 1];
	}
	switch (snakePartArray[0].direction)
	{
	case snakePart::LEFT:
		snakePartArray[0].rect.move(-GameInfo::SizeOnePart, 0);
		break;
	case snakePart::RIGHT:
		snakePartArray[0].rect.move(GameInfo::SizeOnePart, 0);
		break;
	case snakePart::UP:
		snakePartArray[0].rect.move(0, -GameInfo::SizeOnePart);
		break;
	case snakePart::DOWN:
		snakePartArray[0].rect.move(0, GameInfo::SizeOnePart);
		break;
	}
*/
	snakePartArray[snakeSize - 1] = snakePartArray[0];
	snakePartArray.push_front(snakePartArray[snakeSize - 1]);
	snakePartArray.pop_back();
	switch (snakePartArray[1].direction)
	{
	case snakePart::LEFT:
		snakePartArray[0].rect.move(-GameInfo::SizeOnePart, 0);
		break;
	case snakePart::RIGHT:
		snakePartArray[0].rect.move(GameInfo::SizeOnePart, 0);
		break;
	case snakePart::UP:
		snakePartArray[0].rect.move(0, -GameInfo::SizeOnePart);
		break;
	case snakePart::DOWN:
		snakePartArray[0].rect.move(0, GameInfo::SizeOnePart);
		break;
	}
}
snake::~snake()
{
}
