#pragma once

#include <iostream>
#include <vector>
#include <future>
#include <cpprest/http_client.h>
#include <cpprest/json.h>
#include <chrono>
#include <thread>
#include <mutex>

#include "ConsoleHandler.h"

using namespace std;
using namespace web;
using namespace web::http;
using namespace web::http::client;
using namespace utility::conversions;

const string WORD_API_URL = "https://random-word-api.herokuapp.com/word";
const string DEFINITION_API_URL = "https://api.dictionaryapi.dev/api/v2/entries/en/";

struct WordData
{
    string word;
    string definition;
};

class Definite
{
private:

	ConsoleHandler* consoleData;
    vector<WordData> words;
    vector<future<void>> loadFutures;
    mutex loadMutex;
    int score = 0;
    int rounds;
    http_client wordClient = http_client(to_string_t(WORD_API_URL));
    http_client definitionClient = http_client(to_string_t(DEFINITION_API_URL));
    bool allTasksCompleted;


public:

    Definite(ConsoleHandler* consoleData, int rounds);
    ~Definite();

    void FetchWordAndDefinition(WordData& wordData);
    void GetWord(WordData& wordData);
	void GetDefinition(WordData& wordData);
    void StartGame();
    void ShowLoadingAnimation();
    void ShowResults();
    void CheckErrorCode(http_response wordResponse);
};

