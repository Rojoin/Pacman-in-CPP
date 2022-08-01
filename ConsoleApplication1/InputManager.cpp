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
void InputManager(Pacman& pacman)
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

    } //Seleccion
    
    else if (input == aceptarTecla)
    {
       // Continuar();
    }
    else if (input == resetTecla)
    {
        //Reset();
    }
}

