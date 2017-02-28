#include "Gameplay.h"

Gameplay::Gameplay()
{
}

Gameplay::~Gameplay()
{
}

void Gameplay::initialise()
{
}

void Gameplay::render(sf::RenderWindow &)
{
}

void Gameplay::takeInput(sf::Event event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::Up)
		{
			std::cout << "You just pressed the up button" << std::endl;
		}
	}
}

void Gameplay::update(sf::Time)
{
}
