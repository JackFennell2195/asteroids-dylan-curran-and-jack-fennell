#include <iostream>
#include "Credits.h"
#include "Game.h"

Credits::Credits()
{
}

Credits::~Credits()
{
}

void Credits::initialise(sf::Font &font)
{
	
	c_font = font;

	c_message1.setFont(c_font);
	c_message1.setString("Programmers");
	c_message1.setColor(sf::Color::White);
	c_message1.setCharacterSize(70);

	sf::FloatRect textSize = c_message1.getGlobalBounds();
	float xPos = Game::screenWidth / 2 - textSize.width / 2;
	c_message1.setPosition(xPos, 150.0f);
	
	c_message2.setFont(c_font);
	c_message2.setString("Dylan Curran and Jack Fennell");
	c_message2.setColor(sf::Color::White);
	c_message2.setCharacterSize(70);

	sf::FloatRect textSize1 = c_message2.getGlobalBounds();
	float xPos1 = Game::screenWidth / 2 - textSize1.width / 2;
	c_message2.setPosition(xPos1, 300.0f);
	
	
	c_time = sf::seconds(0);
}

void Credits::render(sf::RenderWindow & window)
{
	if (c_time.asSeconds() < 3.0)
	{
		window.draw(c_message1);
		window.draw(c_message2);
	}

}

void Credits::update(sf::Time time)
{
	c_time += time;
	
}
