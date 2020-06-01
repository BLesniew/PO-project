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
        this->wirnikLewy.obroc(this->predkoscObrotuWirnikow*elapsedTime.count());
        this->wirnikPrawy.obroc(this->predkoscObrotuWirnikow*elapsedTime.count());
        deltaTime+=elapsedTime.count();
        this->Rysuj();
    }while(deltaTime*this->predkosc<odleglosc);


}

void Dron::plynDoPrzodu(double odleglosc, double katWznoszenia)
{
    MacierzObrotu tmp = this->macierzObrotu;
    this->ObrocOKat(-katWznoszenia,OX);
    this->plynDoPrzodu(odleglosc);
    this->ObrocOKat(katWznoszenia,OX);
    this->macierzObrotu = tmp;
    this->Rysuj();
}

void Dron::obrocWOsiZ(double katObrotu)
{
    this->ObrocOKat(katObrotu,OZ);
}

void Dron::ObrocOKat(double katObrotu,Axis osObrotu)
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
        if(katObrotu>0)
        {
            this->Bryla::ObrocOKat(this->predkoscObrotu*elapsedTime.count(),osObrotu);
            if(osObrotu == OZ)
            {
                this->wirnikLewy.obroc(this->predkoscObrotuWirnikow*elapsedTime.count());
                this->wirnikPrawy.obroc(-this->predkoscObrotuWirnikow*elapsedTime.count());
            }

        }
        else
        {
            this->Bryla::ObrocOKat(-this->predkoscObrotu*elapsedTime.count(),osObrotu);
            if(osObrotu == OZ)
            {
                this->wirnikLewy.obroc(-this->predkoscObrotuWirnikow*elapsedTime.count());
                this->wirnikPrawy.obroc(this->predkoscObrotuWirnikow*elapsedTime.count());
            }

        }
        deltaTime+=elapsedTime.count();
        this->Rysuj();
    }while(deltaTime*this->predkoscObrotu<abs(katObrotu));
}

void Dron::ustawPredkoscObrotu(double predkoscO)
{
    this->predkoscObrotu = predkoscO;
}

void Dron::ustawPredkoscObrotuWirnikow(double predkoscW)
{
    this->predkoscObrotuWirnikow = predkoscW;
}


void Dron::ustawPredkosc(double predkoscDrona)
{
    this->predkosc = predkoscDrona;
}

void Dron::ustawApi(std::shared_ptr<drawNS::Draw3DAPI> api)
{
    this->ObiektRysowalny::ustawApi(api);
    this->wirnikLewy.ustawApi(api);
    this->wirnikPrawy.ustawApi(api);
}


void Dron::Rysuj()
{
    Prostopadloscian::Rysuj();

    //this->wirnikLewy.pozycjaSrodka = this->pozycjaSrodka + this->wirnikLewy.polozenieWzgledemCialaDrona;
    this->wirnikLewy.ustawOdPozycjiDrona(this->pozycjaSrodka,this->macierzObrotu);
    this->wirnikPrawy.ustawOdPozycjiDrona(this->pozycjaSrodka,this->macierzObrotu);
    this->wirnikLewy.Rysuj();
    this->wirnikPrawy.Rysuj();
}

double Dron::zwrocPromien()
{
    return sqrt(this->szerokosc*this->szerokosc/4+this->wysokosc*this->wysokosc/4+this->dlugosc*this->dlugosc/4);
}

Wektor3D Dron::zwrocPozycje()
{
    return this->pozycjaSrodka;
}

bool Dron::czyKolizja(std::shared_ptr<InterfaceDrona> dronSterowany)
{
    return (this->zwrocPromien()+dronSterowany->zwrocPromien()>=(this->zwrocPozycje()-dronSterowany->zwrocPozycje()).dlugosc());
}
