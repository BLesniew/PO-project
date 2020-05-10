#ifndef BRYLA_H
#define BRYLA_H

#include "ObiektRysowalny.h"
#include "MacierzObrotu.h"
#include "Wektor3D.h"

#include <cmath>
# define M_PI           3.14159265358979323846  /* pi */

enum Axis{OX,OY,OZ};

class Bryla:public ObiektRysowalny{

protected:
MacierzObrotu macierzObrotu;
Wektor3D pozycjaSrodka;

void ObrocOKat(double alpha,Axis osObrotu);
void Przenies(const Wektor3D & wektorPrzesuniecia);

public:
    Bryla();

    //Bryla(MacierzObrotu obrot);
    //Bryla(Wektor3D pozycja, MacierzObrotu obrot);

    virtual int Rysuj() = 0;
    virtual void aktualizujPolozenie() = 0;
    Bryla(const Wektor3D & pozycja);
    void ObrocOKat(double alpha);
};



#endif
