#include <iostream>
#include "../inc/ObiektRysowalny.h"
#include "../inc/MacierzObrotu.h"
#include "../inc/Bryla.h"
#include "../inc/Dr3D_gnuplot_api.hh"
#include "../inc/Dron.h"
#include "../inc/Plaszczyzna.h"
#include "../inc/PoziomMorza.h"
#include "../inc/Dno.h"

using std::vector;
using std::cout;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;


int main()
{
    std::shared_ptr<drawNS::Draw3DAPI> api (new APIGnuPlot3D(-5,5,-5,5,-5,5,-1));        //program dziala dla ref_time_ms ujemnych
    Dron dronSterowany(10);                                                              //przy duzych predkosciach pojawiaja sie znaczące bledy obliczeniowe
    Dno dno;
    PoziomMorza morze(0.25,4,10,1);
    dronSterowany.zmienKolor("red");
    dno.zmienKolor("yellow");
    dronSterowany.ustawApi(api);
    dno.ustawApi(api);
    morze.ustawApi(api);
    dno.Rysuj();
    morze.Rysuj();
    dronSterowany.Rysuj();



    do{

    }while(std::cin.get()!='\n');

    dronSterowany.plynDoPrzodu(2);
    //morze.Wymaz();

    do{

    }while(std::cin.get()!='\n');

    dronSterowany.obrocWOsiZ(30);

    do{

    }while(std::cin.get()!='\n');

    dronSterowany.obrocWOsiZ(45);

    do{

    }while(std::cin.get()!='\n');

    dronSterowany.obrocWOsiZ(285);

    do{

    }while(std::cin.get()!='\n');

    dronSterowany.plynDoPrzodu(2,15);

    do{

    }while(std::cin.get()!='\n');

return 0;
}
