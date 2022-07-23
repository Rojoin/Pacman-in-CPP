#include "GameLogic.h"


void pruebaBajarPieza(Grilla& grilla,Bloque bloque)
{
    
    bloque.BajarPieza(grilla);
}


void GameLogic(Grilla& grilla)
{
    Posicion pos = { 4,0 };
    Bloque bloque{TipoDeBloque::I,Rotacion::Grado0,true,true,pos};
    BloqueI bloqueI{TipoDeBloque::I,Rotacion::Grado0,true,true,pos};
    bloque = bloqueI;
    do
    {
        if (clock() % 1000 == 0)
        {

            grilla.UpdatearGrilla();
            grilla.CheckearLineas();


        }
    } while (!_kbhit());
    if (_getch())
    {
        pruebaBajarPieza(grilla, bloque);
    }
}