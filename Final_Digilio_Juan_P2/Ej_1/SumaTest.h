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

	T result;
	bool hardMode;
	ConsoleHandler* consoleData;

	string welcome;
	string type;
	string integer;
	string decimal;
	string values;
	string min;
	string max;

	Vector2<int> welcomePos;
	Vector2<int> typePos;
	Vector2<int> integerPos;
	Vector2<int> decimalPos;
	Vector2<int> valuesPos;
	Vector2<int> minPos;
	Vector2<int> maxPos;

	void Init();
	void ShowDifficultyMenu();
	void SetDifficulty();
	void InstanceNewValue();
	T GetResult();

public:

	SumaTest(ConsoleHandler* consoleData);
	~SumaTest();

};

//#include "SumaTest.tpp"
