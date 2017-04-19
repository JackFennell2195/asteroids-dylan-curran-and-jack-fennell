#include "Asteroid.h"

Asteroid::Asteroid()
{
	lives = 3;
	rotator = 0.005;
	asteroid_X = ((rand() % 250) + 1) || ((rand() % 250) + 401);
	asteroid_Y = ((rand() % 300) + 1) || ((rand() % 300) + 451);
}

void Asteroid::initialise()
{
	const int circleSize = 25;
	body.setRadius(circleSize);
	body.setFillColor(sf::Color::Green);
	body.setPosition(sf::Vector2f(asteroid_X,asteroid_Y))
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
