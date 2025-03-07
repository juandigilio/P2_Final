#include "GameData.h"


namespace SumaTestData
{
	bool isDecimal = false;
	string welcome = ">>Opciones de dificultad<<";
	string type = "Seleccione el tipo de dato: ";
	string integer = "1- Entero";
	string decimal = "2- Decimal";
	string values = "Seleccione el rango de valores: ";
	string values2 = "Diferencia minima entre min y max (10)";
	string minText = "Minimo:";
	string maxText = "Maximo:";
	string roundsQnty = "Cantidad de rondas (min 1)";
	string roundLength = "Cantidad de numeros por ronda (min 3)";
	string delayText = "Tiempo de respuesta (min 0.5s)";
	string resultInputStr = "Ingrese el resultado:";
	string wellDone = "Correcto!";
	string wrongAnswer = "Incorrecto, el resultado es: ";
	string nextRound = "Siguiente ronda >>>>";
	string totalAcerted = "Aciertos totales: ";

	Vector2<int> welcomePos{};
	Vector2<int> typePos{};
	Vector2<int> integerPos{};
	Vector2<int> decimalPos{};
	Vector2<int> valuesPos{};
	Vector2<int> values2Pos{};
	Vector2<int> minPos{};
	Vector2<int> maxPos{};
	Vector2<int> roundsQntyPos{};
	Vector2<int> roundLengthPos{};
	Vector2<int> delayPos{};
	Vector2<int> resultInputPos{};
	Vector2<int> wellDonePos{};
	Vector2<int> wrongAnswerPos{};
	Vector2<int> nextRoundPos{};
	Vector2<int> totalAcertedPos{};
}

namespace MainMenuData
{
	string menuWelcome = ">>FreakyGames<<";
	string option1 = "1- SumaTest";
	string option2 = "2- Pregunta3";
	string option3 = "3- Definite";
	string exitStr = "ESC - Exit";
	string clean = "                               ";

	Vector2<int> menuWelcomePos{};
	Vector2<int> option1Pos{};
	Vector2<int> option2Pos{};
	Vector2<int> option3Pos{};
	Vector2<int> exitPos{};
}