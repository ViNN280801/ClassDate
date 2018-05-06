#include "stdafx.h"
#include "Date.h"
#include <string>
#include <stdio.h>
#include <cmath>
#include"Header.h"

//Конструктор по умолчанию
Date::Date()
{
	millisec = 0;
	SYSyear = 0;
	SYSmonth = 0;
	SYSday = 0;
}

void Date::SystemDateMillisec()
{
	struct tm newtime;
	char am_pm[] = "AM";
	__time64_t long_time;
	char time_buffer[26];
	errno_t err;

	//Конвертация времени в 64-битную систему
	_time64(&long_time);

	//Конвертация в местное время
	err = _localtime64_s(&newtime, &long_time);

	if (err)
	{
		printf("Invalid argument to _localtime64_s.\n");
		exit(1);
	}

	//Вечернее время
	if (newtime.tm_hour > 12)
	{
		strcpy_s(am_pm, sizeof(am_pm), "PM");
		printf("%d:%d %s\n", newtime.tm_hour, newtime.tm_min, am_pm);
		millisec = newtime.tm_hour * 3600000 + newtime.tm_min * 60000 + newtime.tm_sec * 1000;
		printf("Millisec = %lld millisec.\n\n", millisec);
	}
	//Буднее время
	else
	{
		strcpy_s(am_pm, sizeof(am_pm), "AM");
		printf("%d:%d %s\n", newtime.tm_hour, newtime.tm_min, am_pm);
		millisec = newtime.tm_hour * 3600000 + newtime.tm_min * 60000 + newtime.tm_sec * 1000;
		printf("Millisec = %lld millisec.\n\n", millisec);
	}
}

Date::~Date()
{
}

Date Date::DayMonthYear()
{
	struct tm newtime;
	__time64_t long_time;
	errno_t err;

	//Конвертация времени в 64-битную систему
	_time64(&long_time);

	//Конвертация в местное время
	err = _localtime64_s(&newtime, &long_time);

	if (err)
	{
		printf("Invalid argument to _localtime64_s.\n");
		exit(1);
	}

	printf("%d.%d.%d\n\n", newtime.tm_mday, newtime.tm_mon + 1, 1900 + newtime.tm_year);

	SYSyear = 1900 + newtime.tm_year;
	SYSmonth = newtime.tm_mon + 1;
	SYSday = newtime.tm_mday;

	return Date();
}

void Date::DayMonthYearS()
{
	struct tm newtime;
	__time64_t long_time;
	errno_t err;

	//Конвертация времени в 64-битную систему
	_time64(&long_time);

	//Конвертация в местное время
	err = _localtime64_s(&newtime, &long_time);

	if (err)
	{
		printf("Invalid argument to _localtime64_s.\n");
		exit(1);
	}

	printf("%d.%d.%d\n\n", newtime.tm_mday, newtime.tm_mon + 1, 1900 + newtime.tm_year);
}

bool Date::operator-()
{
	int Day = 0, Month = 0, Year = 0;
	long date = 0;
	struct tm newtime;
	__time64_t long_time;
	errno_t err;

	//Конвертация времени в 64-битную систему
	_time64(&long_time);

	//Конвертация в местное время
	err = _localtime64_s(&newtime, &long_time);

	if (err)
	{
		printf("Invalid argument to _localtime64_s.\n");
		exit(1);
	}

	printf("Введите дату по шаблону (day.month.year): \n");
	scanf_s("%d.%d.%d", &Day, &Month, &Year);


	if (SYSyear > Year && SYSmonth > Month && SYSday > Day)
		date = ((SYSyear - Year) * 365) + ((SYSmonth - Month) * newtime.tm_mday) + SYSday - Day;
	else if (SYSyear < Year && SYSmonth > Month && SYSday > Day)
		date = ((Year - SYSyear) * 365) + ((SYSmonth - Month) * newtime.tm_mday) + SYSday - Day;
	else if (SYSyear < Year && SYSmonth < Month && SYSday > Day)
		date = ((Year - SYSyear) * 365) + ((Month - SYSmonth) * newtime.tm_mday) + SYSday - Day;
	else if (SYSyear < Year && SYSmonth < Month && SYSday < Day)
		date = ((Year - SYSyear) * 365) + ((Month - SYSmonth) * newtime.tm_mday) + Day - SYSday;
	else if (SYSyear > Year && SYSmonth < Month && SYSday < Day)
		date = ((SYSyear - Year) * 365) + ((Month - SYSmonth) * newtime.tm_mday) + Day - SYSday;
	else if (SYSyear > Year && SYSmonth > Month && SYSday < Day)
		date = ((SYSyear - Year) * 365) + ((SYSmonth - Month) * newtime.tm_mday) + Day - SYSday;
	else if (SYSyear > Year && SYSmonth < Month && SYSday > Day)
		date = ((SYSyear - Year) * 365) + ((Month - SYSmonth) * newtime.tm_mday) + SYSday - Day;
	else if (SYSyear < Year && SYSmonth > Month && SYSday < Day)
		date = ((Year - SYSyear) * 365) + ((SYSmonth - Month) * newtime.tm_mday) + Day - SYSday;
	else if (SYSyear == Year && SYSmonth == Month && SYSday == Day)
		date = 0;
	else if (SYSyear < Year && SYSmonth == Month && SYSday == Day)
		date = ((Year - SYSyear) * 365);
	else if (SYSyear > Year && SYSmonth == Month && SYSday == Day)
		date = ((SYSyear - Year) * 365);
	else if (SYSyear < Year && SYSmonth == Month && SYSday < Day)
		date = ((Year - SYSyear) * 365) + Day - SYSday;
	else if (SYSyear > Year && SYSmonth == Month && SYSday > Day)
		date = ((SYSyear - Year) * 365) + SYSday - Day;
	else if (SYSyear == Year && SYSmonth < Month && SYSday == Day)
		date = ((Month - SYSmonth) * newtime.tm_mday);
	else if (SYSyear == Year && SYSmonth > Month && SYSday == Day)
		date = ((SYSmonth - Month) * newtime.tm_mday);
	else if (SYSyear == Year && SYSmonth == Month && SYSday > Day)
		date = SYSday - Day;
	else if (SYSyear == Year && SYSmonth == Month && SYSday < Day)
		date = Day - SYSday;

	printf("Дни до: %ld\n\n", date);
	return date;
}

bool Date::operator+()
{
	int DayPlus = 0, MonthPlus = 1;
	printf("Введите на сколько дней вы хотите увеличить текущий день? \n");
	scanf_s("%d", &DayPlus);

	struct tm newtime;
	__time64_t long_time;
	errno_t err;

	//Конвертация времени в 64-битную систему
	_time64(&long_time);

	//Конвертация в местное время
	err = _localtime64_s(&newtime, &long_time);

	if (err)
	{
		printf("Invalid argument to _localtime64_s.\n");
		exit(1);
	}

	if (newtime.tm_mon == 0)
		MonthPlus = 31;
	else if (newtime.tm_mon == 1)
		MonthPlus = 28;
	else if (newtime.tm_mon == 2)
		MonthPlus = 31;
	else if (newtime.tm_mon == 3)
		MonthPlus = 30;
	else if (newtime.tm_mon == 4)
		MonthPlus = 31;
	else if (newtime.tm_mon == 5)
		MonthPlus = 30;
	else if (newtime.tm_mon == 6)
		MonthPlus = 31;
	else if (newtime.tm_mon == 7)
		MonthPlus = 30;
	else if (newtime.tm_mon == 8)
		MonthPlus = 31;
	else if (newtime.tm_mon == 9)
		MonthPlus = 30;
	else if (newtime.tm_mon == 10)
		MonthPlus = 31;
	else if (newtime.tm_mon == 11)
		MonthPlus = 30;

	if ((DayPlus + SYSday) > MonthPlus && ((DayPlus % 2) + SYSday) < MonthPlus)
		printf("Дата: %d.%d.%d\n\n", (abs((MonthPlus + SYSday) - DayPlus)), newtime.tm_mon + 2, 1900 + newtime.tm_year);

	else if ((DayPlus + SYSday) > MonthPlus && DayPlus < MonthPlus)
		printf("Дата: %d.%d.%d\n\n", (abs(MonthPlus - (SYSday + DayPlus)), newtime.tm_mon + 2, 1900 + newtime.tm_year));

	else if ((DayPlus + SYSday) < MonthPlus)
		printf("Дата: %d.%d.%d\n\n", (DayPlus + SYSday, newtime.tm_mon + 1, 1900 + newtime.tm_year));

	return false;
}
