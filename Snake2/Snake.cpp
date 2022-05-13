#include "Snake.h"

Snake::Snake()
{
	sf::Vector2f headPosition;
	sf::RectangleShape headShape;
	snakeSize.x = 50.0f;
	snakeSize.y = 50.0f;

	headShape.setSize(snakeSize);
	headShape.setFillColor(sf::Color::Magenta);
	
	headPosition.x = 550.0f;
	headPosition.y = 400.0f;
	recentlyClicked = 0;

	headShape.setPosition(headPosition.x, headPosition.y);

	snakeLength = 0;
	snakeBody.push_back(headShape);

}

void Snake::MoveSnake()
{
	sf::Vector2f shift;
	shift.x = 50.0f;
	shift.y = 50.0f;

	sf::Vector2f currentHeadPosition = snakeBody[0].getPosition();
	sf::Vector2f newHeadPosition = currentHeadPosition;
	newHeadPosition.x = currentHeadPosition.x;
	newHeadPosition.y = currentHeadPosition.y;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (recentlyClicked != 3)
		{
			newHeadPosition.x += -shift.x;
			recentlyClicked = 1;
		}
		else
		{
			newHeadPosition.x += shift.x;
			recentlyClicked = 3;
		}
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
	{
		if (recentlyClicked != 4)
		{
			newHeadPosition.y += -shift.y;
			recentlyClicked = 2;
		}
		else
		{
			newHeadPosition.y += shift.y;
			recentlyClicked = 4;
		}
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	{
		if (recentlyClicked != 1)
		{
			newHeadPosition.x += shift.x;
			recentlyClicked = 3;
		}
		else
		{
			newHeadPosition.x += -shift.x;
			recentlyClicked = 1;
		}
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
	{

		if (recentlyClicked != 2)
		{
			newHeadPosition.y += shift.y;
			recentlyClicked = 4;
		}
		else
		{
			newHeadPosition.y += -shift.y;
			recentlyClicked = 2;
		}
	}

	else
	{
		switch (recentlyClicked)
		{
		case 1:
		{
			newHeadPosition.x += -shift.x;
			break;
		}

		case 2:
		{
			newHeadPosition.y += -shift.y;
			break;
		}

		case 3:
		{
			newHeadPosition.x += shift.x;
			break;
		}
		case 4:
		{
			newHeadPosition.y += shift.y;
			break;
		}
		}
	}

	for (int i = snakeLength; i >= 1; i--) 
	{
		snakeBody[i].setPosition(snakeBody[i - 1].getPosition());
	}
	snakeBody[0].setPosition(newHeadPosition);
}

void Snake::SetHeadPosition(sf::RenderWindow& window)
{
	sf::Vector2f position;
	position.x = rand() % (window.getSize().x - 100 - 100 + 1) + 100;
	position.y = rand() % (window.getSize().y - 100 - 100 + 1) + 100;

	snakeBody[0].setPosition(position);
}

void Snake::GenerateExtraRectangle()
{
	sf::Vector2f position = snakeBody.back().getPosition();

	sf::RectangleShape rectangle(sf::Vector2f(50.0f, 50.0f));
	rectangle.setFillColor(sf::Color::Cyan);
	rectangle.setOutlineColor(sf::Color::Black);
	rectangle.setPosition(position.x, position.y);

	snakeBody.push_back(rectangle);

}
 
std::vector<sf::RectangleShape> Snake::GetSnakeBody() const
{
	return snakeBody;
}


sf::RectangleShape Snake::GetHead() const
{
	return GetSnakeBody()[0];
}

sf::Vector2f Snake::GetHeadPosition() const
{
	return snakeBody[0].getPosition();
}

sf::Vector2f Snake::GetSnakeSize() const
{
	return snakeSize;
}

int Snake::GetSnakeLength() const
{
	return snakeLength;
}