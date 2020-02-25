
#include <iostream>
#include <Graphics.hpp>
#include <Window.hpp>
#include <Main.hpp>
#include <stdio.h>
#include "src/Blaine_RPG/game.hpp"



int main()
{	//initializing SMFL
	//creates the game class
	Game game;
	//bias to move

	int x = 50;

	while (1)
	{
		//game.check_active();
		game.renderer();
		game.actions();
		game.collisions();
	}
}
