#ifndef ASTEROID
#define ASTEROID
#include <iostream>
#include <SFML\Graphics.hpp>
class Asteroid
{
	sf::CircleShape body;
	double speed;
	int lives;
	const double MAX_SPEED = 50.0;
	double rotator;
	double acceleration;
	sf::Sprite asteroid_sprite;
	sf::Texture asteroid_texture;
	double asteroid_X;
	double asteroid_Y;

public:
	Asteroid();
	sf::CircleShape getBody();
	void initialise();
	void render(sf::RenderWindow &window);
	void rotate();
	void collision();
	void move();
	void acceleration();
};
#endif //ASTEROID

