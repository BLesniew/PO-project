#ifndef INTERFEJS_PRZESZKODY_H
#define INTERFEJS_PRZESZKODY_H

#include "InterfaceDrona.h"

#include <iostream>
#include <memory>

class InterfacePrzeszody{

protected:


public:
    virtual bool czyKolizja(std::shared_ptr<InterfaceDrona> dronSterowany)=0;


};


#endif
