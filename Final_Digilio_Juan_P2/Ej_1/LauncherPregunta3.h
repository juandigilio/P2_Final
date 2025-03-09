#pragma once

#include<vector>

#include "ConsoleHandler.h"
#include "Question.h"


using namespace std;

class LauncherPregunta3
{
private:

	ConsoleHandler* consoleData;
	vector<Question> pack;


public:

	LauncherPregunta3(ConsoleHandler* consoleData);
	~LauncherPregunta3();

	void Init();
	void ShowThemes();
	void SelectTheme();
};

