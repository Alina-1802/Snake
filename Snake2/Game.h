#include <SFML/Graphics.hpp>
#include <time.h>
#include <chrono>
#include <thread>
#include "Snake.h"
#include "Obstacles.h"
#include "Snake.h"
#include "Points.h"
#include "Texts.h"

class Game
{
public:
	int Open(sf::RenderWindow& window);
	void Update(sf::RenderWindow& window, Points& point, Texts& text, Snake& snake, Obstacles& obstacle) const;
	bool IsOutside(Snake& snake, sf::RenderWindow& window) const;
	bool IsCollision(Snake& snake, Obstacles& obstacle) const;

};
