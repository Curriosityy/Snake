#pragma once
#include <vector>
#include <SFML\Graphics.hpp>
#include "GameInfo.h"
#include "Wall.h"
class WallArray:
	public sf::Drawable, sf::Transformable
{
public:
	WallArray();
	std::vector<Wall> mapWallArray;
	Wall wall;
	void addMap();
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	~WallArray();
};

