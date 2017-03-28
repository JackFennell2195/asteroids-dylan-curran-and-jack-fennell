#ifndef GAMEPLAY
#define GAMEPLAY
#include <iostream>
#include <SFML\Graphics.hpp>

class Gameplay
{
public:
	Gameplay();
	~Gameplay();
	void initialise();
	void render(sf::RenderWindow&);
	void takeInput(sf::Event);
	void update(sf::Time);



};	
#endif // end Gameplay
