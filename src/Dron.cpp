#include "../inc/Dron.h"




void Dron::plynDoPrzodu(double odleglosc)
{
    double deltaTime=0;
    std::chrono::steady_clock::time_point beginMeasuring;
    std::chrono::steady_clock::time_point endMeasuring;
    std::chrono::duration<double> elapsedTime;
    do{
        beginMeasuring = std::chrono::steady_clock::now();
        do{
        endMeasuring = std::chrono::steady_clock::now();
        elapsedTime = endMeasuring - beginMeasuring;
        }while(elapsedTime.count()<1.0/KLATKI_NA_SEC);
        //std::cout<<"HKKK\n";
        this->pozycjaSrodka +=(this->macierzObrotu*Wektor3D(0,this->predkosc*elapsedTime.count(),0));
        deltaTime+=elapsedTime.count();
        this->Rysuj();
    }while(deltaTime*this->predkosc<odleglosc);


}

void Dron::plynDoPrzodu(double odleglosc, double katWznoszenia)
{
    MacierzObrotu tmp = this->macierzObrotu;
    this->ObrocOKat(-katWznoszenia,OX);
    this->plynDoPrzodu(odleglosc);
    this->macierzObrotu = tmp;
    this->Rysuj();
}

void Dron::obrocWOsiZ(double katObrotu)
{
    this->ObrocOKat(katObrotu);
    this->Rysuj();
}


void Dron::ustawPredkosc(double predkoscDrona)
{
    this->predkosc = predkoscDrona;
}

void Dron::Rysuj()
{
    Prostopadloscian::Rysuj();
    this->wirnikLewy.ustawApi(this->drawingApi);
    this->wirnikPrawy.ustawApi(this->drawingApi);

    //this->wirnikLewy.pozycjaSrodka = this->pozycjaSrodka + this->wirnikLewy.polozenieWzgledemCialaDrona;
    this->wirnikLewy.ustawOdPozycjiDrona(this->pozycjaSrodka,this->macierzObrotu);
    this->wirnikPrawy.ustawOdPozycjiDrona(this->pozycjaSrodka,this->macierzObrotu);
    this->wirnikLewy.Rysuj();
    this->wirnikPrawy.Rysuj();
}
