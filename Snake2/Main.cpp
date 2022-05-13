#include<iostream>
#include <SFML/Graphics.hpp>
#include "Snake.h"
#include "Game.h"

using namespace std;

int main()
{
	int window_x = 1200;
	int window_y = 900;

	sf::RenderWindow window(sf::VideoMode(window_x, window_y), "Snake", sf::Style::Close);
	Game game;

	while(1)
	{
		game.Open(window);	
	}

	return 0;
}