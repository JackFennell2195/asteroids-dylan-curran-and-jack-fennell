#include "Gameplay.h"
#include "Game.h"
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

void Gameplay::processInput(sf::Event event)
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
