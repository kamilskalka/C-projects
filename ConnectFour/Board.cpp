#include "Board.h"
#include "raylib.h"
#include <iostream>
#include <cmath>
Board::Board()
{
	
	
	chips.resize(7); //ustalenie wielkosci macierzy zetonow
	for (int i = 0; i < 7; i++)
	{
		chips[i].resize(6);
	}

	for (int k = 0; k < 7; k++) //ustawianie zer na macierzy zetonow
	{
		for (int i = 0; i < 6; i++)
		{
			chips[k][i] = 0;
		}
	}

}

//std::vector<std::vector<int>>& Board::get_chips() { return chips; }

bool Board::drop_chip(int column, int chip)//zwraca false gdy kolumna jest zapełniona i nie przypisuje wtedy zadnej wartosci
{										   //0-RED 1-YELLOW
	int k = 5;
	while (1)
		if (k == -1)
		{
			return false;
			break;
		}
		else if (chips[column][k] == 0)
		{
			chips[column][k] = chip+1;
			return true;
			break;
		}
		else
		{
			k = k - 1;
		}
	}



void Board::draw_chips()
{
	for (int i = 0; i < 7; i++) //rysowanie wrzuconych zetonow
	{
		for (int k = 0; k < 6; k++)
		{
			int colorint;
			colorint = chips[i][k];
			if (colorint == 1)
			{
				DrawCircle((70 + i * 90), (140 + k * 90), 35, RED);
				DrawCircle((70 + i * 90), (140 + k * 90), 27, MAROON);
			}
			else if (colorint == 2)
			{
				DrawCircle((70 + i * 90), (140 + k * 90), 35, YELLOW);
				DrawCircle((70 + i * 90), (140 + k * 90), 27, GOLD);
			}
		}
	}
}


int Board::check_status()
{
	int count = 0;
	int prev_color = 0;
	

	
	for (int i = 0; i < 6; i++)//po skosie "\"
	{
		for (int k = 0; k < -abs(i-2.5)+6.5; k++)
		{
			if (chips[0.5 * (abs(i - 2) + i - 2) + k][0.5 * (abs(i - 2) - i + 2) + k] == prev_color && prev_color == 1)
			{
				count++;
			}
			else if (chips[0.5 * (abs(i - 2) + i - 2) + k][0.5 * (abs(i - 2) - i + 2) + k] == prev_color && prev_color == 2)
			{
				count = count - 1;
			}
			else if (chips[0.5 * (abs(i - 2) + i - 2) + k][0.5 * (abs(i - 2) - i + 2) + k] != prev_color)
			{
				count = 0;
			}
			prev_color = chips[0.5 * (abs(i - 2) + i - 2) + k][0.5 * (abs(i - 2) - i + 2) + k];
			if (count == -3)
			{
				return 2;
			}
			if (count == 3)
			{
				return 1;
			}
		}
		count = 0;
		prev_color = 0;
	}
								
	for (int i = 0; i < 6; i++)//po skosie "/"
	{
		for (int k = 0; k < -abs(i - 2.5) + 6.5; k++)
		{
			if (chips[0.5 * (abs(i - 2) + i - 2) + k][0.5 * (i-2-abs(i-2)) - k +5] == prev_color && prev_color == 1)
			{
				count++;
			}
			else if (chips[0.5 * (abs(i - 2) + i - 2) + k][0.5 * (i - 2 - abs(i - 2)) - k +5] == prev_color && prev_color == 2)
			{
				count = count - 1;
			}
			else if (chips[0.5 * (abs(i - 2) + i - 2) + k][0.5 * (i - 2 - abs(i - 2)) - k +5] != prev_color)
			{
				count = 0;
			}
			prev_color = chips[0.5 * (abs(i - 2) + i - 2) + k][0.5 * (i - 2 - abs(i - 2)) - k +5];
			if (count == -3)
			{
				return 2;
			}
			if (count == 3)
			{
				return 1;
			}
		}
		count = 0;
		prev_color = 0;
	}

	for (int i = 0; i < 7; i++)//szukanie pionowo
	{
		for (int k = 0; k < 6; k++)
		{
			if (chips[i][k] == prev_color && prev_color == 1)
			{
				count++;
			}
			else if (chips[i][k] == prev_color && prev_color == 2)
			{
				count = count - 1;
			}
			else if (chips[i][k] != prev_color)
			{
				count = 0;
			}
			prev_color = chips[i][k];
			if (count == -3)
			{
				return 2;
			}
			if (count == 3)
			{
				return 1;
			}
		}
		count = 0;
		prev_color = 0;
	}

	int empty_spaces = 0;

	for (int k = 0; k < 6; k++)//szukanie poziomo - ostatnie szukanie, sprawdza rowniez czy plansza jest pelna
	{
		for (int i = 0; i < 7; i++)
		{
			if (chips[i][k] == prev_color && prev_color == 1)
			{
				count++;
			}
			else if (chips[i][k] == prev_color && prev_color == 2)
			{
				count = count - 1;
			}
			else if (chips[i][k] != prev_color)
			{
				count = 0;
			}
			prev_color = chips[i][k];
			if (count == -3)
			{
				return 2;
			}
			if (count == 3)
			{
				return 1;
			}
			if (chips[i][k] == 0)
			{
				empty_spaces++;
			}
			
		}
		count = 0;
		prev_color = 0;
		
	}
	
	if (empty_spaces == 0)
	{
		return -1;
	}
	return 0;
}

void Board::clear()
{
	for (int k = 0; k < 7; k++) //ustawianie zer na macierzy zetonow
	{
		for (int i = 0; i < 6; i++)
		{
			chips[k][i] = 0;
		}
	}
}