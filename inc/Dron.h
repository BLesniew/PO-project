#ifndef DRON_H
#define DRON_H

#include "InterfaceDrona.h"
#include "Prostopadloscian.h"
#include "Wirnik.h"
#include <chrono>

#define KLATKI_NA_SEC 60

class Dron:public Prostopadloscian,public InterfaceDrona{

protected:
    double predkosc;
    Wirnik wirnikLewy;
    Wirnik wirnikPrawy;

public:
    void plynDoPrzodu(double odleglosc,double katWznoszenia)override;
    void plynDoPrzodu(double odleglosc)override;
    void obrocWOsiZ(double katObrotu)override;
    void ustawPredkosc(double predkoscDrona);
    void Rysuj();

    //using Prostopadloscian::Prostopadloscian;
    Dron():predkosc(2),wirnikLewy(Wektor3D(-1,-1.5,0)),wirnikPrawy(Wektor3D(1,-1.5,0)){}                           //POZYCJE POWINNY BYC BARDZIEJ OPARTE NA OBLICZENIACH
    Dron(float prdkosc):predkosc(prdkosc),wirnikLewy(Wektor3D(-1,-1.5,0)),wirnikPrawy(Wektor3D(1,-1.5,0)){}                     //przy predkosciach zbyt duzych wzgledem renderowanych klatek na sekundę widać znaczące błedy obliczeniowe
};


#endif // DRON_H
