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
	void processInput(sf::Event);
	void update(sf::Time);


private:
	sf::Font c_font;
	sf::Text c_message1;
	sf::Text c_message2;
	sf::Text c_message3;
	sf::Text c_message4;
	sf::Text c_message5;
	sf::Text c_message6;
	sf::Text c_message7;
	sf::Time c_time;
	bool m_proceedKeyPressed;

};
#endif// end of credits
