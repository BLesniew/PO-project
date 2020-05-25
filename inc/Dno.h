#ifndef DNO_H
#define DNO_H

#include "Plaszczyzna.h"

class Dno:public Plaszczyzna{


public:
    Dno(){this->wspolrzednaZ = -4;this->zmienKolor("yellow");}
    Dno(float pozycja){this->wspolrzednaZ = pozycja;this->zmienKolor("yellow");}
    Dno(float pozycja, float rozmiarPlaszczyzny){this->wspolrzednaZ = pozycja;this->zmienKolor("yellow");this->wielkoscPlaszczyzny=rozmiarPlaszczyzny;}
    Dno(float pozycja, float rozmiarPlaszczyzny, float rozmiarKratki){this->wspolrzednaZ = pozycja;this->zmienKolor("yellow");this->wielkoscPlaszczyzny=rozmiarPlaszczyzny;this->wielkoscKratki = rozmiarKratki;}
};

#endif // DNO_H
