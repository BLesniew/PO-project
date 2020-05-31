#include "../inc/Wirnik.h"

void Wirnik::ustawOdPozycjiDrona(Wektor3D srodekDrona, MacierzObrotu obrotDrona)
{
    this->macierzObrotu=obrotDrona*(MacierzObrotu(Wektor3D(1,0,0),Wektor3D(0,0,-1),Wektor3D(0,1,0)));
    this->ObrocOKat(katObr);
    this->pozycjaSrodka=obrotDrona*this->pozycjaWzgledemDrona+srodekDrona;
}

void Wirnik::obroc(double katObrotu)
{
    this->katObr+=katObrotu;
    while(katObr<0)
    {
        this->katObr+=360;
    }
    if(katObr>360)
    {
        this->katObr-=360;
    }
}
