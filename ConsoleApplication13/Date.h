#pragma once
#include <time.h>
#include <stdio.h>

class Date
{
private:
	long long millisec;
	int SYSyear;
	int SYSmonth;
	int SYSday;
public:
	Date();
	bool operator- ();
	bool operator+ ();
	void SystemDateMillisec();
	~Date();
	Date DayMonthYear();
	void DayMonthYearS();
};

