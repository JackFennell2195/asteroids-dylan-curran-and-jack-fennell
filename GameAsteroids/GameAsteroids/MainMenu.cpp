#include <iostream>
#include "MainMenu.h"
#include "Game.h"

MainMenu::MainMenu()
{
}

MainMenu::~MainMenu()
{
}

void MainMenu::initialise(sf::Font& font)
{
	m_font = font;
	if (!m_backgroundTexture.loadFromFile("ASSETS/IMAGES/menu.png"))
	{
		std::cout << "error with button file";
	}
	m_backgroundSprite.setTexture(m_backgroundTexture);
	m_backgroundSprite.setPosition(0, 25);
	sf::Vector2u textureSize = m_backgroundTexture.getSize();

	m_topOffset = 50;
	m_verticalSpacing = 128;
	m_buttonWidth = 200;
	m_leftOffset = (Game::screenWidth - m_buttonWidth) / 2;
	m_buttonHeight = 50;
	int textDropOffset = 10;
	sf::String m_menuTexts[] = { "Play Game", "Help", "Shop", "Credits", "Quit" };


	if (!m_buttonTexture.loadFromFile("ASSETS/IMAGES/button.png"))
	{
		std::cout << "error with button file";
	}
	for (int i = 0; i < m_optionCount; i++)
	{
		m_buttonSprites[i].setTexture(m_buttonTexture);
		m_buttonSprites[i].setPosition(m_leftOffset, m_verticalSpacing*i + m_topOffset);
		sf::Vector2u textureSize = m_buttonTexture.getSize();
		m_buttonSprites[i].setScale(m_buttonWidth / textureSize.x, m_buttonHeight / textureSize.y);

		m_buttonTexts[i].setFont(m_font);
		m_buttonTexts[i].setString(m_menuTexts[i]);
		m_buttonTexts[i].setColor(sf::Color::White);
		m_buttonTexts[i].setCharacterSize(26);
		sf::FloatRect textSize = m_buttonTexts[i].getGlobalBounds();
		float textOffset = (m_buttonWidth - textSize.width) / 2;
		m_buttonTexts[i].setPosition(m_leftOffset + textOffset, m_verticalSpacing*i + m_topOffset + textDropOffset);

	}
}

void MainMenu::render(sf::RenderWindow& window)
{
	window.draw(m_backgroundSprite);

	for (int i = 0; i < m_optionCount; i++)
	{
		window.draw(m_buttonSprites[i]);
		window.draw(m_buttonTexts[i]);
	}
}

void MainMenu::update(sf::Time time, sf::Window & window)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		sf::Vector2i mouseLocation;
		mouseLocation = sf::Mouse::getPosition(window);
		if (mouseLocation.x > m_leftOffset && mouseLocation.x < m_leftOffset + m_buttonWidth)
		{
			if (mouseLocation.y > m_topOffset && mouseLocation.y < m_topOffset + m_buttonHeight)
			{
				Game::currentState = GameState::Game;
			}
			if (mouseLocation.y > m_topOffset + m_verticalSpacing && mouseLocation.y < m_topOffset + m_verticalSpacing + m_buttonHeight)
			{
				Game::currentState = GameState::Help;
			}
			/*if (mouseLocation.y > m_topOffset + m_verticalSpacing * 2 && mouseLocatin.y < m_topOffset + m_verticalSpacing * 2 + m_buttonHeight)
			{
			Game::currentState = GameState::Shop;
			}
			*/
			if (mouseLocation.y > m_topOffset + m_verticalSpacing * 3 && mouseLocation.y < m_topOffset + m_verticalSpacing * 3 + m_buttonHeight)
			{
				Game::currentState = GameState::Credits;
			}
			if (mouseLocation.y > m_topOffset + m_verticalSpacing * 4 && mouseLocation.y < m_topOffset + m_verticalSpacing * 4 + m_buttonHeight)
			{
				window.close();
			}
		}
	}
}
