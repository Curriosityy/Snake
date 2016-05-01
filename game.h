#pragma once
#include <SFML/Graphics.hpp>
#include <SFML\Audio.hpp>
#include "GameState.h"
#include "GameInfo.h"
#include "menu.h"
#include "engine.h"
class game
{
public:
	game();
	GameState gameState;
	sf::RenderWindow window;
	sf::Font font;
	void run();
	void runMenu();
	void runEngine();
	~game();
};

