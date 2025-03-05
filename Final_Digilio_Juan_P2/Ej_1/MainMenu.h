#pragma once


#include "ConsoleHandler.h"


class MainMenu
{
private:

	bool mainMenu;


public:

	MainMenu();
	~MainMenu();

	void ShowMenu(ConsoleHandler* consoleData);
	void GetInput(ConsoleHandler* consoleData);

};

