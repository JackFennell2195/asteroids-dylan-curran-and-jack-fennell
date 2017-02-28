#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>
/// <summary>
///  Project authors: Dylan Curran and Jack Fennell
/// Project Asteroids in a group: licence screen
/// Date 27/2/2017
/// </summary>

class Licence
{
	Licence();
	~Licence();
	void initialise(sf::Font&);
	void render(sf::RenderWindow&);
	void update(sf::Time);

protected:
	sf::Font l_font;
	sf::Text l_message;
	sf::Time l_time;

};	// end of licence