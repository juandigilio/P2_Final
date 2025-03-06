#ifndef SUMATEST_TPP
#define SUMATEST_TPP

#include "SumaTest.h"

//#include "Vector2.h"


template<is_numeric T>
inline SumaTest<T>::SumaTest(ConsoleHandler* consoleData)
{
	result = 0;
	hardMode = false;
	this->consoleData = consoleData;
}

template<is_numeric T>
inline SumaTest<T>::~SumaTest()
{
}

template<is_numeric T>
void SumaTest<T>::Init()
{
	welcome = ">>Opciones de dificultad<<";
	type = "Seleccione el tipo de dato: ";
	integer = "1- Entero";
	decimal = "2- Decimal";
	values = "Seleccione el rango de valores: ";
	min = "Minimo:";
	max = "Maximo:";

	Vector2<int> center = consoleData->GetConsoleCenter();

	welcomePos{ center.x - welcome.length() / 2, center.y };
	typePos{ center.x - type.length() / 2, center.y };
	integerPos{ center.x - integer.length() / 2, center.y };
	decimalPos{ center.x - decimal.length() / 2, center.y + 1 };
	valuesPos{ center.x - values.length() / 2, center.y };
	minPos{ center.x - min.length() / 2, center.y + 1 };
	maxPos{ center.x - max.length() / 2, center.y + 1 };
}

template<is_numeric T>
void SumaTest<T>::ShowDifficultyMenu()
{
	


	welcomePos.x = (consoleData->consoleWide / 2) - (welcome.length() / 2);
	welcomePos.y = (consoleData->consoleHeight / 20) * 6;
}

template<is_numeric T>
void SumaTest<T>::SetDifficulty()
{
	consoleData->DrawFrame(0);


	cout << "Select difficulty: " << endl;
	cout << "1- Easy" << endl;
	cout << "2- Hard" << endl;
	cout << "3- Back" << endl;
	cout << "4- Exit" << endl;
	cout << "Select an option: ";
	cin >> userInput;
	switch (userInput)
	{
		case '1':
			hardMode = false;
			break;
		case '2':
			hardMode = true;
			break;
		case '3':
			break;
		case '4':
			keepPlaying = false;
			break;
		default:
			cout << "Invalid option" << endl;
			break;
	}
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


#endif