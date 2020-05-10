#include <iostream>
#include "../inc/ObiektRysowalny.h"
#include "../inc/MacierzObrotu.h"
#include "../inc/Bryla.h"
#include "../inc/Dr3D_gnuplot_api.hh"
#include "../inc/Dron.h"

using std::vector;
using std::cout;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;


int main()
{
    std::shared_ptr<drawNS::Draw3DAPI> api (new APIGnuPlot3D(-5,5,-5,5,-5,5,-1));        //program dziala dla ref_time_ms ujemnych
    Dron dronSterowany;
    dronSterowany.zmienKolor("blue");
    dronSterowany.ustawPredkosc(2);                                                     //predkosc nie ma wartosci podstawowej, do naprawienia
    dronSterowany.ustawApi(api);
    dronSterowany.Rysuj();

    do{

    }while(std::cin.get()!='\n');

    dronSterowany.plynDoPrzodu(2);

    do{

    }while(std::cin.get()!='\n');

    dronSterowany.obrocWOsiZ(30);

    do{

    }while(std::cin.get()!='\n');

    dronSterowany.plynDoPrzodu(2,15);

    do{

    }while(std::cin.get()!='\n');

return 0;
}
