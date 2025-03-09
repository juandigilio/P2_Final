#include "LauncherPregunta3.h"

#include <conio.h>

#include "GameData.h"
#include "SaveManager.h"
#include "Pregunta3.h"

using namespace Pregunta3Data;

LauncherPregunta3::LauncherPregunta3(ConsoleHandler* consoleData)
{
	this->consoleData = consoleData;
}

LauncherPregunta3::~LauncherPregunta3()
{
}

void LauncherPregunta3::Init()
{
	consoleData->SetConsoleSize(50, 25);

	Vector2<int> center = consoleData->GetConsoleCenterV2();

	selectThemePos.x = center.x - (selectTheme.length() / 2);
	selectThemePos.y = (consoleData->consoleHeight / 20) * 6;

	sciencePos.x = center.x - (scienceText.length() / 2);
	sciencePos.y = (consoleData->consoleHeight / 20) * 10;

	phisicsPos.x = center.x - (phisicsText.length() / 2);
	phisicsPos.y = (consoleData->consoleHeight / 20) * 13;

	gamingPos.x = center.x - (gamingText.length() / 2);
	gamingPos.y = (consoleData->consoleHeight / 20) * 16;

	mechanicsPos.x = center.x - (mechanicsText.length() / 2);
	mechanicsPos.y = (consoleData->consoleHeight / 20) * 19;

	mathsPos.x = center.x - (mathsText.length() / 2);
	mathsPos.y = (consoleData->consoleHeight / 20) * 22;

	questionPos.x = 1;
	questionPos.y = 1;

	Vector2<int> temp;;

	temp.x = 1;
	temp.y = (consoleData->consoleHeight / 20) * 4;
	optionsPos.push_back(temp);

	temp.y = (consoleData->consoleHeight / 20) * 7;
	optionsPos.push_back(temp);

	temp.y = (consoleData->consoleHeight / 20) * 10;
	optionsPos.push_back(temp);

	temp.y = (consoleData->consoleHeight / 20) * 13;
	optionsPos.push_back(temp);

	temp.y = (consoleData->consoleHeight / 20) * 16;
	optionsPos.push_back(temp);

	exitPos.x = 1;
	exitPos.y = (consoleData->consoleHeight / 20) * 19;

	totalAcertedQntyPos.x = center.x - (totalAcertedQnty.length() / 2);
	totalAcertedQntyPos.y = consoleData->consoleHeight / 2;

	wellDonePos.x = center.x - (wellDone.length() / 2);
	wellDonePos.y = consoleData->consoleHeight / 2;

	wrongAnswerPos.x = center.x - (wrongAnswer.length() / 2);
	wrongAnswerPos.y = consoleData->consoleHeight / 2;

	nextAnswerPos.x = center.x - (nextAnswer.length() / 2);
	nextAnswerPos.y = consoleData->consoleHeight / 2;

	SelectTheme();
}

void LauncherPregunta3::ShowThemes()
{
	consoleData->ClearConsole();

	consoleData->PrintText(selectTheme, selectThemePos);
	consoleData->PrintText(scienceText, sciencePos);
	consoleData->PrintText(phisicsText, phisicsPos);
	consoleData->PrintText(gamingText, gamingPos);
	consoleData->PrintText(mechanicsText, mechanicsPos);
	consoleData->PrintText(mathsText, mathsPos);
}

void LauncherPregunta3::SelectTheme()
{
	ShowThemes();

	char input;

	do
	{
		input = _getch();

	} while (input != '1' && input != '2' && input != '3' && input != '4' && input != '5' && input != 27);

	switch (input)
	{
		case '1':
		{
			SaveManager::LoadQuestionsPack(pack, "../Data/SciencePack.dat");
			break;
		}
		case '2':
		{
			SaveManager::LoadQuestionsPack(pack, "../Data/PhisicsPack.dat");
			break;
		}
		case '3':
		{
			SaveManager::LoadQuestionsPack(pack, "../Data/GamingPack.dat");
			break;
		}
		case '4':
		{
			SaveManager::LoadQuestionsPack(pack, "../Data/MechanicsPack.dat");
			break;
		}
		case '5':
		{
			SaveManager::LoadQuestionsPack(pack, "../Data/MathsPack.dat");
			break;
		}
		case 27:
		{
			break;
		}
	}

	if (input != 27)
	{
		Pregunta3 pregunta3(consoleData, pack);
		pregunta3.PlayGame();
	}

	consoleData->ClearConsole();
}
