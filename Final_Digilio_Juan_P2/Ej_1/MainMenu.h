#pragma once


#include "ConsoleHandler.h"

class MainMenu
{
private:

	ConsoleHandler* consoleData;
	bool mainMenu;

	

	void ShowMenu();
	void GetInput();

public:

	MainMenu(ConsoleHandler* consoleData);
	~MainMenu();

	void Init();
};

