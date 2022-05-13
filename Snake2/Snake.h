#pragma once
#include <SFML/Graphics.hpp>

class Snake
{
	friend class Points;

private:
	sf::Vector2f snakeSize;
	std::vector<sf::RectangleShape> snakeBody; 
	int snakeLength;
	int recentlyClicked;

public:
	Snake();
	void MoveSnake();
	void SetHeadPosition(sf::RenderWindow& window);
	void GenerateExtraRectangle();
	int GetSnakeLength() const;
	sf::Vector2f GetHeadPosition() const;
	sf::RectangleShape GetHead() const;
	sf::Vector2f GetSnakeSize() const;
	std::vector<sf::RectangleShape> GetSnakeBody() const;
};
