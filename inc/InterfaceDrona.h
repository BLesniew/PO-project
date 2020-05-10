#ifndef INTERFACEDRONA_H
#define INTERFACEDRONA_H

class InterfaceDrona{

public:
    virtual void plynDoPrzodu(double odleglosc,double katWznoszenia)=0;
    virtual void plynDoPrzodu(double odleglosc)=0;
    virtual void obrocWOsiZ(double katObrotu)=0;
};


#endif
