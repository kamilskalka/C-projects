#pragma once
#include "Board.h"
#include "raylib.h"
class Game
{
private:
	Board b;
	int column;
	int color;
public:
	Game() : b(), column(0),color(0) {}
	void draw();
	void update();
};

