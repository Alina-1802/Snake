#include "Points.h"
#include <time.h> 
#include <iostream>

Points::Points()
{
	pointSize.x = 10.0f;
	pointSize.y = 10.0f;

	point.setSize(pointSize);
	point.setFillColor(sf::Color::Green);

	obstaclePoint.setSize(pointSize);
	obstaclePoint.setFillColor(sf::Color::Yellow);

	bonusPoint.setSize(pointSize);
	bonusPoint.setFillColor(sf::Color::Blue);

	minusPoint.setSize(pointSize);
	minusPoint.setFillColor(sf::Color::Red);

	sf::Vector2f pointPosition;
	pointPosition.x = 500.0f;
	pointPosition.y = 500.0f;

	point.setPosition(pointPosition);

	isObstaclePointGenerated = false;
	isBonusPointGenerated = false;
	isMinusPointGenerated = false;

	score = 0;
}

void Points::SetPointCoordinates(sf::RenderWindow& window, Obstacles& obstacle, Snake& snake, sf::RectangleShape& point)
{
	sf::Vector2f pointPosition;

	int i = 0;

	do
	{
		pointPosition.x = 60 + (rand() % (window.getSize().x - 60 - 60 + 1));
		pointPosition.y = 60 + (rand() % (window.getSize().y - 60 - 60 + 1));
		point.setPosition(pointPosition);

		int i = 0;
		bool intersects;
		bool tooClose = false;

		do
		{
			
			if ((point.getPosition().x > obstacle.GetObstacles()[i].getPosition().x - 55.0f - pointSize.x) 
				&& (point.getPosition().x < obstacle.GetObstacles()[i].getPosition().x + 55.0f + obstacle.GetObstacles()[0].getSize().x) 
				&& (point.getPosition().y > obstacle.GetObstacles()[i].getPosition().y - 55.0f - pointSize.y) 
				&& (point.getPosition().y < obstacle.GetObstacles()[i].getPosition().y + +55.0f + obstacle.GetObstacles()[0].getSize().y))
			{
				tooClose = true;
			}
			if (&point == &obstaclePoint || &point == &bonusPoint || &point == &minusPoint)
			{
				intersects = point.getGlobalBounds().intersects(obstacle.GetObstacles()[i].getGlobalBounds())
						  || point.getGlobalBounds().intersects(snake.GetSnakeBody()[0].getGlobalBounds())
						  || point.getGlobalBounds().intersects(this->point.getGlobalBounds());
			}
			else if (&point == &(this->point))
			{
				intersects = point.getGlobalBounds().intersects(obstacle.GetObstacles()[i].getGlobalBounds())
					|| point.getGlobalBounds().intersects(snake.GetSnakeBody()[0].getGlobalBounds());
			}
			else
				intersects = point.getGlobalBounds().intersects(obstacle.GetObstacles()[i].getGlobalBounds())
				|| point.getGlobalBounds().intersects(snake.GetSnakeBody()[0].getGlobalBounds());



			if (intersects || tooClose)
			{
				break;
			}
			
			i++;

		} while (i < obstacle.GetObstaclesNumber());

		if (!intersects && !tooClose)
			break;

	} while (1);

	point.setPosition(pointPosition);
}

void Points::SetPointState(sf::RectangleShape snake_head, sf::RenderWindow& window, Snake& snake, Obstacles& obstacle)
{
	int random_number = rand() % 100;

	if (point.getGlobalBounds().intersects(snake.snakeBody[0].getGlobalBounds()))
	{
		score++;
		snake.GenerateExtraRectangle();
		snake.snakeLength++;

		if(snake.GetSnakeLength() % 2 == 0)
		{
			obstacle.GenerateObstacles(window, snake);
		}

		SetPointCoordinates(window, obstacle, snake, point);

		if (snake.GetSnakeLength() % 4 == 0)
		{
			SetPointCoordinates(window, obstacle, snake, obstaclePoint);
			isObstaclePointGenerated = true;
		}
		else if (random_number % 4 == 0 && snake.GetSnakeLength() % 2 == 0) //&& snake.GetSnakeLength() > 6)
		{
			SetPointCoordinates(window, obstacle, snake, bonusPoint);
			isBonusPointGenerated = true;
		}
		if (random_number % 3 == 0 && snake.GetSnakeLength() % 2 == 0)// && snake.GetSnakeLength() > 6)
		{
			SetPointCoordinates(window, obstacle, snake, minusPoint);
			isMinusPointGenerated = true;
		}

	}

	if (obstaclePoint.getGlobalBounds().intersects(snake.snakeBody[0].getGlobalBounds()))
	{
		obstacle.RemoveObstacle();
		obstaclePoint.setPosition(-1.0f, -1.0f);
		isObstaclePointGenerated = false;
	}

	if (bonusPoint.getGlobalBounds().intersects(snake.snakeBody[0].getGlobalBounds()))
	{
		snake.snakeLength += 3;
		score += 3;
		for(int i = 0; i < 3; i++)
			snake.GenerateExtraRectangle();
		bonusPoint.setPosition(-1.0f, -1.0f);
		isBonusPointGenerated = false;
	}

	if (minusPoint.getGlobalBounds().intersects(snake.snakeBody[0].getGlobalBounds()))
	{
		snake.snakeLength -= 3;
		score -= 3;
		for (int i = 0; i < 3; i++)
			snake.snakeBody.pop_back();
		minusPoint.setPosition(-1.0f, -1.0f);
		isMinusPointGenerated = false;
	}
}

int Points::GetScore() const
{
	return score;
}

sf::Vector2f Points::GetPointPosition() const
{
	return point.getPosition();
}

bool Points::GetIsObstaclePointGenerated() const
{
	return isObstaclePointGenerated;
}

bool Points::GetIsBonusPointGenerated() const
{
	return isBonusPointGenerated;
}

bool Points::GetIsMinusPointGenerated() const
{
	return isMinusPointGenerated;
}

sf::RectangleShape Points::GetPoint() const
{
	return point;
}

sf::RectangleShape Points::GetObstaclePoint() const
{
	return obstaclePoint;
}

sf::RectangleShape Points::GetBonusPoint() const
{
	return bonusPoint;
}

sf::RectangleShape Points::GetMinusPoint() const
{
	return minusPoint;
}

