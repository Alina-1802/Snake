#pragma once
#include <SFML/Graphics.hpp>
#include "Points.h"
class Texts
{
private:
	sf::Font font;
	sf::Text textScore;
	sf::Text score;
	sf::Text gameOver;
	void SetForTextScore();
	void SetForScore(Points& point);
	void SetForGameOver(sf::RenderWindow& window);
public:
	Texts();
	void SetEverything(Points& point, sf::RenderWindow& window);
	sf::Text GetTextScore() const;
	sf::Text GetScore() const;
	sf::Text GetGameOver() const;
};

