#ifndef OBIEKTRYSOWALNY_H
#define OBIEKTRYSOWALNY_H

#include "Dr3D_gnuplot_api.hh"
#include <string>

class ObiektRysowalny{

protected:
    int id;                                      //kiedy nie jest narysowany (nie ma rysunku o jego id)
    std::shared_ptr<drawNS::Draw3DAPI> drawingApi;
    std::string kolor;

public:
    virtual int Rysuj() = 0;
    void ustawApi(std::shared_ptr<drawNS::Draw3DAPI> api);
    void zmienKolor(std::string kolorObiektu);
    ObiektRysowalny():id(-1){this->kolor = "black";}

};


#endif
