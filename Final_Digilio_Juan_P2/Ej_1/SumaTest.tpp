#ifndef SUMATEST_TPP
#define SUMATEST_TPP

#include "SumaTest.h"

#include <conio.h>
#include <sstream>
#include <cmath>

#include "GameData.h"

using namespace SumaTestData;

template<is_numeric T>
inline SumaTest<T>::SumaTest(ConsoleHandler* consoleData)
{
	isDecimal = false;
	totalWins = 0;
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
	T temp;
	bool isValid = false;

	do
	{
		if (isDecimal)
		{
			temp = (minVal * 100) + (rand() % ((maxVal - minVal) * 100 + 1));
			temp /= 100;
		}
		else
		{
			temp = minVal + rand() % (maxVal - minVal + 1);
		}

		int randomNum = rand() % 2;

		if (randomNum == 0)
		{
			temp *= -1;
		}

		if (result + temp >= 0)
		{
			isValid = true;
		}
	} while (!isValid);
	
	result += temp;

	Vector2<int> center = consoleData->GetConsoleCenterV2();
	center.x -= static_cast<string>(temp).length() / 2;

	consoleData->SetCursorPosition(center);
	cout << temp;

	Sleep(InMilliseconds(delay));
}

template<is_numeric T>
inline T SumaTest<T>::GetResult()
{
	return result;
}

template<is_numeric T>
void SumaTest<T>::PLayGame()
{
	for (int i = 0; i < totalRounds; i++)
	{
		result = 0;

		for (int j = 0; j < numbersPerRound; j++)
		{
			system("cls");
			consoleData->DrawFrame(0);

			InstanceNewValue();
		}
		
		GetUserResult();

		system("cls");
		consoleData->DrawFrame(0);

		if (i == totalRounds - 1)
		{
			consoleData->PrintText(totalAcerted + to_string(totalWins), totalAcertedPos);
			Sleep(1500);
		}
		else
		{
			consoleData->PrintText(nextRound, nextRoundPos);
			Sleep(1500);
		}

		consoleData->PrintText(nextRound, nextRoundPos);
		Sleep(1500);
	}
}

template<is_numeric T>
void SumaTest<T>::GetUserResult()
{
	system("cls");
	consoleData->DrawFrame(0);

	T userResult;

	consoleData->PrintText(resultInputStr, resultInputPos);

	userResult = CheckValidInput(0, resultInputStr, resultInputPos);

	consoleData->ClearText(resultInputStr, resultInputPos);

	if (userResult == result)
	{
		totalWins++;

		consoleData->PrintText(wellDone, wellDonePos);
	}
	else
	{
		consoleData->PrintText(wrongAnswer, wrongAnswerPos);
		cout << result;
	}

	Sleep(1500);
}

template<is_numeric T>
void SumaTest<T>::ShowResults()
{
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

template<is_numeric T>
int SumaTest<T>::InMilliseconds(float delay)
{
	return delay * 1000;
}


#endif