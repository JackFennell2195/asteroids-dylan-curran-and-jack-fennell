#include "player.h"

void Player::setPosition()
{
	body.setPosition(sf::Vector2f(playerX,playerY));
}

void Player::initialise()
{
	const int circleSize = 50;
	body.setRadius(circleSize);
	body.setFillColor(sf::Color::Red);
	
}

void Player::render(sf::RenderWindow & window)
{
	window.draw(body);
}

void Player::rotate()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		body.setRotation(rotator);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		body.setRotation(-rotator);
	}
}

void Player::acceleration()
{
	playerAcceleration += playerSpeed;
}

void Player::move()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		acceleration();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		rotate();
	}
}
