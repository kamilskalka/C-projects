#pragma once
#include <string>
#include <chrono>
class Task
{
private:
	std::string taskname{};
	bool completion{};
	struct
	{
		std::chrono::year_month_day date{};
		int hour{};
		int minute{};
	} deadline{};
public:
	Task();
	void set_task(std::string newtask); //ustawia zadanie
	std::string get_task(void) const; //zwraca zadanie
	bool set_date(int newday, int newmonth, int newyear, int newhour, int newminute); //ustawia date i zwraca czy jest poprawna
	std::string get_date(void); //zwraca date w stringu; np. 02.07.2024 22:12
	bool is_done(void); //sprawdza czy zadanie jest wykonane
	std::string intoString(void); //zwraca linijke w stringu
	std::string intoPrettyString(void); //zwraca linjke w stringu tylko ladna
	void switch_done(void); //zmienia zadanie z niewykonanego na wykonane i na odwrot
};

