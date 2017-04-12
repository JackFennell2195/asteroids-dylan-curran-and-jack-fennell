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
	c_topOffset = 50;
	c_verticalSpacing = 100;
	c_textWidth = 200;
	c_leftOffset = (Game::screenWidth - c_textWidth) / 2;
	c_textHeight = 50;
	int textDropOffset = 10;
	sf::String c_creditsTexts[] = { "Programmers", "Dylan Curran", "and", "Jack Fennell" };
	
	c_font = font;
	
	for (int i = 0; i < c_options; i++)
	{
		c_message[i].setFont(c_font);
		c_message[i].setString(c_creditsTexts[i]);
		c_message[i].setColor(sf::Color::White);
		c_message[i].setCharacterSize(26);
		sf::FloatRect textSize = c_message[i].getGlobalBounds();
		float textOffset = (c_textWidth - textSize.width) / 2;
		c_message[i].setPosition(c_leftOffset + textOffset, c_verticalSpacing*i + c_topOffset + textDropOffset);

	}
	
	c_time = sf::seconds(0);
}

void Credits::render(sf::RenderWindow & window)
{
	for (int i = 0; i < c_options; i++)
	{
		window.draw(c_message[i]);
	}
}

void Credits::update(sf::Time time)
{
	c_time += time;
	if (c_time.asSeconds() < 6.0)
	{
		Game::currentState = GameState::Credits;
	}
}
