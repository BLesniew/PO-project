#ifndef PRZESZKODA_PROSTOP_H
#define PRZESZKODA_PROSTOP_H

#include "InterfaceDrona.h"
#include "InterfejsPrzeszkody.h"
#include "Prostopadloscian.h"

class PrzeszkodaProstop:public InterfacePrzeszody,public Prostopadloscian{

public:
    bool czyKolizja(std::shared_ptr<InterfaceDrona> dronSterowany) override;           //póki co przeszkody równoległe do osi

    using Prostopadloscian::Prostopadloscian;                                         //używa kostruktorów prostopadloscianu

};

#endif // PRZESZKODA_PROSTOP_H
