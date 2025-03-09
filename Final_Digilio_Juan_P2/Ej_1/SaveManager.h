#pragma once

#include <vector>
#include <iostream>

#include "Question.h"

using namespace std;


static class SaveManager
{
public:

	//SaveManager();
	//~SaveManager();

	static void SaveQuestionsPack(vector<Question>& questionsPack, const string& filePath);
	static void LoadQuestionsPack(vector<Question>& questionsPack, const string& filePath);
};

