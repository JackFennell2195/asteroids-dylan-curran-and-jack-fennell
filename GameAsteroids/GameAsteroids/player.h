#ifndef PLAYER
#define PLAYER
#include <iostream>
#include <SFML\Graphics.hpp>
class Player
{
	const int MAX_SPEED = 100;
	sf::CircleShape body;
	int lives = 0;
	double playerSpeed = 0.05;
	double playerAcceleration = 0;
	double playerX = 0;
	double playerY = 0;
	int fuel = 0;
	int shields = 0;
	double rotator = 0.00056765;
	sf::Sprite sprite;

public:
	void initialise();
	void render(sf::RenderWindow &window);
	void rotate();
	void acceleration();
	void shoots();
	void collision();
	void move();
};

#endif //PLAYER
