#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-main-d.lib")
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-main.lib")
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 
#pragma comment(lib,"opengl32.lib") 
#pragma comment(lib,"glu32.lib") 

#include <SFML/Graphics.hpp>
#include "SFML/OpenGL.hpp"
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include "Game.h"
#include "Licence.h"
#include "SplashScreen.h"

int main()
{
	Game game;
	game.run();
}

float Game::screenWidth = 600;
float Game::screenHeight = 400;
GameState Game::currentState = GameState::Licence;

Game::Game() : m_Window(sf::VideoMode(static_cast<int>(Game::screenWidth), static_cast<int>(Game::screenHeight)), "SFML Game", sf::Style::Default)
{
	loadContent();
	m_Window.setKeyRepeatEnabled(false);
}

void Game::loadContent()
{
	int m_gold;
	if (!m_arialFont.loadFromFile("ASSETS/FONTS/BebasNeue.otf"))
	{
		std::cout << "Error with font file";
	}

	m_licenceScreen.initialise(m_arialFont);
	m_splashScreen.initialise(m_arialFont);

	m_mainMenu.initialise(m_arialFont);
	m_mainGame.initialise();
	m_helpMenu.initialise(m_arialFont);

	m_gold = 0;
#ifdef STARTRICH
	m_gold = 1000;
#endif // STARTRICH

#ifdef TEST_FPS
	updateFrameCount = 0;
	drawFrameCount = 0;
	secondTime = sf::Time::Zero;
	updateFps.setFont(m_arialFont);
	updateFps.setPosition(20, 300);
	updateFps.setCharacterSize(24);
	updateFps.setColor(sf::Color::White);
	drawFps.setFont(m_arialFont);
	drawFps.setPosition(20, 350);
	drawFps.setCharacterSize(24);
	drawFps.setColor(sf::Color::White);
#endif // TEST_FPS 

}

void Game::run()
{

}

void Game::processEvents()
{
}

void Game::update(sf::Time)
{
}

void Game::render()
{
}


