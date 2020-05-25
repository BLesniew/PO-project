#ifndef POZIOMMORZA_H
#define POZIOMMORZA_H

#include "Plaszczyzna.h"

class PoziomMorza:public Plaszczyzna{

protected:
    float wysokoscFal;

public:
    PoziomMorza():wysokoscFal(1){this->wspolrzednaZ = 4;this->zmienKolor("blue");}
    PoziomMorza(float wysokFal):wysokoscFal(wysokFal){this->wspolrzednaZ = 4;this->zmienKolor("blue");}
    PoziomMorza(float wysokFal,float pozycja):wysokoscFal(wysokFal){this->wspolrzednaZ = pozycja;this->zmienKolor("blue");}
    PoziomMorza(float wysokFal,float pozycja,float rozmiarPlaszczyzny):wysokoscFal(wysokFal){this->wspolrzednaZ = pozycja;this->wielkoscPlaszczyzny = rozmiarPlaszczyzny;this->zmienKolor("blue");}
    PoziomMorza(float wysokFal,float pozycja,float rozmiarPlaszczyzny,float rozmiarKratki):wysokoscFal(wysokFal){this->wspolrzednaZ = pozycja;this->wielkoscPlaszczyzny = rozmiarPlaszczyzny;this->wielkoscKratki = rozmiarKratki;this->zmienKolor("blue");}
    void Rysuj() override;

};



#endif // POZIOMMORZA_H
