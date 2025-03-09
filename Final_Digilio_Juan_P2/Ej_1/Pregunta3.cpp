#include "Pregunta3.h"

#include <random> 
#include <algorithm>
#include <string>
#include <conio.h>

#include "GameData.h"

using namespace Pregunta3Data;


Pregunta3::Pregunta3(ConsoleHandler* consoleData, vector<Question>& questionsPack)
{
	this->consoleData = consoleData;

	pack.clear();

	for (auto question : questionsPack)
	{
		pack.push_back(question);
	}

	totalAcerted = 0;
}

Pregunta3::~Pregunta3()
{
}

void Pregunta3::PlayGame()
{
	char input;

	for (int i = 0; i < pack.size(); i++)
	{
		ShowQuestion(pack[i]);

		input = GetInput();

		if (input == 27)
		{
			break;
		}
		else
		{
			CheckCorrectAnswer(input, pack[i]);
		}

		if (i != pack.size() - 1)
		{
			consoleData->ClearConsole();
			consoleData->PrintText(nextAnswer, nextAnswerPos);

			Sleep(1000);
		}	
	}

	ShowResults();
}

void Pregunta3::ShowQuestion(Question question)
{
	consoleData->ClearConsole();

	ReorderOptions();

	consoleData->PrintText(question.qustion, questionPos);

	consoleData->PrintText(to_string(positions[0]) + "-" + question.correctOption, optionsPos[positions[0] - 1]);
	consoleData->PrintText(to_string(positions[1]) + "-" + question.option1, optionsPos[positions[1] - 1]);
	consoleData->PrintText(to_string(positions[2]) + "-" + question.option2, optionsPos[positions[2] - 1]);
	consoleData->PrintText(to_string(positions[3]) + "-" + question.option3, optionsPos[positions[3] - 1]);
	consoleData->PrintText(to_string(positions[4]) + "-" + question.option4, optionsPos[positions[4] - 1]);

	consoleData->PrintText(exitText, exitPos);


	correctOption = (char)positions[0];
}

void Pregunta3::ReorderOptions()
{
	positions = { 1, 2, 3, 4, 5 };

	random_device rd;
	mt19937 g(rd());

	shuffle(positions.begin(), positions.end(), g);
}

char Pregunta3::GetInput()
{
	char input;

	do
	{
		input = _getch();

	} while (input != 27 && input != '1' && input != '2' && input != '3' && input != '4' && input != '5');

	return input;
}

void Pregunta3::CheckCorrectAnswer(char input, Question question)
{
	consoleData->ClearConsole();

	Vector2<int> answerPos;
	answerPos.x = (consoleData->GetConsoleCenterV2().x / 2) - (question.correctOption.length() / 2);
	answerPos.y = wrongAnswerPos.y + 2;

	if (input - '0' == correctOption)
	{
		consoleData->PrintText(wellDone, wellDonePos);
		totalAcerted++;
	}
	else
	{
		consoleData->PrintText(wrongAnswer, wrongAnswerPos);
		consoleData->PrintText(question.correctOption, answerPos);
	}

	Sleep(2500);
}

void Pregunta3::ShowResults()
{
	consoleData->ClearConsole();
	consoleData->PrintText(totalAcertedQnty + to_string(totalAcerted), totalAcertedQntyPos);

	Sleep(3000);
}


