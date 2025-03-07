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
	

	void ShowDifficultyMenu();
	void SetValues();
	void InstanceNewValue();
	T GetResult();
	T CheckValidInput(T min, string text, Vector2<int> position);
	void SetTwoDecimals(T& number);
	bool IsType(string textInput, T& type);
	int GetInteger(int min);

public:

	SumaTest(ConsoleHandler* consoleData);
	~SumaTest();

	void Init();
};

#include "SumaTest.tpp"
