#include "Texts.h"


Texts::Texts()
{
	font.loadFromFile("Resources/Fonts/text_font.ttf");
}

void Texts::SetForTextScore()
{
	textScore.setString("Score: ");
	textScore.setFont(font);
}

void Texts::SetForScore(Points& point)
{
	score.setString(std::to_string(point.GetScore()));
	score.setFont(font);
	score.setPosition(100.0f, 0.0f);
}

void Texts::SetForGameOver(sf::RenderWindow& window)
{
	gameOver.setString("Game Over");
	gameOver.setFont(font);
	gameOver.setPosition(window.getSize().x / 2.0 - 250.0, window.getSize().y / 2.0 - 100.0);
	gameOver.setCharacterSize(120);
}



sf::Text Texts::GetTextScore() const
{
	return textScore;
}

sf::Text Texts::GetScore() const
{
	return score;
}


sf::Text Texts::GetGameOver() const
{
	return gameOver;
}

void Texts::SetEverything(Points& point, sf::RenderWindow& window)
{
	SetForTextScore();
	SetForScore(point);
	SetForGameOver(window);
}