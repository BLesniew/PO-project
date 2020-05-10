#include "../inc/Bryla.h"




void Bryla::ObrocOKat(double katWStopniach, Axis osObrotu)
{
double alpha = -M_PI*katWStopniach/180;
    switch(osObrotu)
    {
        case OX:
            this->macierzObrotu = this->macierzObrotu * MacierzObrotu(Wektor3D(1,0,0),Wektor3D(0,std::cos(alpha),-std::sin(alpha)),Wektor3D(0,std::sin(alpha),std::cos(alpha)));
        break;

        case OY:
            this->macierzObrotu =  this->macierzObrotu * MacierzObrotu(Wektor3D(std::cos(alpha),0,std::sin(alpha)),Wektor3D(0,1,0),Wektor3D(-std::sin(alpha),0,std::cos(alpha)));
        break;

        case OZ:
            this->macierzObrotu = this->macierzObrotu * MacierzObrotu(Wektor3D(std::cos(alpha),-std::sin(alpha),0),Wektor3D(std::sin(alpha),std::cos(alpha),0),Wektor3D(0,0,1));
            //std::cout<<macierzObrotu;
        break;
    }
}

void Bryla::ObrocOKat(double alpha)
{
    ObrocOKat(alpha, OZ);
}

void Bryla::Przenies(const Wektor3D & wektorPrzesuniecia)
{
    this->pozycjaSrodka += wektorPrzesuniecia;
}

Bryla::Bryla(const Wektor3D & pozycja)
{
    this->pozycjaSrodka = pozycja;
}

Bryla::Bryla()
{
    this->pozycjaSrodka = Wektor3D();
    this->macierzObrotu = MacierzObrotu();
}
