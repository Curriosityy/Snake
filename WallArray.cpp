#include "WallArray.h"


WallArray::WallArray()
{
}

void WallArray::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	for (size_t i = 0; i < mapWallArray.size(); i++)
	{
		target.draw(mapWallArray[i].rect);
	}
}
void WallArray::addMap()
{
	for (size_t i = 1; i <= 2; i++)
	{
		for (size_t j = 1; j <= 3; j++)
		{
			wall.rect.setPosition(sf::Vector2f((GameInfo::length / 4)*j - wall.rect.getGlobalBounds().width, (GameInfo::height / 3)*i - wall.rect.getGlobalBounds().height));
			mapWallArray.push_back(wall);
		}
	}
}
WallArray::~WallArray()
{}
