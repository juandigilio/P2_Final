#pragma once

#include <iostream>
#include <vector>

#include "Vector2.h"

using namespace std;

namespace SumaTestData
{
	extern bool isDecimal;
	extern string welcome;
	extern string type;
	extern string integer;
	extern string decimal;
	extern string values;
	extern string values2;
	extern string minText;
	extern string maxText;
	extern string roundsQnty;
	extern string roundLength;
	extern string delayText;
	extern string resultInputStr;
	extern string wellDone;
	extern string wrongAnswer;
	extern string nextRound;
	extern string totalAcerted;

	extern Vector2<int> welcomePos;
	extern Vector2<int> typePos;
	extern Vector2<int> integerPos;
	extern Vector2<int> decimalPos;
	extern Vector2<int> valuesPos;
	extern Vector2<int> values2Pos;
	extern Vector2<int> minPos;
	extern Vector2<int> maxPos;
	extern Vector2<int> roundsQntyPos;
	extern Vector2<int> roundLengthPos;
	extern Vector2<int> delayPos;
	extern Vector2<int> resultInputPos;
	extern Vector2<int> wellDonePos;
	extern Vector2<int> wrongAnswerPos;
	extern Vector2<int> nextRoundPos;
	extern Vector2<int> totalAcertedPos;
}

namespace MainMenuData
{
	extern string menuWelcome;
	extern string option1;
	extern string option2;
	extern string option3;
	extern string exitStr;
	extern string clean;
	extern Vector2<int> menuWelcomePos;
	extern Vector2<int> option1Pos;
	extern Vector2<int> option2Pos;
	extern Vector2<int> option3Pos;
	extern Vector2<int> exitPos;
}

namespace Pregunta3Data
{
	extern string selectTheme;
	extern string scienceText;
	extern string phisicsText;
	extern string gamingText;
	extern string mechanicsText;
	extern string mathsText;

	extern string exitText;
	extern string wellDone;
	extern string wrongAnswer;
	extern string nextAnswer;

	extern string totalAcertedQnty;

	extern Vector2<int> selectThemePos;
	extern Vector2<int> sciencePos;
	extern Vector2<int> phisicsPos;
	extern Vector2<int> gamingPos;
	extern Vector2<int> mechanicsPos;
	extern Vector2<int> mathsPos;

	extern Vector2<int> questionPos;
	extern vector<Vector2<int>> optionsPos;
	extern Vector2<int> exitPos;

	extern Vector2<int> wellDonePos;
	extern Vector2<int> wrongAnswerPos;
	extern Vector2<int> nextAnswerPos;

	extern Vector2<int> totalAcertedQntyPos;
}