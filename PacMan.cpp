/**
  * @file PacMan.cpp
  * @author Jakub Wrzosek
  * @date 29.11.2019
  */

#include "Game.h"
#include "types.h"


/**
  * Funkcja glowna programu zajmujaca sie wywolywaniem metod klasy
  * Game oraz sprawdzaniem czy nie nastapilo spelnienie warunku
  * oznaczajacego koniec gry.
  */
int main()
{
	// Program entry point.
	Game game; // Creating our game object.
	while (!game.getWindow()->isDone())
	{
		// Game
		game.handleGhosts();
		game.handleInput();
		game.update();
		game.render();
		game.restartClock();
		game.sleep();
	}

	// end of application
	return 0;
}

