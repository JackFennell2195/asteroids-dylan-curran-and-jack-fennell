#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include <SFML\Graphics.hpp>

/// <summary>
/// @author jack fennell and dylan curran
/// date 26/02
/// Splash Screen for Asteroids
/// </summary>

class SplashScreen
{
public:
	SplashScreen();
	~SplashScreen();

	void initialise(sf::Font&);
	void render(sf::RenderWindow&);
	void processInput(sf::Event);
	void update(sf::Time);

protected:
	
	sf::Texture m_splashTexture;
	sf::Sprite m_splashSprite;
	sf::Font m_font;
	sf::Text m_message;
	bool m_proceedKeyPressed;
};


#endif // !SPLASHSCREEN_H