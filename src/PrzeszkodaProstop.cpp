#include "../inc/PrzeszkodaProstop.h"


bool PrzeszkodaProstop::czyKolizja(std::shared_ptr<InterfaceDrona> dronSterowany)
{
    double xMin = this->wierzcholki[0][0][0];
    double xMax = this->wierzcholki[0][0][0];
    double yMin = this->wierzcholki[0][0][1];
    double yMax = this->wierzcholki[0][0][1];
    double zMin = this->wierzcholki[0][0][2];
    double zMax = this->wierzcholki[0][0][2];
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(this->wierzcholki[i][j][0]>xMax)
                xMax = this->wierzcholki[i][j][0];
            if(this->wierzcholki[i][j][0]<xMin)
                xMin = this->wierzcholki[i][j][0];

            if(this->wierzcholki[i][j][1]>yMax)
                yMax = this->wierzcholki[i][j][1];
            if(this->wierzcholki[i][j][1]<yMin)
                yMin = this->wierzcholki[i][j][1];

            if(this->wierzcholki[i][j][2]>zMax)
                zMax = this->wierzcholki[i][j][2];
            if(this->wierzcholki[i][j][2]<zMin)
                zMin = this->wierzcholki[i][j][2];
        }
    }

    xMin-=dronSterowany->zwrocPromien();
    yMin-=dronSterowany->zwrocPromien();
    zMin-=dronSterowany->zwrocPromien();

    xMax+=dronSterowany->zwrocPromien();
    yMax+=dronSterowany->zwrocPromien();
    zMax+=dronSterowany->zwrocPromien();


    return (dronSterowany->zwrocPozycje()[0]>=xMin&&dronSterowany->zwrocPozycje()[1]>=yMin&&dronSterowany->zwrocPozycje()[2]>=zMin &&
        dronSterowany->zwrocPozycje()[0]<=xMax&&dronSterowany->zwrocPozycje()[1]<=yMax&&dronSterowany->zwrocPozycje()[2]<=zMax);
}
