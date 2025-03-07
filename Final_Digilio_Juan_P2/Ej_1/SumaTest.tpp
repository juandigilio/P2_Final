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

	Init();
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

}

template<is_numeric T>
inline void SumaTest<T>::InstanceNewValue()
{

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
int SumaTest<T>::GetInteger(int min)
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
	} while (!validValue);

	return temp;
}


#endif