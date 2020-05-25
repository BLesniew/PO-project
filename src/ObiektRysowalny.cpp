#include "../inc/ObiektRysowalny.h"

void ObiektRysowalny::ustawApi(std::shared_ptr<drawNS::Draw3DAPI> api)
{
    drawingApi = api;
}

void ObiektRysowalny::zmienKolor(std::string kolorObiektu)
{
    this->kolor = kolorObiektu;
}


void ObiektRysowalny::Wymaz()
{
    if(this->id>=0)
    {
        drawingApi->erase_shape(this->id);
        drawingApi->redraw();
        this->id=-1;
    }
    else
    {
        std::cerr<<"Podany obiekt nie jest narysowany\n";
    }
}
