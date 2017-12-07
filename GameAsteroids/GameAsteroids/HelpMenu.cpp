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
	h_message.setString("Help Menu");
	h_message.setCharacterSize(50);
	h_message.setFillColor(sf::Color::Yellow);

	sf::FloatRect textSize = h_message.getGlobalBounds();
	float xPos = Game::screenWidth / 2 - textSize.width / 2;
	h_message.setPosition(xPos, 20.0f);

	h_message3.setFont(h_font);
	h_message3.setString("Use the up arrow key to move");
	h_message3.setCharacterSize(30);
	h_message3.setFillColor(sf::Color::Yellow);

	sf::FloatRect textSize3 = h_message3.getGlobalBounds();
	float xPos3 = Game::screenWidth / 2 - textSize3.width / 2;
	h_message3.setPosition(xPos3, 80.0f);

	h_message1.setFont(h_font);
	h_message1.setString("Left or right button to rotate");
	h_message1.setCharacterSize(30);
	h_message1.setFillColor(sf::Color::Yellow);

	sf::FloatRect textSize1 = h_message1.getGlobalBounds();
	float xPos1 = Game::screenWidth / 2 - textSize1.width / 2;
	h_message1.setPosition(xPos1, 140.0f);

	h_message2.setFont(h_font);
	h_message2.setString("use the spacebar to shoot");
	h_message2.setCharacterSize(30);
	h_message2.setFillColor(sf::Color::Yellow);

	sf::FloatRect textSize2 = h_message2.getGlobalBounds();
	float xPos2 = Game::screenWidth / 2 - textSize2.width / 2;
	h_message2.setPosition(xPos2, 200.0f);

	h_message4.setFont(h_font);
	h_message4.setString("Destroy asteroids and pirate ships to earn materials");
	h_message4.setCharacterSize(30);
	h_message4.setFillColor(sf::Color::Yellow);

	sf::FloatRect textSize4 = h_message4.getGlobalBounds();
	float xPos4 = Game::screenWidth / 2 - textSize4.width / 2;
	h_message4.setPosition(xPos4, 260.0f);

	h_message5.setFont(h_font);
	h_message5.setString("Use materials to upgrade your ship in the shop");
	h_message5.setCharacterSize(30);
	h_message5.setFillColor(sf::Color::Yellow);

	sf::FloatRect textSize5 = h_message5.getGlobalBounds();
	float xPos5 = Game::screenWidth / 2 - textSize5.width / 2;
	h_message5.setPosition(xPos5, 320.0f);

	h_exit = false;
}

void HelpMenu::render(sf::RenderWindow &window)
{
	window.draw(h_message);
	window.draw(h_message1);
	window.draw(h_message2);
	window.draw(h_message3);
	window.draw(h_message4);
	window.draw(h_message5);
}

void HelpMenu::processInput(sf::Event event)
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
	h_exit = false;
}
