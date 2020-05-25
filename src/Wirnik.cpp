#include "../inc/Wirnik.h"

void Wirnik::ustawOdPozycjiDrona(Wektor3D srodekDrona, MacierzObrotu obrotDrona)
{
    this->macierzObrotu=obrotDrona*MacierzObrotu(Wektor3D(1,0,0),Wektor3D(0,0,-1),Wektor3D(0,1,0));
    this->pozycjaSrodka=obrotDrona*this->pozycjaWzgledemDrona+srodekDrona;
}
