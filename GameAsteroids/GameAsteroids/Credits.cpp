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
	//message1
	c_message1.setFont(c_font);
	c_message1.setString("Programmers");
	c_message1.setColor(sf::Color::White);
	c_message1.setCharacterSize(70);

	sf::FloatRect textSize = c_message1.getGlobalBounds();
	float xPos = Game::screenWidth / 2 - textSize.width / 2;
	c_message1.setPosition(xPos, 150.0f);
	
	//message2
	c_message2.setFont(c_font);
	c_message2.setString("Dylan Curran and Jack Fennell");
	c_message2.setColor(sf::Color::White);
	c_message2.setCharacterSize(70);

	sf::FloatRect textSize1 = c_message2.getGlobalBounds();
	float xPos1 = Game::screenWidth / 2 - textSize1.width / 2;
	c_message2.setPosition(xPos1, 300.0f);
	
	//message3
	c_message3.setFont(c_font);
	c_message3.setString("Developers");
	c_message3.setColor(sf::Color::White);
	c_message3.setCharacterSize(70);

	sf::FloatRect textSize2 = c_message3.getGlobalBounds();
	float xPos2 = Game::screenWidth / 2 - textSize2.width / 2;
	c_message2.setPosition(xPos2, 150.0f);

	//message4
	c_message4.setFont(c_font);
	c_message4.setString("Producers");
	c_message4.setColor(sf::Color::White);
	c_message4.setCharacterSize(70);

	sf::FloatRect textSize3 = c_message4.getGlobalBounds();
	float xPos3 = Game::screenWidth / 2 - textSize3.width / 2;
	c_message2.setPosition(xPos3, 150.0f);

	//message5
	c_message5.setFont(c_font);
	c_message5.setString("Designers");
	c_message5.setColor(sf::Color::White);
	c_message5.setCharacterSize(70);

	sf::FloatRect textSize4 = c_message5.getGlobalBounds();
	float xPos4 = Game::screenWidth / 2 - textSize4.width / 2;
	c_message5.setPosition(xPos4, 150.0f);
	
	
	c_time = sf::seconds(0);
}

void Credits::render(sf::RenderWindow & window)
{
	if (c_time.asSeconds() < 3.0)
	{
		window.draw(c_message1);
		window.draw(c_message2);
	}
	else if (c_time.asSeconds() > 3.1 && c_time.asSeconds() < 6.0)
	{
		window.draw(c_message3);
		window.draw(c_message2);
	}
	else if (c_time.asSeconds() > 6.1 && c_time.asSeconds() < 9.0)
	{
		window.draw(c_message4);
		window.draw(c_message2);
	}
	else if (c_time.asSeconds() > 9.1 && c_time.asSeconds() < 12.0)
	{
		window.draw(c_message5);
		window.draw(c_message2);
	}


}

void Credits::update(sf::Time time)
{
	c_time += time;
	
}
