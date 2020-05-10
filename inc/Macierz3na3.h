#ifndef MACIERZ3NA3_H
#define MACIERZ3NA3_H
#include "../inc/MacierzKw.h"
#include "../inc/Wektor3D.h"

class Macierz3na3:public MacierzKw<double,3>{

public:
    using MacierzKw::MacierzKw;                              //dziedziczenie konstruktorów MacierzKw
    using MacierzKw::operator=;                              //umozliwia przyrownanie obiektu Macierz3na3 do obiektu MacierzKw
    Macierz3na3(const Wektor3D & wek1,const Wektor3D & wek2,const Wektor3D & wek3);
    //Macierz3na3 & operator = (const MacierzKw<double,3> &MKw);

};


#endif // MACIERZ3NA3_H
