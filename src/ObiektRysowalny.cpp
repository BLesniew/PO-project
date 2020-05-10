#include "../inc/ObiektRysowalny.h"

void ObiektRysowalny::ustawApi(std::shared_ptr<drawNS::Draw3DAPI> api)
{
    drawingApi = api;
}

void ObiektRysowalny::zmienKolor(std::string kolorObiektu)
{
    this->kolor = kolorObiektu;
}
