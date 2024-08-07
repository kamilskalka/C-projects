#pragma once
#include "Task.h"
#include <string>
#include <fstream>
#include <filesystem>
#include <stdlib.h>
#include <iostream>
#include <sstream>
std::string lzero(int x); //funkcja formatujaca dzien z np. 1 na 01
std::string badCharCheck(std::vector<char> symbols, std::string message, std::string badmessage); //funkcja do wykrywania niedozwolonych znaków w stringu
void readFromFile(); //funkcja pozwalajaca wczytac plik, zawierajaca zabezpieczenia przed nieprawidlowymi danymi
void createNewFile(); //funkcja tworzaca nowy plik i nastepnie go otwierajaca, sprawdza czy uzytkownik podal dozwolona nazwe
void openNote(std::filesystem::path x); //funkcja pozwalajaca edytowac liste
Task createNewTask(); // funkcja tworzaca zadanie
int getTaskIndex(std::vector<Task> &Tasks); // zwraca indeks usuwanego zadania
void taskEditMenu(Task& x); //funkcja GUI do edycji zadania

