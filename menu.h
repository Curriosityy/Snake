#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include "GameState.h"
#include "GameInfo.h"
class menu
{
public:
	sf::Font font;
	sf::RenderWindow *window;
	sf::Text text[3];
	GameState *gameState;


	menu(sf::Font font, sf::RenderWindow &window, GameState &gameState);
	void displayMenu();
	void updateMenu();
	void createText();
	~menu();
};

