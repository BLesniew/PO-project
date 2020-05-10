#ifndef MACIERZOBROTU_H
#define MACIERZOBROTU_H
#include "Macierz3na3.h"

class MacierzObrotu:public Macierz3na3{

public:
    MacierzObrotu();
    MacierzObrotu(Wektor<double,3> *wek);                                                                          //nie działało dziedziczenie konstruktorów
    MacierzObrotu(Wektor3D wek1,Wektor3D wek2,Wektor3D wek3):Macierz3na3(wek1,wek2,wek3){if(abs(this->wyznacznik()-1>BLAD_PRZYROWNANIA)){std::cerr<<"TO NIE MACIERZ OBROTU"; exit (1);}}
    void operator=(const Macierz3na3 & macierz);
    void operator=(const MacierzKw<double,3> & macierz);

};



#endif // MACIERZOBROTU_H
