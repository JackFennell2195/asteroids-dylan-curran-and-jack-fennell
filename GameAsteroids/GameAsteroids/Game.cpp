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

	/*m_licenceScreen.initialise(m_arialFont);*/
	m_splashScreen.initialise(m_arialFont);

	m_mainMenu.initialise(m_arialFont);
	/*m_mainGame.initialise();*/
	//m_helpMenu.initialise(m_arialFont);

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
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / 60.f);
	while (m_Window.isOpen())
	{
		processEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			
			processEvents();
			update(timePerFrame);
#ifdef TEST_FPS

			secondTime += timePerFrame;
			updateFrameCount++;
			if (secondTime.asSeconds() > 1)
			{
				char bufferDps[256];
				char bufferUps[256];
				sprintf_s(bufferUps, "%d UPS", updateFrameCount - 1);
				updateFps.setString(bufferUps);
				sprintf_s(bufferDps, "%d DPS", updateFrameCount - 1);
				updateFps.setString(bufferDps);
				updateFrameCount = 0;
				drawFrameCount = 0;
				secondTime = sf::Time::Zero;

			}
#endif // TEST_FPS
		}
		render();
#ifdef TEST_FPS
		drawFrameCount++;
#endif //TEST_FPS
	}
}

void Game::processEvents()
{
	sf::Event event;
	while (m_Window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_Window.close();
		}
		switch (currentState)
		{
		case GameState::Licence:
			break;
		case GameState::Splash:
			m_splashScreen.processInput(event);
			break;
		case GameState::MainMenu:
			break;
		/*case GameState::Help:
			m_helpMenu.processInput(event);
			break;*/
		/*case GameState::Game:
			m_mainGame.processInput(event);
			break;*/
		default:
			break;
		}
	}
}

void Game::update(sf::Time time)
{
	switch (currentState)
	{
	/*case GameState::Licence:
		m_licenceScreen.update(time);
		break;*/
	case GameState::Splash:
		m_splashScreen.update(time);
		break;
	case GameState::MainMenu:
		m_mainMenu.update(time, m_Window);
		break;
	/*case GameState::Help:
		m_helpMenu.update(time);
		break;*/
	//case GameState::Game:
	//	m_mainGame.update(time);
	//	break;
	default:
		break;
	}
}

void Game::render()
{
	m_Window.clear();
	switch (currentState)
	{
	/*case GameState::Licence:
		m_licenceScreen.render(m_Window);
		break;*/
	case GameState::Splash:
		m_splashScreen.render(m_Window);
		break;
	case GameState::MainMenu:
		m_mainMenu.render(m_Window);
		break;
	/*case GameState::Help:
		m_helpMenu.render(m_Window);
		break;*/
	/*case GameState::Game:
		m_mainGame.render(m_Window);
		break;*/
	default:
		break;

		}
#ifdef TEST_FPS
	
	m_Window.draw(updateFps);
	m_Window.draw(drawFps);
#endif // TEST_FPS
	m_Window.display();
}



