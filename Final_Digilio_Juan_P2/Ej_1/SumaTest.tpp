//#ifndef SUMATEST_TPP
//#define SUMATEST_TPP

//#include "SumaTest.h"

//#include <conio.h>
//#include <sstream>
//#include <cmath>
//
//#include "GameData.h"
//
//using namespace SumaTestData;


//template <typename T, typename>
//inline SumaTest<T>::SumaTest(ConsoleHandler* consoleData)
//{
//	totalWins = 0;
//	this->consoleData = consoleData;
//}
//
//template <typename T, typename>
//inline SumaTest<T>::~SumaTest()
//{
//}
//
//template <typename T, typename>
//void SumaTest<T>::Init()
//{
//	SetValues();
//	PLayGame();
//}
//
//template <typename T, typename>
//void SumaTest<T>::SetValues()
//{
//	consoleData->PrintText(values, valuesPos);
//	consoleData->PrintText(values2, values2Pos);
//	consoleData->PrintText(minText, minPos);
//	minVal = CheckValidInput(0, minText, minPos);
//
//	consoleData->PrintText(maxText, maxPos);
//	maxVal = CheckValidInput(minRange + minVal, maxText, maxPos);
//
//	consoleData->ClearConsole();
//
//	consoleData->PrintText(roundsQnty, roundsQntyPos);
//	totalRounds = GetInteger(minRounds, roundsQnty, roundsQntyPos);
//
//	consoleData->ClearConsole();
//
//	consoleData->PrintText(roundLength, roundLengthPos);
//	numbersPerRound = GetInteger(minNumbersPerRound, roundLength, roundLengthPos);
//
//	consoleData->ClearConsole();
//
//	consoleData->PrintText(delayText, delayPos);
//	delay = GetFloat(minDelay, delayText, delayPos);
//
//	consoleData->ClearConsole();
//}

//template <typename T, typename>
//inline void SumaTest<T>::InstanceNewValue()
//{
//	T temp;
//	bool isValid = false;
//
//	do
//	{
//		if (isDecimal)
//		{
//			temp = (minVal * 100) + (rand() % static_cast<int>((maxVal - minVal) * 100 + 1));
//			temp /= 100;
//		}
//		else
//		{
//			temp = minVal + rand() % static_cast<int>(maxVal - minVal + 1);
//		}
//
//		int randomNum = rand() % 2;
//
//		if (randomNum == 0)
//		{
//			temp *= -1;
//		}
//
//		if (result + temp >= 0)
//		{
//			isValid = true;
//		}
//	} while (!isValid);
//
//	result += temp;
//
//	Vector2<int> center = consoleData->GetConsoleCenterV2();
//	center.x -= to_string(temp).length() / 2;
//
//	consoleData->SetCursorPosition(center);
//	cout << temp;
//
//	Sleep(InMilliseconds(delay));
//}
//
//template <typename T, typename>
//inline T SumaTest<T>::GetResult()
//{
//	return result;
//}
//
//template <typename T, typename>
//void SumaTest<T>::PLayGame()
//{
//	for (int i = 0; i < totalRounds; i++)
//	{
//		result = 0;
//
//		for (int j = 0; j < numbersPerRound; j++)
//		{
//			consoleData->ClearConsole();
//
//			InstanceNewValue();
//		}
//
//		GetUserResult();
//
//		consoleData->ClearConsole();
//
//		if (i == totalRounds - 1)
//		{
//			ShowResults();
//		}
//		else
//		{
//			consoleData->PrintText(nextRound, nextRoundPos);
//			Sleep(1500);
//		}
//	}
//}
//
//template <typename T, typename>
//void SumaTest<T>::GetUserResult()
//{
//	consoleData->ClearConsole();
//
//	T userResult;
//
//	consoleData->PrintText(resultInputStr, resultInputPos);
//
//	userResult = CheckValidInput(0, resultInputStr, resultInputPos);
//
//	consoleData->ClearText(resultInputStr, resultInputPos);
//
//	if (userResult == result)
//	{
//		totalWins++;
//
//		consoleData->PrintText(wellDone, wellDonePos);
//	}
//	else
//	{
//		consoleData->PrintText(wrongAnswer, wrongAnswerPos);
//		cout << result;
//	}
//
//	Sleep(1500);
//}
//
//template <typename T, typename>
//void SumaTest<T>::ShowResults()
//{
//	consoleData->ClearConsole();
//
//	consoleData->PrintText(totalAcerted + to_string(totalWins), totalAcertedPos);
//
//	Sleep(3000);
//}
//
//template <typename T, typename>
//T SumaTest<T>::CheckValidInput(T min, string text, Vector2<int> position)
//{
//	string textInput;
//	bool validValue = false;
//	T temp;
//
//	do
//	{
//		cin >> textInput;
//
//		if (IsNumber(textInput, temp) && temp >= min)
//		{
//			if (textInput.find('.') != string::npos)
//			{
//				if (isDecimal)
//				{
//					SetTwoDecimals(temp);
//					validValue = true;
//				}
//			}
//			else
//			{
//				validValue = true;
//			}
//		}
//
//		consoleData->ClearInput(text, position, textInput);
//
//	} while (!validValue);
//
//	return temp;
//}
//
//template <typename T, typename>
//void SumaTest<T>::SetTwoDecimals(T& number)
//{
//	float temp = number;
//	number = round(temp * 100.0) / 100.0;
//}
//
//template <typename T, typename>
//bool SumaTest<T>::IsNumber(string textInput, T& type)
//{
//	istringstream iss(textInput);
//
//	if (iss >> type && iss.eof())
//	{
//		return true;
//	}
//}
//
//template <typename T, typename>
//int SumaTest<T>::GetInteger(int min, string text, Vector2<int> position)
//{
//	string textInput;
//	bool validValue = false;
//	int temp;
//
//	do
//	{
//		cin >> textInput;
//
//		istringstream iss(textInput);
//
//		if (iss >> temp && iss.eof() && temp >= min )
//		{
//			validValue = true;
//		}
//
//		consoleData->ClearInput(text, position, textInput);
//	} while (!validValue);
//
//	return temp;
//}
//
//template <typename T, typename>
//float SumaTest<T>::GetFloat(float min, string text, Vector2<int> position)
//{
//	string textInput;
//	bool validValue = false;
//	float temp;
//
//	do
//	{
//		cin >> textInput;
//
//		istringstream iss(textInput);
//
//		if (iss >> temp && iss.eof() && temp >= min)
//		{
//			validValue = true;
//		}
//
//		consoleData->ClearInput(text, position, textInput);
//	} while (!validValue);
//
//	return temp;
//}
//
//template <typename T, typename>
//int SumaTest<T>::InMilliseconds(float delay)
//{
//	return static_cast<int>(round(delay * 1000));
//}
//
//
//#endif