#include "../inc/PoziomMorza.h"

void PoziomMorza::Rysuj()
{
    int ileKratek=0;
    ileKratek = this->wielkoscPlaszczyzny/this->wielkoscKratki;
    ileKratek++;
    vector<vector<Point3D>> punkty = vector<vector<Point3D>>(ileKratek,vector<Point3D>(ileKratek,Point3D(0,0,0)));
    for(int i=0;i<ileKratek;i++)
    {
        for(int j=0;j<ileKratek;j++)
        {
            if(j%2==0)
                punkty[i][j] = Point3D(-this->wielkoscPlaszczyzny/2+j*this->wielkoscKratki,-this->wielkoscPlaszczyzny/2+i*this->wielkoscKratki,this->wspolrzednaZ+this->wysokoscFal);
            else
                punkty[i][j] = Point3D(-this->wielkoscPlaszczyzny/2+j*this->wielkoscKratki,-this->wielkoscPlaszczyzny/2+i*this->wielkoscKratki,this->wspolrzednaZ-this->wysokoscFal);
        }
    }
    this->id = this->drawingApi->draw_surface(punkty,this->kolor);
    this->drawingApi->redraw();
}


bool PoziomMorza::czyKolizja(std::shared_ptr<InterfaceDrona> dronSterowany)
{
    return (dronSterowany->zwrocPozycje()[2]>=this->wspolrzednaZ);
}
