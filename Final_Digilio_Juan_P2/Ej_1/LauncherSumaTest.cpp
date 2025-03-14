#include "LauncherSumaTest.h"



void LauncherSumaTest::Init()
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

	decimalPos.x = center.x - decimal.length() / 2 + 1;
	decimalPos.y = center.y + 2;

	valuesPos.x = center.x - values.length() / 2;
	valuesPos.y = center.y;

	values2Pos.x = center.x - values2.length() / 2;
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

	resultInputPos.x = center.x - resultInputStr.length() / 2;
	resultInputPos.y = center.y;

	wellDonePos.x = center.x - wellDone.length() / 2;
	wellDonePos.y = center.y;

	wrongAnswerPos.x = center.x - wrongAnswer.length() / 2;
	wrongAnswerPos.y = center.y;

	nextRoundPos.x = center.x - nextRound.length() / 2;
	nextRoundPos.y = center.y;

	totalAcertedPos.x = center.x - totalAcerted.length() / 2;
	totalAcertedPos.y = center.y;

	SetSumaTestDifficulty();
}

void LauncherSumaTest::SetSumaTestDifficulty()
{
	consoleData->ClearConsole();

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

	consoleData->ClearConsole();

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

LauncherSumaTest::LauncherSumaTest(ConsoleHandler* consoleData)
{
	this->consoleData = consoleData;
}

LauncherSumaTest::~LauncherSumaTest()
{
	delete sumaTest;
}
