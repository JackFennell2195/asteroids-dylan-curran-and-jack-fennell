#include "Licence.h"
#include "Game.h"
Licence::Licence()
{
}

Licence::~Licence()
{
}

void Licence::initialise(sf::Font &font)
{
	l_font = font;
	l_message.setFont(l_font);
	l_message.setString("Created By DJ Studios");
	l_message.setCharacterSize(80);
	l_message.setColor(sf::Color::Red);

	sf::FloatRect textSize = l_message.getGlobalBounds();
	float xPos = Game::screenWidth / 2 - textSize.width / 2;
	l_message.setPosition(xPos, 250.0f);
	l_time = sf::seconds(0);
}

void Licence::render(sf::RenderWindow &window)
{
	window.draw(l_message);
}

void Licence::update(sf::Time time)
{
	l_time += time;
	if (l_time.asSeconds() < 1.9)
	{
		Game::currentState = GameState::Licence;
	}
	else
	{
		Game::currentState = GameState::Splash;
	}
}
