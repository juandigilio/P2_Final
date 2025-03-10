#include "MainMenu.h"

#include <iostream>
#include <Windows.h>
#include <conio.h>

#include "GameData.h"
#include "LauncherSumaTest.h"
#include "LauncherPregunta3.h"
#include "Definite.h"

using namespace std;
using namespace SumaTestData;
using namespace MainMenuData;

MainMenu::MainMenu(ConsoleHandler* consoleData)
{
	mainMenu = false;

	this->consoleData = consoleData;

	Init();
}

MainMenu::~MainMenu()
{
}

void MainMenu::Init()
{
	srand(time(0));

	Vector2<int> center = consoleData->GetConsoleCenterV2();

	menuWelcomePos.x = center.x - (menuWelcome.length() / 2);
	menuWelcomePos.y = (consoleData->consoleHeight / 20) * 6;

	option1Pos.x = center.x - (option1.length() / 2);
	option1Pos.y = (consoleData->consoleHeight / 20) * 10;

	option2Pos.x = center.x - (option2.length() / 2);
	option2Pos.y = (consoleData->consoleHeight / 20) * 13;

	option3Pos.x = center.x - (option3.length() / 2);
	option3Pos.y = (consoleData->consoleHeight / 20) * 16;

	exitPos.x = center.x - (exitStr.length() / 2);
	exitPos.y = (consoleData->consoleHeight / 20) * 19;
}

void MainMenu::RunMenu()
{
	mainMenu = true;

	do
	{
		ShowMenu();
		GetInput();

	} while (mainMenu);
}

void MainMenu::ShowMenu()
{
	system("cls");

	consoleData->DrawFrame(0);

	SetConsoleTextAttribute(consoleData->hwnd, 10);
	consoleData->PrintText(menuWelcome, menuWelcomePos);


	SetConsoleTextAttribute(consoleData->hwnd, 15);
	consoleData->PrintText(option1, option1Pos);
	consoleData->PrintText(option2, option2Pos);
	consoleData->PrintText(option3, option3Pos);

	SetConsoleTextAttribute(consoleData->hwnd, 8);
	consoleData->PrintText(exitStr, exitPos);
}

void MainMenu::GetInput()
{
	consoleData->userInput = _getch();

	switch (consoleData->userInput)
		{
		case '1':
		{
			LauncherSumaTest sumaTest(consoleData);
			sumaTest.Init();
			break;
		}
		case '2':
		{
			LauncherPregunta3 pregunta3(consoleData);
			pregunta3.Init();
			break;
		}
		case '3':
		{
			Definite definite(2);
			//definite.StartGame();
			break;
		}
		case 27:
		{
			mainMenu = false;
			break;
		}
	}
}
