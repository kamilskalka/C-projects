#include "Task.h"
#include "Helpers.h"
Task::Task() { completion = false; }


void Task::set_task(std::string newtask) { taskname = newtask; }


std::string Task::get_task(void) const { return taskname; }


bool Task::set_date(int newday, int newmonth, int newyear, int newhour, int newminute)
{
	std::chrono::year_month_day temp = std::chrono::year{ newyear }/newmonth/newday;
	if (temp.ok() && newhour < 24 && newminute < 60 && newhour >= 0 && newminute >=0) //sprawdzenie czy podana data jest mozliwa
	{
		deadline.hour = newhour;
		deadline.minute = newminute;
		deadline.date = temp;
		return true;
	}
	else
	{
		return false;
	}
}


std::string Task::get_date(void)
{
	return lzero((unsigned)deadline.date.day()) + "." + lzero((unsigned)deadline.date.month()) + "." + std::to_string((int)deadline.date.year()) + '\t' + lzero(deadline.hour) + ":" + lzero(deadline.minute);
}


bool Task::is_done(void)
{
	return completion;
}



std::string Task::intoString(void)
{
	std::string x;
	x = taskname + '\t' + get_date() + '\t' + (completion ? "zrobione" : "niezrobione");
	return x;
}

std::string Task::intoPrettyString(void)
{
	std::string x;
	x = taskname + "\n   " + get_date() + " \| " + (completion ? "zrobione" : "niezrobione");
	return x;
}

void Task::switch_done(void) 
{
	completion = (completion + 1) % 2;
}