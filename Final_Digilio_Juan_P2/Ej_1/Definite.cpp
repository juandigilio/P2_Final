#include "Definite.h"

Definite::Definite(ConsoleHandler* consoleData, int rounds)
{
    this->rounds = rounds;
	this->consoleData = consoleData;
	allTasksCompleted = false;
	errorsQnty = 0;
}

Definite::~Definite()
{
}

void Definite::FetchWordAndDefinition(WordData& wordData)
{
    try
    {
        do
        {
            GetWord(wordData);

            GetDefinition(wordData);

        } while (wordData.word.empty() || wordData.definition.empty());
		
    }
    catch (const exception& e)
    {
        cerr << "Exception in FetchWordAndDefinition : " << e.what() << endl;
    }

	errorsQnty = 0;
}

void Definite::GetWord(WordData& wordData)
{
    bool isValid;

    do
    {
        isValid = true;

        http_request wordRequest(methods::GET);
        http_response wordResponse = wordClient.request(wordRequest).get();

        if (wordResponse.status_code() == 200)
        {
            auto jsonResponse = wordResponse.extract_json().get();

            if (jsonResponse.as_array().size() != 0)
            {
                wordData.word = to_utf8string(jsonResponse.as_array()[0].as_string());

				for (int i = 0; i < wordData.word.length(); i++)
				{
					if (wordData.word[i] == ' ')
					{
						isValid = false;
						break;
					}
				}
            }
            else
            {
                cerr << "API response is empty!" << endl;
                Sleep(2000);
                return;
            }
        }
        else
        {
            CheckErrorCode(wordResponse, "Word error ");
            Sleep(2000);
            return;
        }

	} while (!isValid);
}

void Definite::GetDefinition(WordData& wordData)
{
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
        CheckErrorCode(definitionResponse, "Definition error ");
    }
}

void Definite::LoadDefinitions()
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
}

void Definite::ShowLoadingAnimation()
{
    const char animation[] = "|/-\\";
    int i = 0;

	system("cls");

    while (!allTasksCompleted)
    {
		consoleData->PrintCenteredText("Loading ", 4, 0);
        cout << animation[i++ % 4] << flush;
        this_thread::sleep_for(chrono::milliseconds(200));
    }

    cout << "\r" << string(10, ' ') << "\r";
}

void Definite::GameLoop()
{
    for (const auto& wordData : words)
    {
        ShowDefinition(wordData.definition);
        ShowWord(wordData.word);

        CheckCorrectAnswer(wordData.word);
    }
}

void Definite::ShowDefinition(string definition)
{
    system("cls");

    consoleData->SetCursorPosition(0, 0);
    cout << "Definition: " << definition << endl;\
  
    consoleData->PrintCenteredText("Your answer: ");
}

void Definite::ShowWord(string word)
{
    consoleData->PrintText("Palabra: " + word, Vector2(0, 4));
}

void Definite::StartGame()
{
    words.reserve(rounds);

    LoadDefinitions();

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

	GameLoop();

    ShowResults();
}

void Definite::ShowResults()
{
	system("cls");

	consoleData->PrintCenteredText("Game Finished!");
	consoleData->PrintCenteredText("You scored " + to_string(score) + " out of " + to_string(rounds) + "!", 0, 1);

	Sleep(2000);
}

void Definite::CheckErrorCode(http_response wordResponse, string type)
{
	system("cls");

    if (wordResponse.status_code() == 400)
    {
		consoleData->PrintCenteredText(type + "400 - Bad request", 0, errorsQnty + 1);
    }
    else if (wordResponse.status_code() == 404)
    {
        consoleData->PrintCenteredText(type + "404 - Not found", 0, errorsQnty + 1);
    }
    else if (wordResponse.status_code() == 500)
    {
        consoleData->PrintCenteredText(type + "500 - Internal server error", 0, errorsQnty + 1);
    }

	errorsQnty++;
}

void Definite::CheckCorrectAnswer(string word)
{
    string answer;

	Vector2<int> center = consoleData->GetConsoleCenterV2();
	center.x -= 4;
	center.y += 2;

    consoleData->SetCursorPosition(center);

    getline(cin, answer);

    system("cls");

    if (answer == word)
    {
        consoleData->PrintCenteredText("Correct!");
        score++;
    }
    else
    {
        consoleData->PrintCenteredText("Incorrect! The correct word was:");
        consoleData->PrintCenteredText(word, 0, 1);
    }

    Sleep(2000);
}
