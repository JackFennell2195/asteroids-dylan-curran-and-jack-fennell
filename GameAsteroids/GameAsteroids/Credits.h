#ifndef CREDITS
#define CREDITS
#include <iostream>
#include <SFML\Graphics.hpp>
/// <summary>
/// Project authors: Dylan Curran and Jack Fennell
/// Project Asteroids in a group: credits screen
/// Date 28/3/2017
/// </summary>

class Credits
{
public:
	Credits();
	~Credits();
	void initialise(sf::Font&);
	void render(sf::RenderWindow&);
	void update(sf::Time);

private:
	static const int c_options = 6;
	sf::Font c_font;
	sf::Text c_message[c_options];
	sf::Time c_time;

	float c_topOffset;
	float c_leftOffset;
	float c_verticalSpacing;
	float c_textWidth;
	float c_textHeight;
};
#endif// end of credits
