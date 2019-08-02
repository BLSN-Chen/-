#include "config.h"

void SetColor(int foreColor, int backColor)
{
	HANDLE winHandle;      //句柄
	winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	//设置文字颜色
	SetConsoleTextAttribute(winHandle, foreColor + backColor * 0x10);
}

void hide_cursor()//隐藏光标
{
	HANDLE h_GAME = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor_info;
	GetConsoleCursorInfo(h_GAME, &cursor_info);
	cursor_info.bVisible = false;
	SetConsoleCursorInfo(h_GAME, &cursor_info);
}
void show_cursor()//显示光标
{
	HANDLE h_GAME = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor_info;
	GetConsoleCursorInfo(h_GAME, &cursor_info);
	cursor_info.bVisible = true;
	SetConsoleCursorInfo(h_GAME, &cursor_info);
}

void SetPosition(int x, int y)
{
	HANDLE winHandle;
	winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	//设置光标位置
	COORD pos = { x, y };
	SetConsoleCursorPosition(winHandle, pos);
}

void printByxy(int x, int y, string msg)
{
	SetPosition(x, y);
	cout << msg;
}

void printByxy(int x, int y, int num)
{
	SetPosition(x, y);
	cout << num;
}

void Clear(int x, int y, int rowCount, int a)
{
	int i, j;
	for (i = 0; i < rowCount; i++)
	{
		SetPosition(x, y + i);
		for (j = 0; j < a; j++)
		{
			cout << " ";
		}
	}
}
