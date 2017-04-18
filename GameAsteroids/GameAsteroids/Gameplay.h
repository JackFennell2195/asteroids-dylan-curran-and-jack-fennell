#ifndef GAMEPLAY
#define GAMEPLAY
#include <iostream>
#include <SFML\Graphics.hpp>
#include "player.h"

class Gameplay
{
	
public:
	Gameplay();
	~Gameplay();
	void initialise();
	void render(sf::RenderWindow&);
	void processInput(sf::Event);
	void update(sf::Time);



};	
#endif // end Gameplay
