#include "menu.h"

menu::menu(sf::Font font, sf::RenderWindow &window, GameState &gameState)
{
	this->font = font;
	this->window = &window;
	this->gameState = &gameState;

}
void menu::displayMenu()
{	
	createText();
	while (gameState->State==GameState::MENU)
	{
		sf::Vector2f mouse(sf::Mouse::getPosition(*window));
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				gameState->State = GameState::EXIT;
			if (event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
			{
				if (text[1].getGlobalBounds().contains(mouse))
				{
					gameState->State = GameState::PLAY;
				}
				if (text[2].getGlobalBounds().contains(mouse))
				{
					gameState->State = GameState::EXIT;
				}
			}
		}
		updateMenu();
		window->clear();
		for (size_t i = 0; i < 3; i++)
		{
			window->draw(text[i]);
		}
		window->display();
	}
}
void menu::createText()
{
	std::string tekst[] = { "SNAKE","PLAY","EXIT" };
	for (size_t i = 0; i < 3; i++)
	{
		text[i].setFont(font);		
		text[i].setString(tekst[i]);
		if(i==0)
		{
			text[i].setCharacterSize(120);
			text[i].setPosition(sf::Vector2f(GameInfo::length / 2 - (text[i].getGlobalBounds().width / 2), GameInfo::height / 4 - text[i].getGlobalBounds().height / 2));
		}
			
		else
		{
			text[i].setCharacterSize(80);
			text[i].setPosition(sf::Vector2f(GameInfo::length / 4 + (text[0].getGlobalBounds().width / 4), GameInfo::height / 4 + text[0].getGlobalBounds().height*i));
		}
			
	}
}
void menu::updateMenu()
{
	sf::Vector2f mouse(sf::Mouse::getPosition(*window));
	for (size_t i = 1; i < 3; i++)
	{
		if (text[i].getGlobalBounds().contains(mouse))
		{
			text[i].setColor(sf::Color::Cyan);
		}else text[i].setColor(sf::Color::White);

	}
}

menu::~menu()
{
}
