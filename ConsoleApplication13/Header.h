#include "stdafx.h"
#include <iostream>
#include <clocale>
#include "Date.h"

void startTime()
{
	struct tm newtime;
	char am_pm[] = "AM";
	__time64_t long_time;
	char time_buffer[26];
	errno_t err;

	//����������� ������� � 64-������ �������
	_time64(&long_time);

	//����������� � ������� �����
	err = _localtime64_s(&newtime, &long_time);

	if (err)
	{
		printf("Invalid argument to _localtime64_s.\n");
		exit(1);
	}
}