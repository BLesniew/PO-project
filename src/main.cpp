#include <iostream>
#include <string>

#include "../inc/Dr3D_gnuplot_api.hh"
#include "../inc/Dron.h"
#include "../inc/PoziomMorza.h"
#include "../inc/Dno.h"
#include "../inc/PrzeszkodaProstop.h"

using std::cout;
using std::cin;
using std::string;
using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;


int main()
{
    std::shared_ptr<drawNS::Draw3DAPI> api (new APIGnuPlot3D(-5,5,-5,5,-5,5,-1));        //program dziala na ref_time_ms ujemnych

    std::vector<std::shared_ptr<Dron>> kolekcjaDronow;
    std::vector<std::shared_ptr<InterfacePrzeszody>> kolekcjaPrzeszkod;
    std::shared_ptr<PrzeszkodaProstop> tmpPrz;





    char wybor;
    string wybor2, wybor3;
    /*std::cout<<"Czy chcesz podjąć personalizację? (Y/N)\n";
    do{
        cin>>wybor;
    }while(wybor!='Y'&&wybor!='N');

    if(wybor=='Y')                                 //DO UZUPEŁNIENIA
    {
        cout<<"Kolor drona sterowanego: ";
        cin>>wybor2;
        dronSterowany.zmienKolor(wybor2);
        cout<<""
    }*/

    std::shared_ptr<Dron> dronSterowany(new Dron(10));                                                              //przy duzych predkosciach pojawiaja sie znaczące bledy obliczeniowe
    Dno dno;
    PoziomMorza morze(0.25,4,10,1);
    dronSterowany->zmienKolor("red");
    dronSterowany->ustawApi(api);
    dno.ustawApi(api);
    morze.ustawApi(api);
    dno.Rysuj();

    for(int i=0;i<5;i++)                                                              //DO ROZMIESZCZENIA
    {
        kolekcjaDronow.push_back(std::shared_ptr<Dron>(new Dron(10)));
        kolekcjaDronow[i]->ustawApi(api);
        kolekcjaDronow[i]->Rysuj();
    }

    for(int i=0;i<5;i++)                                                            //DO ROZMIESZCZENIA
    {
        tmpPrz = std::shared_ptr<PrzeszkodaProstop>(new PrzeszkodaProstop(i+1,i+2,i+1));
        tmpPrz->ustawApi(api);
        tmpPrz->Rysuj();
        kolekcjaPrzeszkod.push_back(tmpPrz);
    }

    //TYMCZASOWE
    for(int i=0;i<5;i++)
    {
        if(kolekcjaDronow[i]->czyKolizja(dronSterowany))
        {
            cout<<"Kolizja z dronem\n";
        }
        if(kolekcjaPrzeszkod[i]->czyKolizja(dronSterowany))
        {
            cout<<"Kolizja z przeszkodą\n";
        }
    }

    morze.Rysuj();
    dronSterowany->Rysuj();

    do{
        cout<<"\nWybierz akcję:\n";
        cout<<"p - plyn do przodu pod zadanym kątem\n";
        cout<<"o - obróć w miejscu o zadany kąt\n";
        cout<<"q - wyjdź z aplikacji\n";
        cout<<"s - wyswietl statystyki\n";


        cin>>wybor;

        switch(wybor)
        {
            case 'p':
            cout<<"Jak daleko płynąć?\n";
            cin>>wybor2;
            cout<<"Pod jakim kątem płynąć?\n";
            cin>>wybor3;
            dronSterowany->plynDoPrzodu(std::stod(wybor2),std::stod(wybor3));
            break;

            case 'o':
            cout<<"O jaki kąt się obrócić?\n";
            cin>>wybor2;
            dronSterowany->obrocWOsiZ(std::stod(wybor2));
            break;

            case 's':
            cout<<"-----------------------------------\n";
            cout<<"Stworzono "<<Wektor3D::zwrocLiczbePowstalych()<<" wektorów\n";
            cout<<"Istnieje "<<Wektor3D::zwrocLiczbeIstniejacych()<<" wektorów\n";
            cout<<"Stworzono "<<Bryla::zwrocLiczbePowstalych()<<" brył\n";
            cout<<"Istnieje "<<Bryla::zwrocLiczbeIstniejacych()<<" brył\n";
            cout<<"-----------------------------------\n";
            for(int i=0;i<5;i++)
            {
                if(kolekcjaDronow[i]->czyKolizja(dronSterowany))
                {
                    cout<<"Kolizja z dronem\n";
                }
                if(kolekcjaPrzeszkod[i]->czyKolizja(dronSterowany))
                {
                    cout<<"Kolizja z przeszkodą\n";
                }
            }

            break;

            case 'q':
            break;

            default:
            cout<<"Nie rozpoznano znaku, spróbuj jeszcze raz\n\n";
            break;
        }
    }while(wybor!='q');

return 0;
}
