#include "ConsoleHandler.h"


ConsoleHandler::ConsoleHandler()
{
	consoleWide = 80;
	consoleHeight = 35;
	color = 144;
	userInput = '0';
	keepPlaying = true;
	hwnd = GetStdHandle(STD_OUTPUT_HANDLE);

	Init();
}

ConsoleHandler::~ConsoleHandler()
{
	std::cout << "ConsoleData deleted..." << std::endl;
}

void ConsoleHandler::Init()
{
	srand(time(NULL));
	SetConsoleFont(10, 18);
	SetConsoleSize(consoleWide, consoleHeight);
	SetConsoleCenter();
}

void ConsoleHandler::SetConsoleCenter()
{
	consoleCenter.X = consoleWide / 2;
	consoleCenter.Y = consoleHeight / 2;
}

void ConsoleHandler::SetConsoleSize(int wide, int height)
{
	consoleWide = wide;
	consoleHeight = height;
	SetConsoleCenter();

	coord.X = consoleWide;
	coord.Y = consoleHeight;

	rect.Top = 0;
	rect.Left = 0;
	rect.Bottom = coord.Y - 1;
	rect.Right = coord.X - 1;

	hwnd = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleScreenBufferSize(hwnd, coord);
	SetConsoleWindowInfo(hwnd, TRUE, &rect);

	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
	cci.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);


}

void ConsoleHandler::SetConsoleFont(int wide, int height)
{
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;

	cfi.dwFontSize.X = wide;
	cfi.dwFontSize.Y = height;
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;

	wcscpy_s(cfi.FaceName, L"Lucida Console");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}

void ConsoleHandler::DrawFrame(int delay)
{
	cursorPosition.X = 0;
	cursorPosition.Y = 0;
	SetConsoleCursorPosition(hwnd, cursorPosition);

	SetConsoleTextAttribute(hwnd, color);
	color = 187;

	cout << ' ';

	for (int i = 0; i < (consoleWide - 2); i++)
	{
		SetConsoleTextAttribute(hwnd, color);


		cout << ' ';

		Sleep(delay);
	}

	SetConsoleTextAttribute(hwnd, color);

	cout << ' ';

	cursorPosition.X = consoleWide - 1;
	cursorPosition.Y = 1;

	for (int i = 0; i < (consoleHeight - 3); i++)
	{
		SetConsoleCursorPosition(hwnd, cursorPosition);

		SetConsoleTextAttribute(hwnd, color);


		cout << ' ';
		cursorPosition.Y++;

		if (delay > 0)
		{
			Sleep(delay + 20);

		}
	}
	SetConsoleCursorPosition(hwnd, cursorPosition);

	SetConsoleTextAttribute(hwnd, color);

	cout << ' ';

	cursorPosition.X--;
	SetConsoleCursorPosition(hwnd, cursorPosition);

	for (int i = 0; i < (consoleWide - 2); i++)
	{
		SetConsoleTextAttribute(hwnd, color);


		cout << ' ';
		cursorPosition.X--;
		SetConsoleCursorPosition(hwnd, cursorPosition);
		Sleep(delay);
	}

	SetConsoleCursorPosition(hwnd, cursorPosition);

	SetConsoleTextAttribute(hwnd, color);

	cout << ' ';

	cursorPosition.Y--;
	SetConsoleCursorPosition(hwnd, cursorPosition);

	for (int i = 0; i < (consoleHeight - 2); i++)
	{
		cout << ' ' << endl;
		cursorPosition.Y--;
		SetConsoleCursorPosition(hwnd, cursorPosition);
		if (delay > 0)
		{
			Sleep(delay + 20);
		}
	}

	string digitalHappiness = "DigitalHappiness";

	cursorPosition.X = (consoleWide / 2) - (digitalHappiness.length() / 2);
	cursorPosition.Y = 0;
	SetConsoleCursorPosition(hwnd, cursorPosition);

	color = 176;

	for (int i = 0; i < digitalHappiness.length(); i++)
	{
		SetConsoleTextAttribute(hwnd, color);

		cout << digitalHappiness[i];
		if (delay > 0)
		{
			Sleep(100);
		}
	}

	cout << (char)169;

	SetConsoleTextAttribute(hwnd, Color::grey);
}

void ConsoleHandler::SetCursorPosition(int x, int y)
{
	COORD newPos{};
	newPos.X = x;
	newPos.Y = y;
	SetConsoleCursorPosition(hwnd, newPos);
}

void ConsoleHandler::SetCursorPosition(Vector2<int> position)
{
	SetCursorPosition(position.x, position.y);
}

void ConsoleHandler::SetCursorAfter(Vector2<int> position, string text)
{
	int x = position.x + text.length() + 1;
	int y = position.y;
}

COORD ConsoleHandler::GetConsoleCenter()
{
	return consoleCenter;
}

Vector2<int> ConsoleHandler::GetConsoleCenterV2()
{
	return Vector2<int>(consoleCenter.X, consoleCenter.Y);
}

void ConsoleHandler::PrintText(string text, Vector2<int> position)
{
	SetCursorPosition(position);
	cout << text;
}

void ConsoleHandler::PrintCenteredText(string text, int desplacementX, int desplacementY)
{
	Vector2<int> center = GetConsoleCenterV2();
	center.x -= text.length() / 2;
	center.x -= desplacementX / 2;
	center.y += desplacementY;

	PrintText(text, center);
}

void ConsoleHandler::PrintCenteredText(string text)
{
	PrintCenteredText(text, 0, 0);
}

void ConsoleHandler::ClearText(string text, Vector2<int> position)
{
	SetCursorPosition(position);

	ClearText(text);
}

void ConsoleHandler::ClearText(string text)
{
	for (int i = 0; i < text.length(); i++)
	{
		cout << ' ';
	}
}

void ConsoleHandler::ClearInput(string text, Vector2<int> position, string textInput)
{
	SetCursorAfter(position, text);
	ClearText(textInput);
}

void ConsoleHandler::ClearConsole()
{
	system("cls");
	DrawFrame(0);
}
