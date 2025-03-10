#include "MainMenu.h"
#include "ConsoleHandler.h"
//#include "QuestionLoader.h"


using namespace std;

void main()
{
	ConsoleHandler consoleData;
	MainMenu mainMenu(&consoleData);
	consoleData.SetConsoleSize(80, 40);

	mainMenu.RunMenu();
}