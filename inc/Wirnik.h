#ifndef WIRNIK_H
#define WIRNIK_H

#include "graniastoslup6.h"

class Wirnik:public Graniastoslup6{

protected:
    Wektor3D pozycjaWzgledemDrona;

public:
    Wirnik() = delete;
    Wirnik(Wektor3D rozmieszczenie):pozycjaWzgledemDrona(rozmieszczenie){this->macierzObrotu = MacierzObrotu(Wektor3D(1,0,0),Wektor3D(0,0,-1),Wektor3D(0,1,0));}
    void ustawOdPozycjiDrona(Wektor3D srodekDrona, MacierzObrotu obrotDrona);

};




#endif // WIRNIK_H
