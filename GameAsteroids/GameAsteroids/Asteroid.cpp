#include "Asteroid.h"

Asteroid::Asteroid()
{
	lives = 3;
	rotator = 0.005;
}

sf::CircleShape Asteroid::getBody()
{
	return body;
}

void Asteroid::initialise()
{
	const int circleSize = 25;
	body.setRadius(circleSize);
	
}

void Asteroid::render(sf::RenderWindow & window)
{
	window.draw(body);
}

void Asteroid::rotate()
{
	body.setRotation(rotator);
}

void Asteroid::collision()
{
}

void Asteroid::move()
{
	acceleration();
	rotate();
}

void Asteroid::acceleration()
{
}
