#include "Game.h"
#include <iostream>

void Game::Update(sf::RenderWindow& window, Points& point,Texts& text, Snake& snake, Obstacles& obstacle) const
{
	window.clear();
	for (int i = 0; i <= snake.GetSnakeLength(); i++)
		window.draw(snake.GetSnakeBody()[i]);

	for(int i = 0; i < obstacle.GetObstaclesNumber(); i++)
		window.draw(obstacle.GetObstacles()[i]);

	if (point.GetIsObstaclePointGenerated())
	{
		window.draw(point.GetObstaclePoint());
	}
	if (point.GetIsBonusPointGenerated())
	{
		window.draw(point.GetBonusPoint());
	}
	if (point.GetIsMinusPointGenerated())
	{
		window.draw(point.GetMinusPoint());
	}

	window.draw(text.GetTextScore());
	window.draw(text.GetScore());
	window.draw(point.GetPoint());

	if (snake.GetSnakeLength() < 0 || IsOutside(snake, window) || IsCollision(snake, obstacle))
	{
		window.draw(text.GetGameOver());
	}

	window.display();
}

bool Game::IsOutside(Snake& snake, sf::RenderWindow& window) const
{
	if (snake.GetSnakeBody()[0].getPosition().x < 0 
	 || snake.GetSnakeBody()[0].getPosition().y < 0 
	 || snake.GetSnakeBody()[0].getPosition().x > window.getSize().x - snake.GetSnakeSize().x 
	 || snake.GetSnakeBody()[0].getPosition().y > window.getSize().y - snake.GetSnakeSize().y)
	{
		return true;
	}
	else
		return false;
}

bool Game::IsCollision(Snake& snake, Obstacles& obstacle) const
{
	for (int i = 1; i < snake.GetSnakeLength(); i++)
	{
		if (snake.GetSnakeBody()[0].getPosition() == snake.GetSnakeBody()[i].getPosition())
		{
			return true;
		}
	}

	for (int i = 0; i < obstacle.GetObstaclesNumber(); i++)
	{
		if (obstacle.GetObstacles()[i].getGlobalBounds().intersects(snake.GetSnakeBody()[0].getGlobalBounds()))
		{
			return true;
		}
	}

	return false;
}

int Game::Open(sf::RenderWindow& window)
{
	srand(time(NULL));

	Snake snake;
	Points point;
	Texts text;
	Obstacles obstacle;

	snake.SetHeadPosition(window);
	obstacle.GenerateObstacles(window, snake);
	point.SetPointCoordinates(window, obstacle, snake, point.point);

	while (window.isOpen()) 
	{
		sf::Event evnt; 

		while (window.pollEvent(evnt))
		{
			switch (evnt.type)
			{
			case sf::Event::Closed:
				window.close();
			}
		}
		
		text.SetEverything(point, window);
		snake.MoveSnake();
		point.SetPointState(snake.GetHead(), window, snake, obstacle);
		Update(window, point, text, snake, obstacle);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
		{
			std::chrono::milliseconds delay(500);
			std::this_thread::sleep_for(delay);
			exit(0);
		}

		if (snake.GetSnakeLength() < 0 || IsOutside(snake, window) || IsCollision(snake, obstacle))
		{
			std::chrono::seconds delay(2);
			std::this_thread::sleep_for(delay);
			break;
		}

		std::chrono::milliseconds delay(100);
		std::this_thread::sleep_for(delay);
	}
	
}