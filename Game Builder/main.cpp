// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Definitions.h"
#include "GameBuilder.h"

int main()
{
	// Calling Game Builder runner. Setting size of window and it's title
	GameBuilder* gameBuilder = new GameBuilder(SCREEN_WIDTH, SCREEN_HEIGHT, "GAME BUILDER"); 

	// Calling run function 
	gameBuilder->Run();

	return EXIT_SUCCESS;
}
