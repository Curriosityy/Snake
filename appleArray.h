#pragma once
//#include <vector>
#include "apple.h"
#include <SFML\Graphics.hpp>


class appleArray:
	public sf::Drawable, sf::Transformable

{
public:
	std::vector<apple>::const_iterator appleIterator;
	std::vector<apple> mapAppleArray;
	apple Apple;
	void addApple(int x,int y);
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	appleArray();
	~appleArray();
};

