#pragma once

#include <vector>

#include "Question.h"

using namespace std;

class QuestionLoader
{
private:

	vector<Question> sciencePack;
	vector<Question> phisicsPack;
	vector<Question> gamingPack;
	vector<Question> mechanicsPack;
	vector<Question> mathsPack;

public:

	QuestionLoader();
	~QuestionLoader();

	void Init();
	void PushPack(vector<Question>& emptyPack, Question dataPack[5]);
	void SavePacks();
	vector<Question> GetSciencePack();
	vector<Question> GetPhisicsPack();
	vector<Question> GetGamingPack();
	vector<Question> GetMechanicsPack();
	vector<Question> GetMathsPack();
};

