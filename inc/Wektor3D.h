#ifndef WEKTOR3D_H
#define WEKTOR3D_H

#include "../inc/wektor.h"

class Wektor3D:public Wektor<double, 3>{

public:
    using Wektor::Wektor;                                            //uzywa konstruktorow dla wektora
    Wektor3D(double x,double y,double z);
    Wektor3D(Wektor<double,3> wek);

    static int zwrocLiczbeIstniejacych();
    static int zwrocLiczbePowstalych();
    Wektor3D(const Wektor3D & tmp){*this = tmp;ileIstnieje++;ileStworzono++;}
    ~Wektor3D(){ileIstnieje--;}
};

#endif
