#ifndef LICENCE
#define LICENCE
#include <iostream>
#include <SFML\Graphics.hpp>
/// <summary>
///  Project authors: Dylan Curran and Jack Fennell
/// Project Asteroids in a group: licence screen
/// Date 27/2/2017
/// </summary>

class Licence
{
public:
	Licence();
	~Licence();
	void initialise(sf::Font&);
	void render(sf::RenderWindow&);
	void update(sf::Time);

private:
	sf::Font l_font;
	sf::Text l_message;
	sf::Text l_message1;
	sf::Text l_message2;
	sf::Time l_time;

};
#endif// end of licence

