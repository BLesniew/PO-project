#ifndef DRON_H
#define DRON_H

#include "InterfaceDrona.h"
#include "Prostopadloscian.h"
#include "Wirnik.h"
#include "InterfejsPrzeszkody.h"

#include <chrono>

#define KLATKI_NA_SEC 60

class Dron:public Prostopadloscian,public InterfaceDrona, public InterfacePrzeszody{

protected:
    double predkosc;
    double predkoscObrotu;
    double predkoscObrotuWirnikow;
    Wirnik wirnikLewy;
    Wirnik wirnikPrawy;

public:
    void plynDoPrzodu(double odleglosc,double katWznoszenia)override;
    void plynDoPrzodu(double odleglosc)override;
    void obrocWOsiZ(double katObrotu)override;

    void ObrocOKat(double katWStopniach, Axis osObrotu);
    void ustawApi(std::shared_ptr<drawNS::Draw3DAPI> api);

    void ustawPredkosc(double predkoscDrona);
    void ustawPredkoscObrotu(double predkoscO);
    void ustawPredkoscObrotuWirnikow(double predkoscW);
    void Rysuj();

    double zwrocPromien()override;
    Wektor3D zwrocPozycje()override;

    //using Prostopadloscian::Prostopadloscian;
    Dron():predkosc(2),wirnikLewy(Wektor3D(-2*this->szerokosc/5,-this->dlugosc/2,0)),
        wirnikPrawy(Wektor3D(2*this->szerokosc/5,-this->dlugosc/2,0)),predkoscObrotu(100),predkoscObrotuWirnikow(600){}
    Dron(double prdkosc):predkosc(prdkosc),wirnikLewy(Wektor3D(-2*this->szerokosc/5,-this->dlugosc/2,0)),
        wirnikPrawy(Wektor3D(2*this->szerokosc/5,-this->dlugosc/2,0)),predkoscObrotu(100),predkoscObrotuWirnikow(600){}                     //przy predkosciach zbyt duzych wzgledem renderowanych klatek na sekundę widać znaczące błedy obliczeniowe

    bool czyKolizja(std::shared_ptr<InterfaceDrona> dronSterowany)override;
};


#endif // DRON_H
