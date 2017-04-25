#include "Game.h"

Game::Game()
{
	mGameState = Uninitialized;
}

void Game::Start()
{
	if (mGameState != Uninitialized)
	{
		return;
	}

	mWindow.create(sf::VideoMode(1024, 768, 32), "Rush Hour!");
	mGameState = Game::Playing;

	while (!isExiting())
	{
		GameLoop();
	}
	
	mWindow.close();

}

bool Game::isExiting()
{
	if (mGameState == Game::ExitGame)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Game::GameLoop()
{
	sf::Event currentEvent;

	while (mWindow.waitEvent(currentEvent))
	{
		switch (mGameState)
		{
			case Game::Playing:
			{
				mWindow.clear(sf::Color(255, 0, 0));
				mWindow.display();

				if (currentEvent.type == sf::Event::Closed)
				{
					mGameState = Game::ExitGame;
				}
				break;
			}
		}
	}
}

