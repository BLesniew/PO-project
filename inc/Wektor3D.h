#ifndef WEKTOR3D_H
#define WEKTOR3D_H

#include "../inc/wektor.h"

class Wektor3D:public Wektor<double, 3>{

public:
    using Wektor::Wektor;                                            //uzywa konstruktorow dla wektora
    Wektor3D(double x,double y,double z);
};

#endif
