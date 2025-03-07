#ifndef SUMATEST_TPP
#define SUMATEST_TPP

#include "SumaTest.h"

#include <conio.h>
#include <sstream>
#include <cmath>

#include "GameData.h"
//#include "Vector2.h"

using namespace SumaTestData;

template<is_numeric T>
inline SumaTest<T>::SumaTest(ConsoleHandler* consoleData)
{
	isDecimal = false;
	this->consoleData = consoleData;
}

template<is_numeric T>
inline SumaTest<T>::~SumaTest()
{
}

template<is_numeric T>
void SumaTest<T>::Init()
{
	SetValues();
}

template<is_numeric T>
void SumaTest<T>::ShowDifficultyMenu()
{


}

template<is_numeric T>
void SumaTest<T>::SetValues()
{
	consoleData->PrintText(values, valuesPos);
	consoleData->PrintText(values2, values2Pos);
	consoleData->PrintText(minText, minPos);
	minVal = CheckValidInput(0, minText, minPos);

	consoleData->PrintText(maxText, maxPos);
	maxVal = CheckValidInput(minVal + 10, maxText, maxPos);

	system("cls");

	consoleData->DrawFrame(0);

	consoleData->PrintText(roundsQnty, roundsQntyPos);
	totalRounds = GetInteger(minRounds, roundsQnty, roundsQntyPos);

	consoleData->ClearText(roundsQnty, roundsQntyPos);

	consoleData->PrintText(roundLength, roundLengthPos);
	numbersPerRound = GetInteger(minNumbersPerRound, roundLength, roundLengthPos);

	consoleData->ClearText(roundLength, roundLengthPos);

	consoleData->PrintText(delayText, delayPos);
	delay = GetFloat(minDelay, delayText, delayPos);

	system("cls");
}

template<is_numeric T>
inline void SumaTest<T>::InstanceNewValue()
{
	if (isDecimal)
	{
		float temp = (minVal * 100) + (rand() % ((maxVal - minVal) * 100 + 1));
		temp /= 100;
	}
	else
	{
		int temp = minVal + rand() % (maxVal - minVal + 1);
	}
}

template<is_numeric T>
inline T SumaTest<T>::GetResult()
{
	return result;
}

template<is_numeric T>
T SumaTest<T>::CheckValidInput(T min, string text, Vector2<int> position)
{
	string textInput;
	bool validValue = false;
	T temp;

	do
	{
		cin >> textInput;

		if (IsType(textInput, temp) && temp > min)
		{
			if (textInput.find('.') != string::npos)
			{
				if (isDecimal)
				{
					SetTwoDecimals(temp);
					validValue = true;
				}
			}
			else
			{
				validValue = true;
			}
		}

		consoleData->ClearInput(text, position, textInput);

	} while (!validValue);

	return temp;
}

template<is_numeric T>
void SumaTest<T>::SetTwoDecimals(T& number)
{
	float temp = number;
	number = round(temp * 100.0) / 100.0;
}

template<is_numeric T>
bool SumaTest<T>::IsType(string textInput, T& type)
{
	istringstream iss(textInput);

	if (iss >> type && iss.eof())
	{
		return true;
	}
}

template<is_numeric T>
int SumaTest<T>::GetInteger(int min, string text, Vector2<int> position)
{
	string textInput;
	bool validValue = false;
	int temp;

	do
	{
		cin >> textInput;

		if (IsType(textInput, temp) && temp > min)
		{
			validValue = true;
		}

		consoleData->ClearInput(text, position, textInput);
	} while (!validValue);

	return temp;
}

template<is_numeric T>
float SumaTest<T>::GetFloat(float min, string text, Vector2<int> position)
{
	string textInput;
	bool validValue = false;
	float temp;

	do
	{
		cin >> textInput;

		if (IsType(textInput, temp) && temp > min)
		{
			validValue = true;
		}

		consoleData->ClearInput(text, position, textInput);
	} while (!validValue);

	return temp;
}


#endif