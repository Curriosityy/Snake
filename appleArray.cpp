#include "appleArray.h"



appleArray::appleArray()
{
}
void appleArray::addApple(int x,int y)
{
	Apple.rect.setPosition(sf::Vector2f(x, y));
	mapAppleArray.push_back(Apple);
}

void appleArray::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	for (size_t i = 0; i < mapAppleArray.size(); i++)
	{
		target.draw(mapAppleArray[i].rect);
	}
}
appleArray::~appleArray()
{
}
