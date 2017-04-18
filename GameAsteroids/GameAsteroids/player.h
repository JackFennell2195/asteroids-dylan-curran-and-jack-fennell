#ifndef PLAYER
#define PLAYER
#include <iostream>
#include <SFML\Graphics.hpp>
class Player
{
	const int MAX_SPEED = 100;
	sf::CircleShape body;
	
	
	int lives = 0;
	double playerSpeed = 0.001;
	double playerAcceleration = 0;
	double playerX = 300;
	double playerY = 300;
	int fuel = 0;
	int shields = 0;
	double rotator = 0.05;
	double currentAngle = 0;
	double accelerate = 0;
	sf::Sprite p_sprite;
	sf::Texture p_texture;

public:
	void setPosition();
	void initialise();
	void render(sf::RenderWindow &window);
	void rotate();
	double acceleration();
	void shoots();
	void collision();
	void move();
};

#endif //PLAYER
