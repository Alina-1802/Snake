#pragma once
#include <SFML/Graphics.hpp>
#include "Snake.h"
#include "Obstacles.h"

class Points
{
	friend class Game;

private:
	sf::RectangleShape point;
	sf::RectangleShape bonusPoint;
	sf::RectangleShape obstaclePoint;
	sf::RectangleShape minusPoint;
	sf::Vector2f pointSize;
	int score;
	bool isObstaclePointGenerated;
	bool isBonusPointGenerated;
	bool isMinusPointGenerated;
public:
	Points();
	sf::RectangleShape GetPoint() const;
	sf::RectangleShape GetObstaclePoint() const;
	sf::RectangleShape GetBonusPoint() const;
	sf::RectangleShape GetMinusPoint() const;
	sf::Vector2f GetPointPosition() const;
	int GetScore() const;
	bool GetIsObstaclePointGenerated() const;
	bool GetIsBonusPointGenerated() const;
	bool GetIsMinusPointGenerated() const;
	void SetPointCoordinates(sf::RenderWindow& window, Obstacles& obstacle, Snake& snake, sf::RectangleShape& point);
	void SetPointState(sf::RectangleShape snake_head, sf::RenderWindow& window, Snake& snake, Obstacles& obstacle);
};

