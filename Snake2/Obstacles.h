#pragma once
#include <SFML/Graphics.hpp>
#include "Snake.h"

class Obstacles
{
private:
	std::vector<sf::RectangleShape> obstacles;
	int obstaclesNumber;

public:
	Obstacles();
	void GenerateObstacles(sf::RenderWindow& window, Snake& snake);
	void RemoveObstacle();
	int GetObstaclesNumber() const;
	std::vector<sf::RectangleShape> GetObstacles() const;
};

