#include "../inc/Dno.h"

bool Dno::czyKolizja(std::shared_ptr<InterfaceDrona> dronSterowany)
{
    return (this->wspolrzednaZ+dronSterowany->zwrocPromien()>=dronSterowany->zwrocPozycje()[2]);
}
