#ifndef SUMATEST_TPP
#define SUMATEST_TPP

#include "SumaTest.h"

#include <conio.h>
#include <sstream>
#include <cmath>

//#include "GameData.h"
//#include "Vector2.h"


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

	minVal = CheckValidInput(0, min, minPos);

	consoleData->PrintText(maxText, maxPos);

	maxVal = CheckValidInput(minVal + 10, max, maxPos);
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

		istringstream iss(textInput);

		if (iss >> temp && iss.eof())
		{
			if (temp > min)
			{
				if (entrada.find('.') != string::npos) 
				{
					if (isDecimal)
					{
						validValue = true;
						SetTwoDecimals(temp);
					}		
				}
				else 
				{
					validValue = true;
				}		
			}
			else
			{
				consoleData->SetCursorAfter(position, text);
				consoleData->ClearText(textInput);
			}
		}
		else
		{
			consoleData->SetCursorAfter(position, text);
			consoleData->ClearText(textInput);
		}

	} while (!validValue);

	return temp;
}

template<is_numeric T>
void SumaTest<T>::SetTwoDecimals(T& number)
{
	number = round(number * 100.0) / 100.0;
}


#endif