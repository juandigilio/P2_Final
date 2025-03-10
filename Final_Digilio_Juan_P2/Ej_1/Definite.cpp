#include "Definite.h"

Definite::Definite(int rounds)
{
    this->rounds = rounds;
}

//void Definite::FetchWordAndDefinition(WordData& wordData)
//{
    /*http_request wordRequest(methods::GET);
    http_response wordResponse = wordClient.request(wordRequest).get();

    if (wordResponse.status_code() == 200)
    {
        auto jsonResponse = wordResponse.extract_json().get();
        wordData.word = to_utf8string(jsonResponse.as_array()[0].as_string());
    }
    else
    {
        CheckErrorCode(wordResponse);
    }

    uri_builder defUri(to_string_t(wordData.word));

    http_response definitionResponse = definitionClient.request(methods::GET, defUri.to_string()).get();

    if (definitionResponse.status_code() == 200)
    {
        auto jsonResponse = definitionResponse.extract_json().get();
        wordData.definition = to_utf8string(jsonResponse.as_array()[0][to_string_t("meanings")][0][to_string_t("definitions")][0][to_string_t("definition")].as_string());
    }
    else
    {
        CheckErrorCode(wordResponse);
    }*/
//}

//void Definite::ShowLoadingAnimation()
//{
   /* const char animation[] = "|/-\\";
    int i = 0;

    while (!loadFutures.empty())
    {
        cout << "\rLoading " << animation[i++ % 4] << flush;

        this_thread::sleep_for(chrono::milliseconds(200));
    }

    cout << "\r" << string(10, ' ') << "\r";*/
//}

//void Definite::StartGame()
//{
//    for (int i = 0; i < rounds; i++)
//    {
//        WordData newWord;
//
//        loadFutures.push_back(async(launch::async, [this, &newWord] { FetchWordAndDefinition(newWord); }));
//
//        words.push_back(newWord);
//    }
//
//    ShowLoadingAnimation();
//
//    for (const auto& wordData : words)
//    {
//        cout << "Definition: " << wordData.definition << endl;
//        cout << "Your answer: ";
//
//        string answer;
//
//        getline(cin, answer);
//
//        if (answer == wordData.word)
//        {
//            cout << "Correct!" << endl;
//            score++;
//        }
//        else
//        {
//            cout << "Incorrect! The correct word was: " << wordData.word << endl;
//        }
//    }
//
//    ShowResults();
//}
//
//void Definite::ShowResults()
//{
//    cout << "Game Finished! You scored " << score << " out of " << rounds << "!" << endl;
//}
//
//void Definite::CheckErrorCode(http_response wordResponse)
//{
//    if (wordResponse.status_code() == 400)
//    {
//        cout << "Bad request" << endl;
//    }
//    else if (wordResponse.status_code() == 404)
//    {
//        cout << "Word not found" << endl;
//    }
//    else if (wordResponse.status_code() == 500)
//    {
//        cout << "Internal server error" << endl;
//    }
//
//}
