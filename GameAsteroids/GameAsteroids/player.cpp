#include "player.h"

void Player::setPosition()
{
	body.setPosition(sf::Vector2f(playerX,playerY));
	p_sprite.setPosition(sf::Vector2f(playerX, playerY));
	
}

void Player::initialise()
{
	
	const int circleSize = 20;
	body.setOrigin(20,20);
	p_sprite.setOrigin(50,50);
	body.setRadius(circleSize);
	body.setRotation(rotator);
	p_sprite.setRotation(rotator);
	
	body.setFillColor(sf::Color::Red);
	if (!p_texture.loadFromFile("ASSETS/IMAGES/basicShip.png"))
	{
		std::cout << "The ship has not loaded" << std::endl;
	}
	p_sprite.setTexture(p_texture);
	p_sprite.setPosition(playerX, playerY);
	
	sf::Vector2u textureSize = p_texture.getSize();
}

void Player::render(sf::RenderWindow & window)
{
	window.draw(body);
	window.draw(p_sprite);
	
}

void Player::rotate()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		body.rotate(rotator);
		p_sprite.rotate(rotator);
		
		currentAngle += rotator;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		body.rotate(-rotator);
		p_sprite.rotate(-rotator);
		
		currentAngle -= rotator;
	}
	std::cout << currentAngle << std::endl;
}

double Player::acceleration()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		playerAcceleration += playerSpeed;
	}
	else
	{
		if (playerAcceleration >= 0.001)
		{
			playerAcceleration -= playerSpeed;
		}
	}
	
	return playerAcceleration;
}

void Player::move()
{
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		
		accelerate = acceleration();
		playerX += accelerate * cos(currentAngle);
		playerY += accelerate * sin(currentAngle);
		std::cout << currentAngle << std::endl;
		setPosition();
	}
	else
	{
		if (!accelerate <= 0)
		{
			
			accelerate = acceleration();
			playerX += accelerate * cos(currentAngle);
			playerY += accelerate * sin(currentAngle);

			setPosition();
		}
	}
	
	if (playerX >= 760)
	{
		playerX = -49;
		setPosition();
	}
	if (playerX <= -50)
	{
		playerX = 759;
		setPosition();
	}
	if (playerY <= -50)
	{
		playerY = 759;
		setPosition();
	}
	if (playerY >= 760)
	{
		playerY = -49;
		setPosition();
	}
	
}
