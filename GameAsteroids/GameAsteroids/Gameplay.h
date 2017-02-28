#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>

class Gameplay
{
	Gameplay();
	~Gameplay();
	void initialise();
	void render(sf::RenderWindow&);
	void takeInput(sf::Event);
	void update(sf::Time);



};	// end Gameplay