#include "game.h"



game::game()
{
	window.create(sf::VideoMode(GameInfo::length, GameInfo::height,32), "Snake"/*,::Style::Fullscreen*/);
	if (!font.loadFromFile("Sabo-Regular.otf"))
	{
	}
}

void game::run()
{
	while (window.isOpen())
	{
		window.setFramerateLimit(60);
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		switch (gameState.State)
		{

		case GameState::PLAY:
			runEngine();
			break;
		case GameState::MENU:
			runMenu();
			break;
		case GameState::EXIT:
			window.close();
			break;
		}
		//window.clear();


		//window.display();
	}
}
void game::runMenu()
{
	menu menu1(font,window,gameState);
	menu1.displayMenu();
}
void game::runEngine()
{
	engine engine1(font, window, gameState);
	engine1.displayGame();
}
game::~game()
{
}
