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
	c_message.setFont(c_font);
	c_message.setString("");
	
}

void Credits::render(sf::RenderWindow &)
{
}

void Credits::update(sf::Time)
{
}
