#pragma once

#include "ConsoleHandler.h"
#include "SumaTest.h"


class LauncherSumaTest
{
private:

	ConsoleHandler* consoleData;
	void* sumaTest;

	void SetSumaTestDifficulty();

public:
	LauncherSumaTest(ConsoleHandler* consoleData);
	~LauncherSumaTest();

	void Init();
};

