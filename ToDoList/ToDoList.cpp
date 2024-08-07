#include "Task.h"
#include "Helpers.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <chrono>
#include <stdlib.h>
#include <filesystem>
int main()
{
	
	std::filesystem::create_directory("Lists");

	int option{};
	std::string x;
	std::string message = "To Do List. Kamil Skalka 2023\n"; //wiadomosc powitalna
	while (1)
	{
		system("cls");
		
		std::cout << message;
		std::cout << "[1] Wczytaj liste\n" << "[2] Stworz nowa liste\n" << "[3] Wyjdz\n";
		std::cin >> x;
		
		if (x.length() == 1 && std::isdigit(x[0])) //zabezpieczenie przez wpisaniem stringa 
		{
			option = stoi(x);
		}
		else
		{
			option = 4;
		}
		
		switch (option)
		{
		case 1:
			readFromFile();
			message = "";
			break;
		case 2:
			createNewFile();
			message = "Wpisz cyfre odpowiadajaca funkcji:\n";
			break;
		case 3:
			return 0;
			break;
		default:
			message = "Zle zdefiniowane polecenie. Wpisz cyfre odpowiadajaca funkcji:\n";
			break;
		}
				
	}
}

