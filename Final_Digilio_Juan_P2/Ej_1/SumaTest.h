#pragma once

#include <iostream>
#include <concepts>
#include <string>

#include "ConsoleHandler.h"


using namespace std;

template <typename T>
concept is_numeric = integral<T> || floating_point<T>;


template <is_numeric T>
class SumaTest
{
private:

	ConsoleHandler* consoleData;
	T minVal;
	T maxVal;
	T result;
	int totalRounds;
	int numbersPerRound;
	float delay;
	int totalWins;

	const float minDelay = 0.5f;
	const int minNumbersPerRound = 3;
	const int minRounds = 1;
	const int minRange = 10;
	

	void SetValues();
	void InstanceNewValue();
	T GetResult();
	void PLayGame();
	void GetUserResult();
	void ShowResults();

	T CheckValidInput(T min, string text, Vector2<int> position);
	void SetTwoDecimals(T& number);
	bool IsNumber(string textInput, T& type);
	int GetInteger(int min, string text, Vector2<int> position);
	float GetFloat(float min, string text, Vector2<int> position);
	int InMilliseconds(float delay);

public:

	SumaTest(ConsoleHandler* consoleData);
	~SumaTest();

	void Init();
};

#include "SumaTest.tpp"
