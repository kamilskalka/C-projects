// ConnectFour.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "raylib.h"
#include "Game.h"
#include "Board.h"


int main()
{
	SetConfigFlags(FLAG_VSYNC_HINT);
	SetConfigFlags(FLAG_WINDOW_HIGHDPI);
	InitWindow(680, 650, "Connect Four");
	SetTargetFPS(60);
	
	Game ConnectFour;

	while (!WindowShouldClose())
	{	
		ConnectFour.update();
		ConnectFour.draw();
	}

	CloseWindow();

	return 0;
}


