#pragma once

#include <iostream>
#include <vector>

#include "Question.h"
#include "ConsoleHandler.h"

using namespace std;

class Pregunta3
{
private:

	ConsoleHandler* consoleData;
	vector<Question> pack;
	vector<int> positions;
	char correctOption;
	int totalAcerted;
	
	void ShowQuestion(Question question);
	void ReorderOptions();
	char GetInput();
	void CheckCorrectAnswer(char input, Question question);
	void ShowResults();


public:

	Pregunta3(ConsoleHandler* consoleData, vector<Question>& questionsPack);
	~Pregunta3();

	void PlayGame();
};

