#include "MainMenu.h"

#include <iostream>
#include <Windows.h>
#include <conio.h>


using namespace std;

MainMenu::MainMenu()
{
	mainMenu = false;
}

MainMenu::~MainMenu()
{
}

void MainMenu::ShowMenu(ConsoleHandler* consoleData)
{
	string welcome = ">>FreakyGames<<";
	string option1 = "1- SumaTest";
	string option2 = "2- Pregunta3";
	string option3 = "3- Definite";
	string exit = "ESC - Exit";
	string clean = "                               ";
	COORD thisCursor{};

	bool mainMenu = true;

	system("cls");

	consoleData->DrawFrame(0);

	thisCursor.X = (consoleData->consoleWide / 2) - (welcome.length() / 2);
	thisCursor.Y = (consoleData->consoleHeight / 20) * 6;
	SetConsoleTextAttribute(consoleData->hwnd, 10);
	SetConsoleCursorPosition(consoleData->hwnd, thisCursor);
	cout << welcome;

	consoleData->menu1 = thisCursor;

	thisCursor.X = (consoleData->consoleWide / 2) - (option1.length() / 2);
	thisCursor.Y = (consoleData->consoleHeight / 20) * 10;
	SetConsoleTextAttribute(consoleData->hwnd, 15);
	SetConsoleCursorPosition(consoleData->hwnd, thisCursor);
	cout << option1;

	consoleData->menu2 = thisCursor;

	thisCursor.X = (consoleData->consoleWide / 2) - (option2.length() / 2);
	thisCursor.Y = (consoleData->consoleHeight / 20) * 13;
	SetConsoleTextAttribute(consoleData->hwnd, 15);
	SetConsoleCursorPosition(consoleData->hwnd, thisCursor);
	cout << option2;

	consoleData->menu3 = thisCursor;

	thisCursor.X = (consoleData->consoleWide / 2) - (option3.length() / 2);
	thisCursor.Y = (consoleData->consoleHeight / 20) * 16;
	SetConsoleTextAttribute(consoleData->hwnd, 15);
	SetConsoleCursorPosition(consoleData->hwnd, thisCursor);
	cout << option3;

	consoleData->exit = thisCursor;

	thisCursor.X = (consoleData->consoleWide / 2) - (exit.length() / 2);
	thisCursor.Y = (consoleData->consoleHeight / 20) * 19;
	SetConsoleTextAttribute(consoleData->hwnd, 8);
	SetConsoleCursorPosition(consoleData->hwnd, thisCursor);
	cout << exit;
}

void MainMenu::GetInput(ConsoleHandler* consoleData)
{
}
