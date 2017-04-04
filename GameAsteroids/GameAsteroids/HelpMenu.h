#ifndef HELPMENU
#define HELPMENU
/// <summary>
///  Project authors: Dylan Curran and Jack Fennell
/// Project Asteroids in a group: help menu
/// Date 27/2/2017
/// </summary>
#include <iostream>
#include <SFML\Graphics.hpp>
class HelpMenu
{


public:
	HelpMenu();		// default constructor
	~HelpMenu();	// destructor
	void initialise(sf::Font&);
	void render(sf::RenderWindow&);
	void processInput(sf::Event);
	void update(sf::Time);

protected:
	sf::Font h_font;
	sf::Text h_message;
	bool h_exit;
};	
#endif // end helpMenu