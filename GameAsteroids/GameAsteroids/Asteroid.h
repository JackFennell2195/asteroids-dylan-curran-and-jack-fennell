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
	double asteroidAcceleration;
	double asteroid_X;
	double asteroid_Y;
	sf::Sprite asteroid_sprite;
	sf::Texture asteroid_texture;

public:
	Asteroid();
	void initialise();
	void render(sf::RenderWindow &window);
	void rotate();
	void collision();
	void move();
	void acceleration();
};
#endif //ASTEROID

