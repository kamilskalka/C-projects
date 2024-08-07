#pragma once
#include <vector>


class Board
{
private:
	std::vector<std::vector<int>> chips; //macierz przechowujaca zetony jako cyfry: 0 - brak zetonu, 1 - zeton czerwony, 2 - zeton zolty
public:
	Board();
	int check_status(); // metoda sprawdzajaca czy ktos juz polaczyl 4 zetony ze soba, jesli tak to zwraca ktory gracz to zrobil (-1 - koniec miejsca na planszy, 0 - brak polaczenia, 1 - wygraly zetony czerwone, 2- wygraly zetony zolte) 
	bool drop_chip(int column, int chip); // metoda wrzucajaca zeton na plansze, zabezpiecznie przed overflow planszy
	void draw_chips(); // metoda rysujaca zetony wrzucone na plansze
	void clear(); // metoda przywracajaca plansze do stanu poczatkowego
};

