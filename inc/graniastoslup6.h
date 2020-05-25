#ifndef GRANIASTOSLUP_6
#define GRANIASTOSLUP_6

#include "Bryla.h"
using std::vector;
using drawNS::Point3D;

class Graniastoslup6:public Bryla{

protected:
    double wysokosc;
    double odlegloscOdSrodkaPdst;
    vector<vector<Point3D>> wierzcholki = vector<vector<Point3D>>(2,vector<Point3D>(6,Point3D(0,0,0)));              //2 poziomy po 6 punktów

public:
    void Rysuj() override;
    void aktualizujPolozenie();

    Graniastoslup6();
    Graniastoslup6(double wysokoscGran, double dlugoscBokuPodstawy);


};




#endif // GRANIASTOSLUP_6
