#ifndef DRON_H
#define DRON_H

#include "InterfaceDrona.h"
#include "Prostopadloscian.h"
#include <chrono>

class Dron:public Prostopadloscian,public InterfaceDrona{

protected:
double predkosc;

public:
    void plynDoPrzodu(double odleglosc,double katWznoszenia)override;
    void plynDoPrzodu(double odleglosc)override;
    void obrocWOsiZ(double katObrotu)override;
    void ustawPredkosc(double predkoscDrona);

    using Prostopadloscian::Prostopadloscian;
};


#endif // DRON_H
