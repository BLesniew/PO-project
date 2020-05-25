#ifndef PLASZCZYZNA_H
#define PLASZCZYZNA_H

#include "ObiektRysowalny.h"
using std::vector;
using drawNS::Point3D;

class Plaszczyzna:public ObiektRysowalny{

protected:
    float wspolrzednaZ;
    float wielkoscPlaszczyzny;
    float wielkoscKratki;



public:
    Plaszczyzna():wspolrzednaZ(0),wielkoscPlaszczyzny(10),wielkoscKratki(1){}
    Plaszczyzna(float pozycja):wspolrzednaZ(pozycja),wielkoscPlaszczyzny(10),wielkoscKratki(1){}
    Plaszczyzna(float pozycja,float rozmiarPlaszczyzny):wspolrzednaZ(pozycja),wielkoscPlaszczyzny(rozmiarPlaszczyzny),wielkoscKratki(1){}
    Plaszczyzna(float pozycja,float rozmiarPlaszczyzny,float rozmiarKratki):wspolrzednaZ(pozycja),wielkoscPlaszczyzny(rozmiarPlaszczyzny),wielkoscKratki(rozmiarKratki){}
    void Rysuj() override;

};


#endif // PLASZCZYZNA_H
