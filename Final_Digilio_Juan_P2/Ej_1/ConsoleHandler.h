#pragma once

#include "Vector2.h"

#include <iostream>
#include <Windows.h>

using namespace std;


enum Color
{
	grey = 8,
	blue = 9,
	green = 10,
	red = 12,
	violet = 13,
	yellow = 14,
	white = 15,
};

class ConsoleHandler
{
private:

	COORD cursorPosition;
	HANDLE hwnd;
	CONSOLE_FONT_INFOEX cfi;
	SMALL_RECT rect;
	COORD coord;
	CONSOLE_CURSOR_INFO cci;
	int consoleWide;
	int consoleHeight;
	int color;
	COORD consoleCenter;

	void Init();
	void SetConsoleCenter();

public:

	char userInput;
	bool keepPlaying;
	
	COORD menu1;
	COORD menu2;
	COORD menu3;
	COORD exit;

	ConsoleHandler();
	~ConsoleHandler();

	
	void SetConsoleSize(int wide, int height);
	void SetConsoleFont(int wide, int height);
	void DrawFrame(int delay);
	void SetCursorPosition(int x, int y);
	void SetCursorPosition(Vector2<int> position);
	void SetCursorPosition(Vector2<int> position, string text);
	COORD GetConsoleCenter();
	Vector2<int> GetConsoleCenterV2();
};

