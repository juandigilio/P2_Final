#include "MainMenu.h"

#include <iostream>
#include <Windows.h>
#include <conio.h>

#include "GameData.h"

using namespace std;
using namespace SumaTestData;

MainMenu::MainMenu(ConsoleHandler* consoleData)
{
	mainMenu = false;

	this->consoleData = consoleData;
}

MainMenu::~MainMenu()
{
	delete sumaTest;
}

void MainMenu::Init()
{
	ShowMenu();
	GetInput();
}

void MainMenu::InitSumaTest()
{
	Vector2<int> center{};
	center.x = consoleData->GetConsoleCenter().X;
	center.y = consoleData->GetConsoleCenter().Y;


	welcomePos.x = center.x - welcome.length() / 2;
	welcomePos.y = center.y;
	typePos.x = center.x - type.length() / 2;
	typePos.y = center.y;
	integerPos.x = center.x - integer.length() / 2;
	integerPos.y = center.y + 1;
	decimalPos.x = center.x - decimal.length() / 2;
	decimalPos.y = center.y + 2;
	valuesPos.x = center.x - values.length() / 2;
	valuesPos.y = center.y;
	values2Pos.x = center.x - values.length() / 2;
	values2Pos.y = center.y + 1;
	minPos.x = center.x - minText.length() / 2;
	minPos.y = center.y + 2;
	maxPos.x = center.x - maxText.length() / 2;
	maxPos.y = center.y + 3;
	roundsQntyPos.x = center.x - roundsQnty.length() / 2;
	roundsQntyPos.y = center.y;
	roundLengthPos.x = center.x - roundLength.length() / 2;
	roundLengthPos.y = center.y;
	delayPos.x = center.x - delayText.length() / 2;
	delayPos.y = center.y;

	SetSumaTestDifficulty();
}

void MainMenu::SetSumaTestDifficulty()
{
	system("cls");

	consoleData->DrawFrame(0);

	consoleData->PrintText(welcome, welcomePos);

	consoleData->PrintText(type, typePos);
	consoleData->PrintText(integer, integerPos);
	consoleData->PrintText(decimal, decimalPos);

	char input{};

	do
	{
		input = _getch();

		if (input == '2')
		{
			isDecimal = true;
		}
		else
		{
			isDecimal = false;
		}

	} while (input != '1' && input != '2');

	consoleData->ClearText(type, typePos);
	consoleData->ClearText(integer, integerPos);
	consoleData->ClearText(decimal, decimalPos);


	if (isDecimal)
	{
		sumaTest = new SumaTest<float>(consoleData);
		SumaTest<float>* sumaTestFloat = static_cast<SumaTest<float>*>(sumaTest);
		sumaTestFloat->Init();
	}
	else
	{
		sumaTest = new SumaTest<int>(consoleData);
		SumaTest<int>* sumaTestInt = static_cast<SumaTest<int>*>(sumaTest);
		sumaTestInt->Init();
	}
}

void MainMenu::ShowMenu()
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

void MainMenu::GetInput()
{
	mainMenu = true;

	do
	{
		consoleData->userInput = _getch();

	} while (consoleData->userInput != '1' && consoleData->userInput != '2' && consoleData->userInput != '3' && consoleData->userInput != 27);

	switch (consoleData->userInput)
	{
		case '1':
		{
			InitSumaTest();
			break;
		}
		case '2':
		{
			//menu->ShowInstructions(console);
			break;
		}
		case '3':
		{
			//menu->ShowMain(console);
			break;
		}
		case 27:
		{
			consoleData->keepPlaying = false;
			break;
		}
	}
}
