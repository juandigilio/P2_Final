#include "MainMenu.h"
#include "ConsoleHandler.h"
#include "QuestionLoader.h"

void main()
{
	ConsoleHandler consoleData;
	MainMenu mainMenu(&consoleData);

	mainMenu.RunMenu();

	//QuestionLoader questionLoader;
	//questionLoader.Init();

}