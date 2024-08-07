#include "Helpers.h"
#include "Task.h"

std::string lzero(int x) 
{
	if (x < 10)
	{
		return "0" + std::to_string(x);
	}
	else
	{
		return std::to_string(x);
	}
	
}

std::string badCharCheck(std::vector<char> symbols, std::string message, std::string badmessage)
{
	
	std::string msg = message;
	std::string filename;
	std::cin.ignore(); //naprawilo to ze jak byl znak niedozwolony na pierwszym miejscu to go skipowalo
	bool not_valid = true;
	
	while (not_valid)
	{	
		not_valid = false;
		system("cls");
		std::cout << msg;
		std::getline(std::cin, filename);
		for (char i : filename) //sprawdzanie czy nazwa posiada znaki niedozwolone, zawarte w wektorze symbols
		{
			for (char k : symbols)
			{
				if (k == i)
				{
					msg = badmessage;
					not_valid = true;
				}
			}
		}
	}
	return filename;
	
	
	
};

void taskEditMenu(Task& y)
{
	int option = 0;
	std::string message = "\n[0] Cofnij\n[1] Zmien zadanie\n[2] Zmien date i godzine\n[3] Zmien status wykonania\n";
	bool exit = true;
	while (exit)
	{
		system("cls");
		std::cout << y.intoPrettyString()<<"\n";
		std::cout << message;
		std::string x;
		std::cin >> x;
		try //zabezpieczenie przed blednym wejsciem
		{
			option = stoi(x);
		}
		catch (std::exception)
		{
			message = "\nBledny argument.\n\n[0] Cofnij (zapisz)\n[1] Zmien zadanie\n[2] Zmien date i godzine\n[3] Zmien status wykonania\n";
			continue;
		}
		std::vector<char> v = { '\t' };
		std::string newTask;
		std::string newday, newmonth, newyear, newhour, newminute;
		bool isGood = true;
		switch (option)
		{
		case 0:
			exit = false;
			break;
		case 1:
			message = "\n[0] Cofnij (zapisz)\n[1] Zmien zadanie\n[2] Zmien date i godzine\n[3] Zmien status wykonania\n";
			system("cls");
			newTask = badCharCheck(v, "Wprowadz nowe zadanie\n", "Tabulator w nazwie. zamien go na spacje:\n");
			y.set_task(newTask);
			break;
		case 2:
			message = "\n[0] Cofnij (zapisz)\n[1] Zmien zadanie\n[2] Zmien date i godzine\n[3] Zmien status wykonania\n";
			system("cls");
			std::cout << "Wprowadz dzien:\n";
			std::cin >> newday;
			system("cls");
			std::cout << "Wprowadz miesiac:\n";
			std::cin >> newmonth;
			system("cls");
			std::cout << "Wprowadz rok:\n";
			std::cin >> newyear;
			system("cls");
			std::cout << "Wprowadz godzine:\n";
			std::cin >> newhour;
			system("cls");
			std::cout << "Wprowadz minuty:\n";
			std::cin >> newminute;
			try
			{
				isGood = y.set_date(stoi(newday), stoi(newmonth), stoi(newyear), stoi(newhour), stoi(newminute));
			}
			catch (std::exception)
			{
				isGood = false;
			}
			if (!isGood)
			{
				message = "\nBledna data.\n[0] Cofnij (zapisz)\n[1] Zmien zadanie\n[2] Zmien date i godzine\n[3] Zmien status wykonania\n";
			}
			break;
		case 3:
			message = "\n[0] Cofnij (zapisz)\n[1] Zmien zadanie\n[2] Zmien date i godzine\n[3] Zmien status wykonania\n";
			y.switch_done();
			break;
		default:
			break;
		}
	}
	
}

Task createNewTask()
{
	Task x;
	x.set_task("Nowe zadanie");
	return x;
}

int getTaskIndex(std::vector<Task> &Tasks)
{
	int y = Tasks.size();
	std::string message = "Wprowadz numer zadania:\n";
	while (1)
	{
		system("cls");
		for (int i = 0; i < Tasks.size(); i++)
		{

			std::cout << i + 1 << ". " << Tasks[i].intoPrettyString() << "\n\n";
		}
		std::cout << message;
		int option;
		std::string x;
		std::cin >> x;
		try //zabezpieczenie przed blednym wejsciem
		{
			option = stoi(x) - 1;
		}
		catch (std::exception)
		{
			message = "Bledny argument.\nWprowadz numer zadania:\n";
			continue;
		}
		if (option < y && option >= 0)
		{
			return option;
		}
		else
		{
			message = "Nie ma takiego zadania.\nWprowadz numer zadania:\n";
		}
	
	}
}

void createNewFile()
{
	std::vector<char> symbols = { '\\','/', ':', '*','?', '\"', '<', '>', '|'};
	std::string filename = badCharCheck(symbols, "Wpisz nazwe pliku:\n", "Niedozwolony znak w nazwie pliku. Wpisz ponownie nazwe:\n");
	std::ofstream file;
	file.open(".\\Lists\\" + filename + ".txt");
	file.close();
	openNote(".\\Lists\\" + filename + ".txt");
}

void openNote(std::filesystem::path x)
{
	system("cls");
	std::vector<Task> Tasks;
	std::fstream list;
	list.open(x);
	std::string note_content;
	while (std::getline(list, note_content, '\t'))
	{
		Task currentTask{};
		currentTask.set_task(note_content);
		
		std::string day,month,year,hour,minute;
		std::getline(list, day, '.');
		std::getline(list, month, '.');
		std::getline(list, year, '\t');
		std::getline(list, hour, ':');
		std::getline(list, minute, '\t');
		currentTask.set_date(stoi(day), stoi(month), stoi(year),stoi(hour),stoi(minute));
			
		std::string done;
		std::getline(list, done);
		if (done == "zrobione")
		{
			currentTask.switch_done();
		}

		Tasks.push_back(currentTask);
	}
	bool exit = false;
	while(!exit)
	{
		system("cls");
		
		for (int i = 0; i < Tasks.size(); i++)
		{

			std::cout << i + 1 << ". " << Tasks[i].intoPrettyString() << "\n\n";
		}

		
		std::cout << "[0] Zapisz\n" << "[1] Dodaj zadanie\n";
		if (Tasks.size() > 0)
		{
			std::cout << "[2] Edytuj zadanie\n" << "[3] Usun zadanie\n";
		}
		
		int option{};
		std::string x;
		std::cin >> x;

		if (x.length() == 1 && std::isdigit(x[0])) //zabezpieczenie przez wpisaniem stringa 
		{
			option = stoi(x);
		}
		else
		{
			option = 4;
		}
		if (Tasks.size() > 0)
		{
			switch (option)
			{
			case 0:
				exit = true;
				break;
			case 1:
				Tasks.push_back(createNewTask());
				break;
			case 2:
				taskEditMenu(Tasks[getTaskIndex(Tasks)]);
				break;
			case 3:
				Tasks.erase(Tasks.begin() + getTaskIndex(Tasks));
				break;
			default:
				break;
			}
		}
		else
		{
			switch (option)
			{
			case 0:
				exit = true;
			case 1:
				Tasks.push_back(createNewTask());
				break;			
			default:
				break;
			}
		}
	}
	
	list.close();
	list.open(x);
	for (auto i : Tasks)
	{
		list << i.intoString() << "\n";
	}
	list.close();
}

void readFromFile() 
{
	system("cls"); // czyszczenie terminala
	std::vector<std::filesystem::path> paths; //wektor sciezek do plikow z listami
	for (const auto &i : std::filesystem::directory_iterator(".\\Lists"))
	{
		paths.push_back(i.path());
	}
	if (paths.size() == 0)
	{
		std::cout << "Brak dostepnych list\n" << "[0] Cofnij";
		std::string x;
		std::cin >> x;
	}
	else
	{
		std::string message = "";
		int option = 0;
		while (1)
		{
			system("cls");
			std::cout << message;
			std::cout << "Dostepne listy:\n" << "[0] Cofnij\n" << "\n";

			for (int i = 0; i < paths.size();i++)
			{
				std::cout << "[" << i + 1 << "] " << paths[i].filename().string() << "\n";
			}
			std::string x;
			std::cin >> x;
			try //zabezpieczenie przed blednym wejsciem
			{
				option = stoi(x) - 1;
			}
			catch (std::exception)
			{
				message = "Bledny argument\n";
				continue;
			}
			if (option == -1)
			{
				return;
			}
			else if (option >= 0 && option < paths.size())
			{
				break;
			}
			else
			{
				message = "Nie ma pliku o takim indeksie\n";
			}
		}
		openNote(paths[option]);
	}
	
}