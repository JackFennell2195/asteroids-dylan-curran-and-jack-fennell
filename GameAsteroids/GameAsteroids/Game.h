#ifndef GAME_H
#define GAME_H

#ifdef _DEBUG
#define TEST_FPS
#endif // _DEBUG

#include "Licence.h"
#include "SplashScreen.h"
#include "MainMenu.h"
#include "GamePlay.h"
#include "HelpMenu.h"

enum class
	GameState
{
	None,
	Licence,
	Splash,
	MainMenu,
	Help,
	Game
};

class Game
{
public:
	Game();
	void run();

	static float screenWidth;
	static float screenHeight;
	static GameState currentState;

protected:
	void processEvents();
	void update(sf::Time);
	void render();
	void loadContent();

	sf::Font m_arialFont;

	sf::RenderWindow m_Window;
#ifdef TEST_FPS
	sf::Text updateFps;
	sf::Text drawFps;
	sf::Time secondTime;
	int updateFrameCount;
	int drawFrameCount;

#endif // TEST_FPS
	Licence m_licenceScreen;
	SplashScreen m_splashScreen;
	MainMenu m_mainMenu;
	Gameplay m_mainGame;
	HelpMenu m_helpMenu;



};
#endif // !GAME_H