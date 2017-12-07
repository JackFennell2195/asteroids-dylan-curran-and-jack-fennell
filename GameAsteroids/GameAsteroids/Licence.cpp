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
	l_message.setString("Created");
	l_message.setCharacterSize(130);
	l_message.setFillColor(sf::Color::Red);

	sf::FloatRect textSize = l_message.getGlobalBounds();
	float xPos = Game::screenWidth / 2 - textSize.width / 2;
	l_message.setPosition(xPos, 150.0f);

	l_message1.setFont(l_font);
	l_message1.setString("By");
	l_message1.setCharacterSize(130);
	l_message1.setFillColor(sf::Color::Red);

	sf::FloatRect textSize1 = l_message1.getGlobalBounds();
	float xPos1 = Game::screenWidth / 2 - textSize1.width / 2;
	l_message1.setPosition(xPos1, 260.0f);

	l_message2.setFont(l_font);
	l_message2.setString("DJ Studios");
	l_message2.setCharacterSize(130);
	l_message2.setFillColor(sf::Color::Red);

	sf::FloatRect textSize2 = l_message2.getGlobalBounds();
	float xPos2 = Game::screenWidth / 2 - textSize2.width / 2;
	l_message2.setPosition(xPos2, 370.0f);

	l_time = sf::seconds(0);
}

void Licence::render(sf::RenderWindow &window)
{
	window.draw(l_message);
	window.draw(l_message1);
	window.draw(l_message2);
}

void Licence::update(sf::Time time)
{
	l_time += time;
	if (l_time.asSeconds() < 2.2)
	{
		Game::currentState = GameState::Licence;
	}
	else
	{
		Game::currentState = GameState::Splash;
	}
}

