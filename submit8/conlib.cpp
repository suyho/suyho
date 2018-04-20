#include<stdio.h>
#include<conio.h>
#include<Windows.h>

HANDLE stdout_handle;

void init_lib()
{
	stdout_handle = GetStdHandle(STD_OUTPUT_HANDLE);

}

void cls()
{
	COORD cur;
	DWORD num;

	cur.X = 0;
	cur.Y = 0;
	FillConsoleOutputCharacter(stdout_handle, ' ', 80 * 30, cur, &num);
}

void setPosition(int x, int y) {
	COORD cur;

	if ((x >= 0) && (x < 80) && (y >= 0) && (y < 24))
	{
		cur.X = x;
		cur.Y = y;
		SetConsoleCursorPosition(stdout_handle, cur);
	}
}

void printxy(int x, int y,const char str[])
{
	COORD cur;

	if ((x >= 0) && (x < 80) && (y >= 0) && (y < 24))
	{
		cur.X = x;
		cur.Y = y;
		SetConsoleCursorPosition(stdout_handle, cur);
		printf(str);
	}
}

char checkkey()
{
	char key;

	key = '\0';
	while (_kbhit())
	{
		key = _getch();
	}
	return key;
}

void wait()
{
	Sleep(100);
}