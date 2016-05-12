#include "engine.h"

engine::engine(sf::Font font, sf::RenderWindow &window, GameState &gameState)
{
	this->font = font;
	this->window = &window;
	this->gameState = &gameState;
	text.setFont(this->font);
}

void engine::displayGame()
{
	sf::Clock appleClock;
	sf::Clock moveClock;
	int fps = 0;
	map.addMap();
	while (gameState->State == GameState::PLAY)
	{
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				gameState->State = GameState::EXIT;
			}
			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape)
			{
				gameState->State = GameState::MENU;
			}
			if (event.type == sf::Event::KeyPressed&&event.key.code == sf::Keyboard::P)
			{
				Snake.addSnakePart();
			}
		}
		if (!pause)
		{
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Left)
				{
					Snake.changeDirection(1);
				}
				if (event.key.code == sf::Keyboard::Right)
				{
					Snake.changeDirection(2);
				}
				if (event.key.code == sf::Keyboard::Down)
				{
					Snake.changeDirection(4);
				}
				if (event.key.code == sf::Keyboard::Up)
				{
					Snake.changeDirection(3);
				}
			}
			collisionWithApple();
			collisionWithSnake();
			collisionWithWall();
			if (appleClock.getElapsedTime() > sf::seconds(GameInfo::appleDelay) || Apple.mapAppleArray.empty()||containFlag)
			{
				Apple.addApple(randomizer(GameInfo::length), randomizer(GameInfo::height));
				WallContainApple();
				appleClock.restart();
				containFlag = false;
			}
			if (moveClock.getElapsedTime() > sf::milliseconds(GameInfo::snakeSpeed * 100 - Snake.points / 10))
			{
				Snake.moveSnake();
				moveClock.restart();
			}
			isOutOfScreen();
			window->clear();
			window->draw(map);
			window->draw(Apple);
			window->draw(Snake);
			drawPoints();
			window->display();
			
		}
		else
		{
			gameOver();
		}
	}
}
void engine::isOutOfScreen()
{
	if (Snake.snakePartArray[0].rect.getPosition().x < 0)
	{
		Snake.snakePartArray[0].rect.setPosition(sf::Vector2f(GameInfo::length - GameInfo::SizeOnePart, Snake.snakePartArray[0].rect.getPosition().y));
	}
	if (Snake.snakePartArray[0].rect.getPosition().x >= GameInfo::length)
	{
		Snake.snakePartArray[0].rect.setPosition(sf::Vector2f(0, Snake.snakePartArray[0].rect.getPosition().y));
	}
	if (Snake.snakePartArray[0].rect.getPosition().y < 0)
	{
		Snake.snakePartArray[0].rect.setPosition(sf::Vector2f(Snake.snakePartArray[0].rect.getPosition().x, GameInfo::height - GameInfo::SizeOnePart));
	}
	if (Snake.snakePartArray[0].rect.getPosition().y >= GameInfo::height)
	{
		Snake.snakePartArray[0].rect.setPosition(sf::Vector2f(Snake.snakePartArray[0].rect.getPosition().x, 0));
	}
}
void engine::collisionWithApple()
{
	counter = 0;
	for (Apple.appleIterator = Apple.mapAppleArray.begin(); Apple.appleIterator != Apple.mapAppleArray.end(); Apple.appleIterator++)
	{
		if (Snake.snakePartArray[0].rect.getGlobalBounds().intersects(Apple.mapAppleArray[counter].rect.getGlobalBounds()))
		{
			Apple.mapAppleArray.erase(Apple.appleIterator);
			Snake.points += GameInfo::pointsAdd;
			Snake.addSnakePart();
			break;
		}
		counter++;
	}
}
void engine::collisionWithSnake()
{
	for (size_t i = 1; i < Snake.snakeSize; i++)
	{
		if (Snake.snakePartArray[0].rect.getGlobalBounds().intersects(Snake.snakePartArray[i].rect.getGlobalBounds()))
		{
			pause = true;
		}
	}
}
void engine::drawPoints()
{
	text.setStyle(sf::Text::Underlined);
	text.setCharacterSize(24);
	text.setPosition(sf::Vector2f(0, 0));
	text.setString("points: ");
	window->draw(text);
	text.setPosition(sf::Vector2f(text.getPosition().x + text.getGlobalBounds().width, text.getPosition().y));
	text.setString(std::to_string(Snake.points));
	window->draw(text);
}
int engine::randomizer(int position)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(0, position/10);
	return dist(gen)*10;
}
void engine::gameOver()
{
	window->clear();
	text.setStyle(sf::Text::Bold);
	text.setCharacterSize(60);
	text.setString("GAME OVER!@");
	text.setPosition(sf::Vector2f(GameInfo::length / 2 - (text.getGlobalBounds().width / 2), GameInfo::height / 4 - text.getGlobalBounds().height / 2));
	window->draw(text);
	text.setPosition(sf::Vector2f(text.getPosition().x + (text.getGlobalBounds().width / 2), text.getPosition().y + text.getGlobalBounds().height * 2));
	text.setCharacterSize(30);
	text.setString(std::to_string(Snake.points));
	window->draw(text);
	window->display();
}
void engine::collisionWithWall()
{
	for (size_t i = 0; i < map.mapWallArray.size(); i++)
	{
		if (map.mapWallArray[i].rect.getGlobalBounds().intersects(Snake.snakePartArray[0].rect.getGlobalBounds()))
			pause = true;
	}
}
void engine::WallContainApple()
{
	for (size_t i = 0; i < map.mapWallArray.size(); i++)
	{
		if (map.mapWallArray[i].rect.getGlobalBounds().intersects((Apple.mapAppleArray[Apple.mapAppleArray.size() - 1].rect.getGlobalBounds())))
		{
			Apple.mapAppleArray.pop_back();
			containFlag = true;
		}
	}
}
engine::~engine()
{
}
