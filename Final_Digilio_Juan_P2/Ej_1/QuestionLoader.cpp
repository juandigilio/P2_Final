#include "QuestionLoader.h"

#include "SaveManager.h"

QuestionLoader::QuestionLoader()
{
}

QuestionLoader::~QuestionLoader()
{
}

void QuestionLoader::Init()
{
	Question pack[5];

	{
		pack[0].qustion = "Planeta mas grande del sistema solar";
		pack[0].correctOption = "Jupiter";
		pack[0].option1 = "Saturno";
		pack[0].option2 = "Neptuno";
		pack[0].option3 = "Urano";
		pack[0].option4 = "Marte";

		pack[1].qustion = "Particula subatomica con carga negativa.";
		pack[1].correctOption = "Electron";
		pack[1].option1 = "Proton";
		pack[1].option2 = "Neutron";
		pack[1].option3 = "Quark";
		pack[1].option4 = "Foton";

		pack[2].qustion = "Elemento quimico mas abundante del universo.";
		pack[2].correctOption = "Hidrogeno";
		pack[2].option1 = "Oxigeno";
		pack[2].option2 = "Helio";
		pack[2].option3 = "Carbono";
		pack[2].option4 = "Nitrogeno";

		pack[3].qustion = "Creador de la teoria de la relatividad.";
		pack[3].correctOption = "Albert Einstein";
		pack[3].option1 = "Isaac Newton";
		pack[3].option2 = "Nikola Tesla";
		pack[3].option3 = "Galileo Galilei";
		pack[3].option4 = "Stephen Hawking";

		pack[4].qustion = "Capa de la atmosfera mas cercana a la tierra";
		pack[4].correctOption = "Troposfera";
		pack[4].option1 = "Estratofera";
		pack[4].option2 = "Mesosfera";
		pack[4].option3 = "Termosfera";
		pack[4].option4 = "Exosfera";
	}
	PushPack(sciencePack, pack);

	{
		pack[0].qustion = "En las condiciones adecuadas, puede viajar mas rapido que la luz.";
		pack[0].correctOption = "Neutrino";
		pack[0].option1 = "Foton";
		pack[0].option2 = "Electron";
		pack[0].option3 = "Proton";
		pack[0].option4 = "Neutron";

		pack[1].qustion = "Es la fuerza que mantiene unidos los nucleos atomicos.";
		pack[1].correctOption = "Fuerza nuclear fuerte";
		pack[1].option1 = "Fuerza nuclear debil";
		pack[1].option2 = "Fuerza electromagnetica";
		pack[1].option3 = "Fuerza de gravedad";
		pack[1].option4 = "Fuerza de friccion";

		pack[2].qustion = "Es la colision de una particula cargada elcticamente contra la atmosfera de la tierra.";
		pack[2].correctOption = "Aurora boreal";
		pack[2].option1 = "Arcoiris";
		pack[2].option2 = "Estrella fugaz";
		pack[2].option3 = "Atardecer naranja";
		pack[2].option4 = "Rayos infrarrojos";

		pack[3].qustion = "Es la fuerza que mantiene a los planetas en orbita alrededor del sol.";
		pack[3].correctOption = "Fuerza de gravedad";
		pack[3].option1 = "Fuerza electromagnetica";
		pack[3].option2 = "Fuerza nuclear fuerte";
		pack[3].option3 = "Fuerza nuclear debil";
		pack[3].option4 = "Fuerza de atraccion";

		pack[4].qustion = "Fenomeno que se da en casos execpionales, en el que las leyes de la fisica dejan de ser validas.";
		pack[4].correctOption = "Singularidad";
		pack[4].option1 = "Paradoja";
		pack[4].option2 = "Anomalia";
		pack[4].option3 = "Fenomeno paranormal";
		pack[4].option4 = "Fenomeno extraterrestre";
	}
	PushPack(phisicsPack, pack);

	{
		pack[0].qustion = "Primer juego del Nintendo 64.";
		pack[0].correctOption = "Super Mario 64";
		pack[0].option1 = "Donkey Kong 64";
		pack[0].option2 = "Golden  Eye";
		pack[0].option3 = "Banjo & Kazooe";
		pack[0].option4 = "Mario Kart";

		pack[1].qustion = "Consola mas vendida de todos los tiempos.";
		pack[1].correctOption = "Play Station 2";
		pack[1].option1 = "Play Station 1";
		pack[1].option2 = "Nintendo Switch";
		pack[1].option3 = "Nintendo DS";
		pack[1].option4 = "GameBoy";

		pack[2].qustion = "Primer juego FPS.";
		pack[2].correctOption = "Wolfenstein 3D";
		pack[2].option1 = "DOOM";
		pack[2].option2 = "Duke Nukem";
		pack[2].option3 = "Half Life";
		pack[2].option4 = "Counter Strike";

		pack[3].qustion = "Juego mas vendido de la historia.";
		pack[3].correctOption = "Tetris";
		pack[3].option1 = "Minecraft";
		pack[3].option2 = "Super Mario";
		pack[3].option3 = "GTA V";
		pack[3].option4 = "The Witcher 3";

		pack[4].qustion = "La pesadilla de todo verdadero gamer.";
		pack[4].correctOption = "El templo del agua";
		pack[4].option1 = "Que se corte la luz";
		pack[4].option2 = "Quedarse sin internet";
		pack[4].option3 = "Que se cuelgue el juego y no hayas guardado la partida";
		pack[4].option4 = "Las 3 luces rojas de la X-box";
	}
	PushPack(gamingPack, pack);

	{
		pack[0].qustion = "Industria creadora del turbo compresor.";
		pack[0].correctOption = "Aeronautica";
		pack[0].option1 = "Automotriz";
		pack[0].option2 = "Nautica";
		pack[0].option3 = "Ejercito";
		pack[0].option4 = "Nasa";

		pack[1].qustion = "Razon por la que un motor puede producir exceso de humo negro.";
		pack[1].correctOption = "Exceso de combustible en la mezcla";
		pack[1].option1 = "Esta quemando aceite";
		pack[1].option2 = "Aros danados";
		pack[1].option3 = "Motor frio";
		pack[1].option4 = "Todas son correctas";

		pack[2].qustion = "Conjunto mecanico encargado de distribuir de maner NO uniforme la potencia a las ruedas.";
		pack[2].correctOption = "Diferencial";
		pack[2].option1 = "Control de traccion";
		pack[2].option2 = "ABS";
		pack[2].option3 = "ESP";
		pack[2].option4 = "Control de estabilidad";

		pack[3].qustion = "Los motores diesel llevan calentadores en vez de bujia porque.";
		pack[3].correctOption = "Funcionan por detonacion";
		pack[3].option1 = "Funcionan por explocion";
		pack[3].option2 = "Funcionan por ignicion";
		pack[3].option3 = "Tienen turbo";
		pack[3].option4 = "Tienen inyectores";

		pack[4].qustion = "Los motores de competicion utilizan valvulas de titaneo porque el titaneo.";
		pack[4].correctOption = "Disipa mas temperatura";
		pack[4].option1 = "Es mas liviano";
		pack[4].option2 = "Es mas duro";
		pack[4].option3 = "Es mas resistente";
		pack[4].option4 = "Todas son correctas";
	}
	PushPack(mechanicsPack, pack);

	{
		pack[0].qustion = "Razon principal por la que usamos quaterniones en fisica";
		pack[0].correctOption = "Todas son correctas";
		pack[0].option1 = "Evitar usar matrices";
		pack[0].option2 = "Porque estamos todos locos";
		pack[0].option3 = "Evitar usar grados euler";
		pack[0].option4 = "Evitar el gimball lock";

		pack[1].qustion = "Un plano es.";
		pack[1].correctOption = "Una sucesion infinita de lineas";
		pack[1].option1 = "Un espacio delimitado por 4 lineas";
		pack[1].option2 = "Un conjunto de lineas determinadas";
		pack[1].option3 = "Un espacio bidimensional";
		pack[1].option4 = "Todas son correctas";

		pack[2].qustion = "La inversa de una matriz es.";
		pack[2].correctOption = "La determinante de todos los puntos";
		pack[2].option1 = "La version negativa de si misma";
		pack[2].option2 = "La matriz identidad";
		pack[2].option3 = "El resultado de multiplicarla por si misma";
		pack[2].option4 = "El resultado de dividirla por si misma";

		pack[3].qustion = "Un quaternion es.";
		pack[3].correctOption = "Un numero hiper complejo";
		pack[3].option1 = "Un numero complejo";
		pack[3].option2 = "Un conjunto de numeros complejos";
		pack[3].option3 = "Un conjunto de numeros reales";
		pack[3].option4 = "El peor invento de la historia";

		pack[4].qustion = "Las rotaciones en un espacio 3D deben manejarse mediante.";
		pack[4].correctOption = "Multiplicacion de quaterniones";
		pack[4].option1 = "Multiplicacion de matrices";
		pack[4].option2 = "Utilizando grados Euler";
		pack[4].option3 = "Utilizando producto punto";
		pack[4].option4 = "Utilizando matrices y vectores";
	}
	PushPack(mathsPack, pack);

	SavePacks();
}

void QuestionLoader::PushPack(vector<Question>& emptyPack, Question dataPack[5])
{
	for (int i = 0; i < 5; i++)
	{
		emptyPack.push_back(dataPack[i]);
	}
}

void QuestionLoader::SavePacks()
{
	SaveManager::SaveQuestionsPack(sciencePack, "../Data/SciencePack.dat");
	SaveManager::SaveQuestionsPack(phisicsPack, "../Data/PhisicsPack.dat");
	SaveManager::SaveQuestionsPack(gamingPack, "../Data/GamingPack.dat");
	SaveManager::SaveQuestionsPack(mechanicsPack, "../Data/MechanicsPack.dat");
	SaveManager::SaveQuestionsPack(mathsPack, "../Data/MathsPack.dat");
}

vector<Question> QuestionLoader::GetSciencePack()
{
	return sciencePack;
}

vector<Question> QuestionLoader::GetPhisicsPack()
{
	return phisicsPack;
}

vector<Question> QuestionLoader::GetGamingPack()
{
	return gamingPack;
}

vector<Question> QuestionLoader::GetMechanicsPack()
{
	return mechanicsPack;
}

vector<Question> QuestionLoader::GetMathsPack()
{
	return mathsPack;
}
