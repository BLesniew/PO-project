#include "../inc/Wektor3D.h"

Wektor3D::Wektor3D(double x, double y, double z)
{
    this->tab[0]=x;
    this->tab[1]=y;
    this->tab[2]=z;
}

Wektor3D::Wektor3D(Wektor<double,3>wek)
{
    this->tab[0]=wek[0];
    this->tab[1]=wek[1];
    this->tab[2]=wek[2];
}

