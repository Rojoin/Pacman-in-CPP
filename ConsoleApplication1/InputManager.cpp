#include "InputManager.h"

const char arribaDefault = 'w';
const char abajoDefault = 's';
const char izquierdaDefault = 'a';
const char derechaDefault = 'd';
const char seleccionarDefault = 'e';
const char resetTeclaDefault = 'r';
const char aceptarTeclaDefault = '1';
const char negarTeclaDefault = '2';
char aceptarTecla = aceptarTeclaDefault;
char negarTecla = negarTeclaDefault;
char arriba = arribaDefault;
char abajo = abajoDefault;
char izquierda = izquierdaDefault;
char derecha = derechaDefault;
char seleccionar = seleccionarDefault;
char resetTecla = resetTeclaDefault;
void Continuar(bool& gameOver, bool& juegoCorriendo)
{
	MoverCursor(30, 4);
	ElegirColor(Colores::Amarillo);
	cout << "Quieres volver al menu principal? ";
	MoverCursor(30, 5);
	cout <<"Aprete ";
	ElegirColor(Colores::VerdeClaro);
	cout << aceptarTecla;
	ElegirColor(Colores::Amarillo);
	cout << " para salir o ";
	ElegirColor(Colores::RojoClaro);
	cout << negarTecla;
	ElegirColor(Colores::Amarillo);
	cout << " seguir jugando";
	char input = _getch();
	if (input == aceptarTecla)
	{
		ElegirColor(Colores::Blanco);
		MoverCursor(30, 4);
		cout << "                                                                         ";
		MoverCursor(30, 5);
		cout << "                                                                         ";
		MoverCursor(30, 4);
		ElegirColor(Colores::Amarillo);
		cout << "Gracias por Jugar,aprete cualquier tecla para volver al menu :)";
		gameOver = false;
		juegoCorriendo = false;
		//menuController = MenuController::Menu;
		ElegirColor(Colores::Blanco);
	}
	else if (input == negarTecla)
	{
		ElegirColor(Colores::Blanco);
		MoverCursor(30, 4);
		cout << "                                                                         ";
		MoverCursor(30, 5);
		cout << "                                                                         ";
		return;
	}
	else
	{
		Continuar(gameOver,juegoCorriendo);
	}

}
void InputManager(Pacman& pacman,bool& gameOver, bool& juegoCorriendo)
{
	char input = _getch();
    if (input == arriba)
    {
        pacman.direccionActual = Direccion::Arriba;
    } //Arriba  
    else if (input == abajo)
    {
        pacman.direccionActual = Direccion::Abajo;
    } //Abajo
    else if (input == izquierda)
    {
        pacman.direccionActual = Direccion::Izquierda;
    } //Izquierda
    else if (input == derecha)
    {
        pacman.direccionActual = Direccion::Derecha;
    } //Derecha
    else if (input == seleccionar)
    {
		pacman.cocos = 228;
    } //Seleccion
    
    else if (input == aceptarTecla)
    {
       Continuar(gameOver,juegoCorriendo);
    }
    else if (input == resetTecla)
    {
        //Reset();
    }
}

