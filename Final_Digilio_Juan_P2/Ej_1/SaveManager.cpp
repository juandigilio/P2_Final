#include "SaveManager.h"


#include <fstream>


void SaveManager::SaveQuestionsPack(vector<Question>& questionsPack, const string& filePath)
{
	ofstream outputStream = ofstream();

	try
	{
		cout << "Writing to the data file..." << endl;

		outputStream.open(filePath, ios::out | ios::binary);

		if (!outputStream.is_open())
		{
			throw ofstream::failure("The file could not be opened");
		}

		size_t questionCount = questionsPack.size();
		outputStream.write(reinterpret_cast<char*>(&questionCount), sizeof(questionCount));

		for (const auto& question : questionsPack)
		{
			auto writeString = [&](const string& str)
				{
					size_t size = str.size();
					outputStream.write(reinterpret_cast<const char*>(&size), sizeof(size));
					outputStream.write(str.data(), size);

					if (outputStream.fail())
					{
						throw ofstream::failure("The file could not be written correctly");
					}
				};

			writeString(question.qustion);
			writeString(question.correctOption);
			writeString(question.option1);
			writeString(question.option2);
			writeString(question.option3);
			writeString(question.option4);
		}

		outputStream.close();

		if (outputStream.is_open())
		{
			throw ofstream::failure("The file could not be closed");
		}
	}
	catch (const ofstream::failure& exception)
	{
		cerr << "OUTPUT FILE STREAM ERROR: " << exception.what() << endl;

		if (outputStream.is_open())
		{
			outputStream.close();
		}
	}
}

void SaveManager::LoadQuestionsPack(vector<Question>& questionsPack, const string& filePath)
{
    ifstream inputStream;

    try
    {
        cout << "Reading from the data file..." << endl;

        inputStream.open(filePath, ios::in | ios::binary);

        if (!inputStream.is_open())
        {
            throw ifstream::failure("The file could not be opened");
        }

        size_t questionCount;
        inputStream.read(reinterpret_cast<char*>(&questionCount), sizeof(questionCount));

        if (inputStream.fail())
        {
            throw ifstream::failure("Error reading question count");
        }

        auto readString = [&](string& str)
        {
             size_t size;
             inputStream.read(reinterpret_cast<char*>(&size), sizeof(size));
             
             if (inputStream.fail())
             {
                 throw ifstream::failure("Error reading string size");
             }
             
             str.resize(size);
             inputStream.read(&str[0], size);
             
             if (inputStream.fail())
             {
                 throw ifstream::failure("Error reading string data");
             }
        };

        questionsPack.clear();

        for (size_t i = 0; i < questionCount; ++i)
        {
            Question question;
            readString(question.qustion);
            readString(question.correctOption);
            readString(question.option1);
            readString(question.option2);
            readString(question.option3);
            readString(question.option4);

            questionsPack.push_back(question);
        }

        inputStream.close();

        if (inputStream.is_open())
        {
            throw ifstream::failure("The file could not be closed");
        }
    }
    catch (const ifstream::failure& exception)
    {
        cerr << "INPUT FILE STREAM ERROR: " << exception.what() << endl;

        if (inputStream.is_open())
        {
            inputStream.close();
        }
    }
}
