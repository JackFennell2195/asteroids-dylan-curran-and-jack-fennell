#include "HelpMenu.h"
#include "Game.h"
#include <iostream>
/// <summary>
///  Project authors: Dylan Curran and Jack Fennell
/// Project Asteroids in a group: help menu
/// Date 27/2/2017
/// </summary>

HelpMenu::HelpMenu()
{
}

HelpMenu::~HelpMenu()
{
}

void HelpMenu::initialise(sf::Font &font)
{
	h_font = font;

	h_message.setFont(h_font);
	h_message.setString("Use the up arrow key to move and the left or right button to rotate, use the spacebar to shoot");
	h_message.setCharacterSize(21);
	h_message.setColor(sf::Color::Green);

	sf::FloatRect textSize = h_message.getGlobalBounds();
	float xPos = Game::screenWidth / 2 - textSize.width / 2;
	h_message.setPosition(xPos, 100.0f);
	h_exit = false;
}

void HelpMenu::render(sf::RenderWindow &window)
{
}

void HelpMenu::takeInput(sf::Event event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::Escape)
		{
			h_exit = true;
		}
	}
}

void HelpMenu::update(sf::Time time)
{
	if (h_exit)
	{
		Game::currentState = GameState::MainMenu;
	}
}
