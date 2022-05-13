#include "Obstacles.h"

void Obstacles::GenerateObstacles(sf::RenderWindow& window, Snake& snake)
{
	sf::RectangleShape obstacle;
	obstacle.setFillColor(sf::Color::Black);
	obstacle.setOutlineColor(sf::Color::White);
	obstacle.setOutlineThickness(5);

	sf::Vector2f obstacleSize;
	obstacleSize.x = 100.0f;
	obstacleSize.y = 100.0f;
	obstacle.setSize(obstacleSize);

	sf::Vector2f position;
	do
	{
		position.x = rand() % (window.getSize().x  + 1 - 100) + 0;
		position.y = rand() % (window.getSize().y + 1 - 100) + 0;
		obstacle.setPosition(position);

	} while (obstacle.getGlobalBounds().intersects(snake.GetSnakeBody()[0].getGlobalBounds()));
		
	obstacle.setPosition(position);
	obstacles.push_back(obstacle);

	obstaclesNumber++;
}

std::vector<sf::RectangleShape> Obstacles::GetObstacles() const
{
	return obstacles;
}

Obstacles::Obstacles()
{
	obstaclesNumber = 0;
}

int Obstacles::GetObstaclesNumber() const
{
	return obstaclesNumber;
}

void Obstacles::RemoveObstacle()
{
	obstacles.pop_back();
	obstaclesNumber--;
}