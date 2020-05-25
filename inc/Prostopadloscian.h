#ifndef PROSTOPADLOSCIAN_H
#define PROSTOPADLOSCIAN_H

#include "Bryla.h"
using std::vector;
using drawNS::Point3D;

class Prostopadloscian:public Bryla{

protected:
    double dlugosc;
    double szerokosc;
    double wysokosc;
    vector<vector<Point3D>> wierzcholki=vector<vector<Point3D>>(2,vector<Point3D>(4,Point3D(0,0,0)));                      //2 poziomy po 4 punkty

public:
    void Rysuj() override;
    void aktualizujPolozenie() override;
    Prostopadloscian();
    //Prostopadloscian():wierzcholki[0][0](-1,-1,-1),wierzcholki[0][1](-1,1,-1),wierzcholki[0][2](1,1,-1),wierzcholki[0][3](1,-1,-1),
    //                    wierzcholki[1][0](-1,-1,1),wierzcholki[1][1](-1,1,1),wierzcholki[1]2](1,1,1),wierzcholki[1][3](1,-1,1) {}
    Prostopadloscian(double dlugoscX,double dlugoscY, double wysokosc);

};



#endif
