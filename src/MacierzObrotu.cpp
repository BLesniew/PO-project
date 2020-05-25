#include "../inc/MacierzObrotu.h"

MacierzObrotu::MacierzObrotu()
{
    this->tab[0]=Wektor3D(1,0,0);
    this->tab[1]=Wektor3D(0,1,0);
    this->tab[2]=Wektor3D(0,0,1);
}


MacierzObrotu::MacierzObrotu(Wektor<double,3> *wek)
{
    this->tab[0]=wek[0];
    this->tab[1]=wek[1];
    this->tab[2]=wek[2];
    if(abs(this->wyznacznik()-1)>BLAD_PRZYROWNANIA)
    {
    std::cerr<<"WYZNACZNIK ROWNY "<<this->wyznacznik()<<", TO NIE MACIERZ OBROTU\n";
    exit (1);
    }
}


MacierzObrotu::MacierzObrotu(const Macierz3na3 & macierz)
{
    this->tab[0] = macierz[0];
    this->tab[1] = macierz[1];
    this->tab[2] = macierz[2];
    if(abs(this->wyznacznik()-1)>BLAD_PRZYROWNANIA)
    {
    std::cerr<<"WYZNACZNIK ROWNY "<<this->wyznacznik(Gauss)<<", TO NIE MACIERZ OBROTU\n";
    exit (2);
    }
}

MacierzObrotu::MacierzObrotu(const MacierzKw<double,3> & macierz)
{
    Macierz3na3 tmp;
    tmp = macierz;
    *this = tmp;
}
