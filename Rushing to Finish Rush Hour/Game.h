#pragma once
#include "Shared.h"


//This class is similar to the "Wrappers" that Andy always has us writing. 

class Game
{

public:


	Game();
	void Start();

private:
	bool isExiting();
	void GameLoop();

	enum GameState
	{
		Uninitialized, LoadingScreen, Paused, Menu, Playing, ExitGame
	};

	GameState mGameState;

	sf::RenderWindow mWindow;



};