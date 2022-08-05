#include "Menu.h"
#include "SoundManager.h"





void GameMenu()
{
	srand(time(0));
	ConsoleFont();
	SizeScroll();
	int cursor = 1;
	char acceptKey = acceptDefaultKey;
	char deniedKey = deniedDefaultKey;
	char upKey = upDefaultKey;
	char downKey = downDefaultKey;
	char leftKey = leftDeaultKey;
	char rightKey = rightDefaultKey;
	char selectKey = selectDefaultKey;
	GameStates gameStates = GameStates::Menu;
	bool audio = true;
	PlayTheme(audio);
	do
	{
		if (!audio)
		{
			PlayNull();
		}
		while (!_kbhit() && gameStates != GameStates::Exit)
		{
			switch (gameStates)
			{
			case GameStates::Menu:
				MoveCursor(0, 0);
				SelectColor(Colors::Yellow);
				std::cout << R"(  
 
  ____               __  __               
 |  _ \  __ _   ___ |  \/  |  __ _  _ __  
 | |_) |/ _` | / __|| |\/| | / _` || '_ \ 
 |  __/| (_| || (__ | |  | || (_| || | | |
 |_|    \__,_| \___||_|  |_| \__,_||_| |_|
                                          
 )";
				SelectColor(Colors::White);
				if (cursor == (int)GameStates::Game)
				{
					SelectColor(Colors::Red);
				}

				cout << R"(  
               ____________
              /            \
             |     Jugar    |
              \____________/   )" <<
					endl;
				SelectColor(Colors::White);
				if (cursor == (int)GameStates::How)
				{
					SelectColor(Colors::Red);
				}
				cout << R"(  
               ____________
              /            \
             |  Como Jugar  |
              \____________/   )" <<
					endl;
				SelectColor(Colors::White);
				if (cursor == (int)GameStates::Options)
				{
					SelectColor(Colors::Red);
				}
				cout << R"(  
               ____________
              /            \
             |   Opciones   |
              \____________/   )" <<
					endl;
				SelectColor(Colors::White);
				if (cursor == (int)GameStates::Credits)
				{
					SelectColor(Colors::Red);
				}
				cout << R"(  
               ____________
              /            \
             |   Creditos   |
              \____________/   )" <<
					endl;
				SelectColor(Colors::White);
				if (cursor == (int)GameStates::Exit)
				{
					SelectColor(Colors::Red);
				}
				cout << R"(  
               ____________
              /            \
             |     Salir    |
              \____________/   )" <<
					endl;
				SelectColor(Colors::White);
				cout << "\n\nMuevase con ";
				SelectColor(Colors::Purple);
				cout << upKey;
				SelectColor(Colors::White);
				cout << " para arriba y ";
				SelectColor(Colors::Purple);
				cout << downKey;
				SelectColor(Colors::White);
				cout << " para abajo,\nselecione la opcion con ";
				SelectColor(Colors::Purple);
				cout << selectKey;
				SelectColor(Colors::White);
				cout << ".";
				break;
			case GameStates::Game:
				system("cls");
				GameLogic(rightKey, leftKey, upKey, downKey, selectKey, acceptKey, deniedKey,audio);
				gameStates = GameStates::Menu;
				system("cls");
				PlayTheme(audio);
				break;
			case GameStates::How:
				system("cls");
				SelectColor(Colors::Violet);
				std::cout << R"(
  _____            _           
 |  __ \          | |          
 | |__) |___  __ _| | __ _ ___ 
 |  _  // _ \/ _` | |/ _` / __|
 | | \ \  __/ (_| | | (_| \__ \
 |_|  \_\___|\__, |_|\__,_|___/
              __/ |            
             |___/                                            
)" << endl;
				SelectColor(Colors::Yellow);
				cout << "\nPacman";
				SelectColor(Colors::White);
				cout << " es un videjuego de habilidad en donde un jugador ";
				cout << "\ncontrolara a ";
				SelectColor(Colors::Yellow);
				cout << "Pacman";
				SelectColor(Colors::White);
				cout << " y tratara de comer todos los cocos(o puntos)";
				cout << "\nde la pantalla sin que los fantasmas lo atrapen.";
				cout << "\n\nEl jugador contara con 3 vidas y perdera una si toca aun fantasma.";
				cout << "\n\nEl juego se acaba si ";
				SelectColor(Colors::Yellow);
				cout << "Pacman";
				SelectColor(Colors::White);
				cout << " pierde las 3 vidas.";
				cout << "\nSi el jugador come una pildora podra momentaneamente";
				cout << "\ncomer a los fantasmas sin recibir da" << enie << "o.";
				SelectColor(Colors::Red);
				std::cout << R"(
   _____            _             _           
  / ____|          | |           | |          
 | |     ___  _ __ | |_ _ __ ___ | | ___  ___ 
 | |    / _ \| '_ \| __| '__/ _ \| |/ _ \/ __|
 | |___| (_) | | | | |_| | | (_) | |  __/\__ \
  \_____\___/|_| |_|\__|_|  \___/|_|\___||___/                                 
)" << endl;
				SelectColor(Colors::White);
				cout << "\nUtilize ";
				SelectColor(Colors::Yellow);
				cout << upKey << spa << leftKey << spa << downKey << spa << rightKey;
				SelectColor(Colors::White);
				cout << " para moverse.";
				cout << "\n\nUtilize la tecla ";
				SelectColor(Colors::Cream);
				cout << acceptKey;
				SelectColor(Colors::White);
				cout << " para pausar el juego.";
				cout << "\n\nAprete cualquier tecla para volver al menu.";
				_getch();
				gameStates = GameStates::Menu;
				system("cls");
				break;
			case GameStates::Options:
				OptionsMenu(cursor, rightKey, leftKey, upKey, downKey, selectKey, acceptKey, deniedKey,audio);
				gameStates = GameStates::Menu;
				system("cls");
				PlayTheme(audio);
				break;
			case GameStates::Credits:
				system("cls");
				SelectColor(Colors::BlueSecondType);
				std::cout << R"(
   _____              _ _ _            
  / ____|            | (_) |           
 | |     _ __ ___  __| |_| |_ ___  ___ 
 | |    | '__/ _ \/ _` | | __/ _ \/ __|
 | |____| | |  __/ (_| | | || (_) \__ \
  \_____|_|  \___|\__,_|_|\__\___/|___/
                            
)" << endl;
				SelectColor(Colors::White);
				cout << "\nJuego realizado por ";
				SelectColor(Colors::Red);
				cout << "Ignacio Arrastua";
				SelectColor(Colors::White);
				cout << " como trabajo Final ";
				cout << "\npara la materia Fundamentos de la Programacion 2022.";
				cout << "\nMain theme realizado por ";
				SelectColor(Colors::Violet);
				cout << "Ezequiel Gonzales";
				SelectColor(Colors::White);
				cout << ".\n\nAprete cualquier tecla para volver";
				_getch();
				gameStates = GameStates::Menu;
				system("cls");
				break;
			case GameStates::Exit:
				break;
			default:
				break;
			}
		}
		InputManager(gameStates, cursor, upKey, downKey, selectKey);
	} while (gameStates != GameStates::Exit);
}


void OptionsMenu(int& cursor, char& rightKey, char& leftKey, char& upKey, char& downKey, char& selectKey, char& acceptKey, char& deniedKey, bool& audio)
{
	cursor = 1;
	bool optionsLoop = true;
	Options opcion = (Options)cursor;
	do
	{
		system("cls");
		SelectColor(Colors::Violet);
		std::cout << R"(
   ____             _                       
  / __ \           (_)                      
 | |  | |_ __   ___ _  ___  _ __   ___  ___ 
 | |  | | '_ \ / __| |/ _ \| '_ \ / _ \/ __|
 | |__| | |_) | (__| | (_) | | | |  __/\__ \
  \____/| .__/ \___|_|\___/|_| |_|\___||___/
        | |                                 
        |_|                                 
)" << endl;
		SelectColor(Colors::White);
		cout << "Muevase con ";
		SelectColor(Colors::Violet);
		cout << upKey;
		SelectColor(Colors::White);
		cout << " y ";
		SelectColor(Colors::Violet);
		cout << downKey;
		SelectColor(Colors::White);
		cout << " y seleccione con ";
		SelectColor(Colors::Violet);
		cout << selectKey;
		SelectColor(Colors::White);
		cout << "\nla tecla que quiera cambiar(Cuidado con las mayusculas!)." << endl << endl;;
		if ((Options)cursor == Options::Up)
		{
			SelectColor(Colors::Yellow);
		}
		cout << "Arriba:" << upKey << endl;
		SelectColor(Colors::White);
		if ((Options)cursor == Options::Down)
		{
			SelectColor(Colors::Yellow);
		}
		cout << "Abajo:" << downKey << endl;
		SelectColor(Colors::White);
		if ((Options)cursor == Options::Left)
		{
			SelectColor(Colors::Yellow);
		}
		cout << "Izquierda:" << leftKey << endl;
		SelectColor(Colors::White);
		if ((Options)cursor == Options::Right)
		{
			SelectColor(Colors::Yellow);
		}
		cout << "Derecha:" << rightKey << endl;
		SelectColor(Colors::White);
		if ((Options)cursor == Options::Select)
		{
			SelectColor(Colors::Yellow);
		}
		cout << "Seleccionar:" << selectKey << endl;

		SelectColor(Colors::White);
		if ((Options)cursor == Options::Acept)
		{
			SelectColor(Colors::Yellow);
		}
		cout << "Pausa:" << acceptKey << endl;
		SelectColor(Colors::White);
		if ((Options)cursor == Options::Denied)
		{
			SelectColor(Colors::Yellow);
		}
		cout << "Salir:";
		if (deniedKey == deniedDefaultKey)
		{
			cout << "ESC";
		}
		else
		{
			cout << deniedKey;

		}
		cout << endl;
		SelectColor(Colors::White);
		if ((Options)cursor == Options::Audio)
		{
			SelectColor(Colors::Yellow);
		}
		cout << "Audio:";
		if (audio)
		{
			SelectColor(Colors::Green);
			cout << "ON";
		}
		else
		{
			SelectColor(Colors::Red);
			cout << "OFF";
		}
		cout << endl;
		SelectColor(Colors::White);
		if ((Options)cursor == Options::Default)
		{
			SelectColor(Colors::Yellow);
		}
		cout << "Volver a las teclas predeterminadas." << endl << endl;;
		SelectColor(Colors::White);
		if ((Options)cursor == Options::Menu)
		{
			SelectColor(Colors::Yellow);
		}
		cout << "Volver al menu principal." << endl;
		SelectColor(Colors::White);

		if (InputManager(cursor, upKey, downKey, selectKey))
		{
			ChooseOptions(cursor, optionsLoop, rightKey, leftKey, upKey, downKey, selectKey, acceptKey, deniedKey,audio);
		}
	} while (optionsLoop);
	cursor = 1;
}
void ChooseOptions(int cursor, bool& opcionesLoop, char& rightKey, char& leftKey, char& upKey, char& downKey, char& selectKey, char& acceptKey, char& deniedKey, bool& audio)
{
char tecla;
system("cls");
std::cout << R"(
   ____             _                       
  / __ \           (_)                      
 | |  | |_ __   ___ _  ___  _ __   ___  ___ 
 | |  | | '_ \ / __| |/ _ \| '_ \ / _ \/ __|
 | |__| | |_) | (__| | (_) | | | |  __/\__ \
  \____/| .__/ \___|_|\___/|_| |_|\___||___/
        | |                                 
        |_|                                 
)";
switch ((Options)cursor)
{
case Options::Up:
	cout << "Elija la tecla para moverse para arriba(actual " << upKey << "):";
	tecla = _getch();
	if (tecla != downKey && tecla != rightKey && tecla != leftKey && tecla != selectKey && tecla != acceptKey && tecla != deniedKey)
	{
		upKey = tecla;
		cout << "\nAhora " << upKey << " se ha seleccionado.";
	}
	else
	{
		cout << "\nSe ha vuelto a la tecla original.";
		upKey = upDefaultKey;
	}
	_getch();
	break;
case Options::Down:
	cout << "Elija la tecla para moverse para abajo(actual " << downKey << "):";
	tecla = _getch();
	if (tecla != upKey && tecla != rightKey && tecla != leftKey && tecla != selectKey && tecla != acceptKey && tecla != deniedKey)
	{
		downKey = tecla;
		cout << "\nAhora " << downKey << " se ha seleccionado.";
	}
	else
	{
		cout << "\nSe ha vuelto a la tecla original.";
		downKey = downDefaultKey;
	}
	_getch();
	break;
case Options::Left:
	cout << "Elija la tecla para moverse hacia la izquierda(actual " << leftKey << "):";
	tecla = _getch();
	if (tecla != downKey && tecla != rightKey && tecla != upKey && tecla != selectKey && tecla != acceptKey && tecla != deniedKey)
	{
		leftKey = tecla;
		cout << "\nAhora " << leftKey << " se ha seleccionado.";
	}
	else
	{
		cout << "\nSe ha vuelto a la tecla original.";
		leftKey = leftDeaultKey;
	}
	_getch();
	break;
case Options::Right:
	cout << "Elija la tecla para moverse hacia la derecha(actual " << rightKey << "):";
	tecla = _getch();
	if (tecla != downKey && tecla != upKey && tecla != leftKey && tecla != selectKey && tecla != acceptKey && tecla != deniedKey)
	{
		rightKey = tecla;
		cout << "\nAhora " << rightKey << " se ha seleccionado.";
	}
	else
	{
		cout << "\nSe ha vuelto a la tecla original.";
		rightKey = rightDefaultKey;
	}
	_getch();
	break;
case Options::Select:
	cout << "Elija la tecla para seleccionar(actual " << selectKey << "):";
	tecla = _getch();
	if (tecla != downKey && tecla != rightKey && tecla != leftKey && tecla != upKey && tecla != acceptKey && tecla != deniedKey)
	{
		selectKey = tecla;
		cout << "\nAhora " << selectKey << " se ha seleccionado.";
	}
	else
	{
		cout << "\nSe ha vuelto a la tecla original.";
		selectKey = selectDefaultKey;
	}

	_getch();
	break;
case Options::Acept:
	cout << "Elija la tecla para moverse para pausa(actual " << acceptKey << "):";
	tecla = _getch();
	if (tecla != downKey && tecla != rightKey && tecla != leftKey && tecla != selectKey && tecla != upKey && tecla != deniedKey)
	{
		acceptKey = tecla;
		cout << "\nAhora " << acceptKey << " se ha seleccionado.";
	}
	else
	{
		cout << "\nSe ha vuelto a la tecla original.";
		acceptKey = acceptDefaultKey;


	}
	_getch();
	break;
case Options::Denied:
	cout << "Elija la tecla para moverse para salir(actual ";
	if (deniedKey == deniedDefaultKey)
	{
		cout << "ESC";
	}
	else
	{
		cout << deniedKey;

	}
	cout << "):";
	tecla = _getch();
	if (tecla != downKey && tecla != rightKey && tecla != leftKey && tecla != selectKey && tecla != acceptKey && tecla != upKey)
	{
		deniedKey = tecla;
		cout << "\nAhora ";
		if (deniedKey == deniedDefaultKey)
		{
			cout << "ESC";
		}
		else
		{
			cout << deniedKey;

		}
		cout << " se ha seleccionado.";
	}
	else
	{
		cout << "\nSe ha vuelto a la tecla original.";
		deniedKey = deniedDefaultKey;
	}
	_getch();
	break;

case Options::Audio:
	if (audio)
	{
		audio = false;
		PlayNull();
	}
	else
	{
		audio = true;
	}
	break;
case Options::Default:
	cout << "Se han reseteado todas las teclas a su valor por defecto.";
	ResetKeys(rightKey, leftKey, upKey, downKey, selectKey, acceptKey, deniedKey);
	_getch();
	break;
case Options::Menu:
	system("cls");
	opcionesLoop = false;

	break;

}


}


void ResetKeys(char& rightKey, char& leftKey, char& upKey, char& downKey, char& selectKey, char& acceptKey, char& deniedKey)
{
	acceptKey = acceptDefaultKey;
	deniedKey = deniedDefaultKey;
	upKey = upDefaultKey;
	downKey = downDefaultKey;
	leftKey = leftDeaultKey;
	rightKey = rightDefaultKey;
	selectKey = selectDefaultKey;
}
