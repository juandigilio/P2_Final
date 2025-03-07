#include "MainMenu.h"


void main()
{
	ConsoleHandler consoleData;
	MainMenu mainMenu(&consoleData);

	mainMenu.RunMenu();
}