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

	if (!m_splashTexture.loadFromFile("ASSETS/IMAGES?wallpaper.jpg"))
	{
		std::cout << "error with Splash File";
	}
	m_splashTexture.setRepeated(true);
	m_splashSprite.setTexture(m_splashTexture);
	m_splashSprite.setTextureRect(sf::IntRect(0, 0 static_cast<int>(Game::screenWidth), static_cast<int>(Game::screenHeight)));
	m_splashSprite.setPosition(0, 0);
	m_message.setFont(m_font);
	m_message.setString("Press the space bar to continue");
	m_message.setCharacterSize(20); 
	m_message.setStyle(sf::Text::Bold);
	m_message.setColor(sf::Color::White);

	sf::FloatRect textSize = m_message.getGlobalBounds();
	float xposition = Game::screenWidth / 2 - textSize.width / 2;
	m_message.setPosition(xposition, Game::screenHeight * 0.75f);
	m_proceedKeyPressed = false;
}

void SplashScreen::render(sf::RenderWindow& window)
{
	window.draw(m_message);
	window.draw(m_splashSprite);
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
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		m_proceedKeyPressed = true;
	}
	if (m_proceedKeyPressed)
	{
		Game::currentState = GameState::MainMenu;
	}
	m_proceedKeyPressed = false;
}
