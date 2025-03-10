#include "Definite.h"

Definite::Definite(ConsoleHandler* consoleData, int rounds)
{
    this->rounds = rounds;
	this->consoleData = consoleData;
	allTasksCompleted = false;
}

void Definite::FetchWordAndDefinition(WordData& wordData)
{
    try
    {
        http_request wordRequest(methods::GET);
        http_response wordResponse = wordClient.request(wordRequest).get();


        if (wordResponse.status_code() == 200)
        {
            auto jsonResponse = wordResponse.extract_json().get();

            if (jsonResponse.as_array().size() != 0)
            {
                wordData.word = to_utf8string(jsonResponse.as_array()[0].as_string());
            }
            else
            {
                cerr << "API response is empty!" << endl;
                return;
            }
        }
        else
        {
            CheckErrorCode(wordResponse);
            return;
        }

        uri_builder defUri(to_string_t(wordData.word));
        http_response definitionResponse = definitionClient.request(methods::GET, defUri.to_string()).get();

        if (definitionResponse.status_code() == 200)
        {
            auto jsonResponse = definitionResponse.extract_json().get();

            if (jsonResponse.as_array().size() > 0 &&
                jsonResponse.as_array()[0].has_field(to_string_t("meanings")) &&
                jsonResponse.as_array()[0][to_string_t("meanings")].as_array().size() > 0 &&
                jsonResponse.as_array()[0][to_string_t("meanings")][0].has_field(to_string_t("definitions")) &&
                jsonResponse.as_array()[0][to_string_t("meanings")][0][to_string_t("definitions")].as_array().size() > 0 &&
                jsonResponse.as_array()[0][to_string_t("meanings")][0][to_string_t("definitions")][0].has_field(to_string_t("definition")))
            {
                wordData.definition = to_utf8string(jsonResponse.as_array()[0][to_string_t("meanings")][0][to_string_t("definitions")][0][to_string_t("definition")].as_string());
            }
            else
            {
                cerr << "Definition not found in API response!" << endl;
            }
        }
        else
        {
            CheckErrorCode(definitionResponse);
        }
    }
    catch (const std::exception& e)
    {
        cerr << "Exception in FetchWordAndDefinition : " << e.what() << endl;
    }
}

void Definite::ShowLoadingAnimation()
{
    const char animation[] = "|/-\\";
    int i = 0;

    consoleData->ClearConsole();

    while (!allTasksCompleted)
    {
        cout << "\rLoading " << animation[i++ % 4] << flush;
        this_thread::sleep_for(chrono::milliseconds(200));
    }

    cout << "\r" << string(10, ' ') << "\r";
}

void Definite::StartGame()
{
    words.reserve(rounds);

    for (int i = 0; i < rounds; i++)
    {
        words.emplace_back(); 
        WordData* newWord = &words.back();

        loadFutures.push_back(async(launch::async, [this, newWord] 
        {
            try 
            {
                FetchWordAndDefinition(*newWord);
            }
            catch (const std::exception& e) 
            {
                cerr << "Error en FetchWordAndDefinition: " << e.what() << endl;
            }
        }));
    }

    thread loadingThread(&Definite::ShowLoadingAnimation, this);

    for (auto& future : loadFutures)
    {
        if (future.valid())
        {
            future.get();
        }
    }
    loadFutures.clear();

    allTasksCompleted = true;
    loadingThread.join();

    for (const auto& wordData : words)
    {
        cout << "Definition: " << wordData.definition << endl;
        cout << "Your answer: ";

        string answer;
        getline(cin, answer);

        if (answer == wordData.word)
        {
            cout << "Correct!" << endl;
            score++;
        }
        else
        {
            cout << "Incorrect! The correct word was: " << wordData.word << endl;
        }
    }

    ShowResults();
}

void Definite::ShowResults()
{
    cout << "Game Finished! You scored " << score << " out of " << rounds << "!" << endl;
}

void Definite::CheckErrorCode(http_response wordResponse)
{
    if (wordResponse.status_code() == 400)
    {
        cout << "400 - Bad request" << endl;
    }
    else if (wordResponse.status_code() == 404)
    {
        cout << "404 - Not found" << endl;
    }
    else if (wordResponse.status_code() == 500)
    {
        cout << "500 - Internal server error" << endl;
    }

}
