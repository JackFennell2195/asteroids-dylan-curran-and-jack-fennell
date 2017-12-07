#include <iostream>
#include "SplashScreen.h"
#include "Game.h"


SplashScreen::SplashScreen()
{
}

SplashScreen::~SplashScreen()
{
}

void SplashScreen::initialise(sf::Font& font)
{
	m_font = font;
	if (!m_splashTexture.loadFromFile("ASSETS/IMAGES/splash.png"))
	{
		std::cout << "error with button file";
	}
	m_splashSprite.setTexture(m_splashTexture);
	m_splashSprite.setPosition(0, 25);
	sf::Vector2u textureSize = m_splashTexture.getSize();


	m_message.setFont(m_font);
	m_message.setString("Press the space bar to continue");
	m_message.setCharacterSize(40);
	m_message.setStyle(sf::Text::Bold);
	m_message.setFillColor(sf::Color::White);

	sf::FloatRect textSize = m_message.getGlobalBounds();
	float xposition = Game::screenWidth / 2 - textSize.width / 2;
	m_message.setPosition(xposition, Game::screenHeight * 0.87f);
	m_proceedKeyPressed = false;
}

void SplashScreen::render(sf::RenderWindow& window)
{

	window.draw(m_splashSprite);
	window.draw(m_message);
}

void SplashScreen::processInput(sf::Event event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::Space)
		{
			m_proceedKeyPressed = true;
		}
	}
}

void SplashScreen::update(sf::Time time)
{
	
	if (m_proceedKeyPressed)
	{
		Game::currentState = GameState::MainMenu;
	}
	m_proceedKeyPressed = false;
}
