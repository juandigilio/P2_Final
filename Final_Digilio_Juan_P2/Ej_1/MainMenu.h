#pragma once


#include "ConsoleHandler.h"
#include "SumaTest.h"

class MainMenu
{
private:

	ConsoleHandler* consoleData;
	bool mainMenu;

	void* sumaTest;

	void ShowMenu();
	void GetInput();
	void InitSumaTest();
	void SetSumaTestDifficulty();

public:

	MainMenu(ConsoleHandler* consoleData);
	~MainMenu();

	void Init();
};

