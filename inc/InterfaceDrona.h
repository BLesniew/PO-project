#ifndef INTERFACEDRONA_H
#define INTERFACEDRONA_H

#include "Wektor3D.h"

class InterfaceDrona{

public:
    virtual void plynDoPrzodu(double odleglosc,double katWznoszenia)=0;
    virtual void plynDoPrzodu(double odleglosc)=0;
    virtual void obrocWOsiZ(double katObrotu)=0;

    virtual double zwrocPromien()=0;
    virtual Wektor3D zwrocPozycje()=0;
};


#endif
