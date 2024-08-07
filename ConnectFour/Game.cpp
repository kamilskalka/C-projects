#include "Game.h"
#include <cmath>
void Game::draw()
{
	BeginDrawing();

	ClearBackground(BLUE);
	for (int k = 0; k < 7; k++) //rysowanie planszy
	{

		for (int i = 0; i < 6; i++)
		{
			DrawCircle((70 + k * 90), (140 + i * 90), 39, WHITE);
		}

	}

	b.draw_chips();
	if (color == 0)
	{
		DrawCircle((70 + column * 90), (50), 35, RED);
		DrawCircle((70 + column * 90), (50), 27, MAROON);
	}
	if (color == 1)
	{
		DrawCircle((70 + column * 90), (50), 35, YELLOW);
		DrawCircle((70 + column * 90), (50), 27, GOLD);
	}
	
	switch (b.check_status())
	{
	case -1:
		DrawText("GAME OVER : NO MORE SPACE", 33, 20, 40, BLACK);
		DrawText("PRESS R TO RESTART", 96, 60, 40, BLACK);
		break;
	case 0:

		break;
	case 1:
		DrawText("GAME OVER : RED WINS", 90, 20, 40, BLACK);
		DrawText("PRESS R TO RESTART", 96, 60, 40, BLACK);
		break;
	case 2:
		DrawText("GAME OVER : YELLOW WINS", 60, 20, 40, BLACK);
		DrawText("PRESS R TO RESTART", 96, 60, 40, BLACK);
		break;
	}
	
	EndDrawing();
}

void Game::update()
{
	
	switch (b.check_status())
	{
	case 0:
		if (IsKeyPressed(KEY_RIGHT))
		{
			column = (column + 1) % 7;
		}
		if (IsKeyPressed(KEY_LEFT))
		{
			column = column - 1;

			if (column == -1)
			{
				column = 6;
			}
		}

		if (IsKeyPressed(KEY_DOWN))
		{
			if (b.drop_chip(column, color))
			{
				color = (color + 1) % 2;
			}
		}

		break;
	default:
		break;
	}
	if (b.check_status() != 0 )
	{
		if (IsKeyPressed(KEY_R))
		{
			b.clear();
			color = 0;
			column = 0;
		}
	}
}

