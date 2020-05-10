#include "../inc/Macierz3na3.h"




Macierz3na3::Macierz3na3(const Wektor3D & wek1,const Wektor3D & wek2,const Wektor3D & wek3)
{
    this->tab[0]=wek1;
    this->tab[1]=wek2;
    this->tab[2]=wek3;
}



/*
Macierz3na3 & Macierz3na3::operator = (const MacierzKw<double,3> &MKw)
{
    for(int i=0;i<3;i++)
    {
        this->tab[0]=MKw[0];
    }
}
*/
