#ifndef MAINMENU_H
#define MAINMENU_H

#include <SFML\Graphics.hpp>

/// <summary>
/// @author jack fennell and dylan curran
/// date 26/02
/// Main menu screen for Asteroids
/// </summary>

class MainMenu
{
public:
	MainMenu();
	~MainMenu();

	void initialise(sf::Font&);
	void render(sf::RenderWindow&);
	void update(sf::Time, sf::Window&);

protected:

	static const int m_optionCount = 5;
	sf::Texture m_buttonTexture;
	sf::Font m_font;
	sf::Text m_buttonTexts[m_optionCount];

	float m_topOffset;
	float m_leftOffset;
	float m_verticalSpacing;
	float m_buttonWidth;
	float m_buttonHeight;
};

#endif // !MAINMENU_H
