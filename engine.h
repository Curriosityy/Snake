#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include "GameState.h"
#include "GameInfo.h"
#include "snake.h"
#include "appleArray.h"
#include "WallArray.h"
#include <random>
class engine
{
public:
	sf::Font font;
	sf::RenderWindow *window;
	sf::Text text;
	sf::Event event;
	GameState *gameState;
	snake Snake;
	appleArray Apple;
	WallArray map;
	int counter = 0;
	bool pause = false;
	bool containFlag = false;
	engine(sf::Font font, sf::RenderWindow &window, GameState &gameState);
	void isOutOfScreen();
	void collisionWithApple();
	void collisionWithSnake();
	void collisionWithWall();
	int randomizer(int positon);
	void drawPoints();
	void displayGame();
	void gameOver();
	void WallContainApple();
	~engine();
};

