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
	c_message3.setPosition(xPos2, 150.0f);

	//message4
	c_message4.setFont(c_font);
	c_message4.setString("Producers");
	c_message4.setColor(sf::Color::White);
	c_message4.setCharacterSize(70);

	sf::FloatRect textSize3 = c_message4.getGlobalBounds();
	float xPos3 = Game::screenWidth / 2 - textSize3.width / 2;
	c_message4.setPosition(xPos3, 150.0f);

	//message5
	c_message5.setFont(c_font);
	c_message5.setString("Designers");
	c_message5.setColor(sf::Color::White);
	c_message5.setCharacterSize(70);

	sf::FloatRect textSize4 = c_message5.getGlobalBounds();
	float xPos4 = Game::screenWidth / 2 - textSize4.width / 2;
	c_message5.setPosition(xPos4, 150.0f);


	c_message6.setFont(c_font);
	c_message6.setString("Artists");
	c_message6.setColor(sf::Color::White);
	c_message6.setCharacterSize(70);

	sf::FloatRect textSize5 = c_message6.getGlobalBounds();
	float xPos5 = Game::screenWidth / 2 - textSize5.width / 2;
	c_message6.setPosition(xPos5, 150.0f);
	

	c_message7.setFont(c_font);
	c_message7.setString("(Press Esc to return to the Main Menu)");
	c_message7.setColor(sf::Color::White);
	c_message7.setCharacterSize(30);

	sf::FloatRect textSize6 = c_message7.getGlobalBounds();
	float xPos6 = Game::screenWidth / 2 - textSize6.width / 2;
	c_message7.setPosition(xPos6, 450.0f);

	
	c_time = sf::seconds(0);
}

void Credits::render(sf::RenderWindow & window)
{
	window.draw(c_message7);

	if (c_time.asSeconds() < 4.0)
	{
		window.draw(c_message1);
		window.draw(c_message2);
	}
	else if (c_time.asSeconds() > 4.1 && c_time.asSeconds() < 7.0)
	{
		window.draw(c_message3);
		window.draw(c_message2);
	}
	else if (c_time.asSeconds() > 7.1 && c_time.asSeconds() < 10.0)
	{
		window.draw(c_message4);
		window.draw(c_message2);
	}
	else if (c_time.asSeconds() > 10.1 && c_time.asSeconds() < 13.0)
	{
		window.draw(c_message5);
		window.draw(c_message2);
	}
	else if (c_time.asSeconds() > 13.1 && c_time.asSeconds() < 16.0)
	{
		window.draw(c_message6);
		window.draw(c_message2);
	}
	else if (c_time.asSeconds() > 16.1)
	{
		Game::currentState = GameState::MainMenu;
		c_time = sf::seconds(0);
	}

}

void Credits::processInput(sf::Event event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::Escape)
		{
			m_proceedKeyPressed = true;
		}
	}
}
void Credits::update(sf::Time time)
{
	c_time += time;

	if (m_proceedKeyPressed)
	{
		Game::currentState = GameState::MainMenu;
	}
	m_proceedKeyPressed = false;
	
}
