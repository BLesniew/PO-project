#ifndef DNO_H
#define DNO_H

#include "Plaszczyzna.h"
#include "InterfejsPrzeszkody.h"
#include "InterfaceDrona.h"


class Dno:public Plaszczyzna,public InterfacePrzeszody{


public:
    Dno(){this->wspolrzednaZ = -4;this->zmienKolor("yellow");}
    Dno(float pozycja){this->wspolrzednaZ = pozycja;this->zmienKolor("yellow");}
    Dno(float pozycja, float rozmiarPlaszczyzny){this->wspolrzednaZ = pozycja;this->zmienKolor("yellow");this->wielkoscPlaszczyzny=rozmiarPlaszczyzny;}
    Dno(float pozycja, float rozmiarPlaszczyzny, float rozmiarKratki){this->wspolrzednaZ = pozycja;this->zmienKolor("yellow");this->wielkoscPlaszczyzny=rozmiarPlaszczyzny;this->wielkoscKratki = rozmiarKratki;}

    bool czyKolizja(std::shared_ptr<InterfaceDrona> dronSterowany)override;
};

#endif // DNO_H
