#include "../inc/graniastoslup6.h"


void Graniastoslup6::Rysuj()
{
    this->aktualizujPolozenie();
    if(this->id>=0)
    {
        drawingApi->erase_shape(this->id);
    }

    this->id = drawingApi->draw_polyhedron(this->wierzcholki,this->kolor);
    drawingApi->redraw();
}

void Graniastoslup6::aktualizujPolozenie()
{
    this->wierzcholki[0][0] = (macierzObrotu*Wektor3D(-odlegloscOdSrodkaPdst,0,-wysokosc/2)+this->pozycjaSrodka);
    this->wierzcholki[0][1] = (macierzObrotu*Wektor3D(-odlegloscOdSrodkaPdst/2,odlegloscOdSrodkaPdst*sqrt(3)/2,-wysokosc/2)+this->pozycjaSrodka);
    this->wierzcholki[0][2] = (macierzObrotu*Wektor3D(odlegloscOdSrodkaPdst/2,odlegloscOdSrodkaPdst*sqrt(3)/2,-wysokosc/2)+this->pozycjaSrodka);
    this->wierzcholki[0][3] = (macierzObrotu*Wektor3D(odlegloscOdSrodkaPdst,0,-wysokosc/2)+this->pozycjaSrodka);
    this->wierzcholki[0][4] = (macierzObrotu*Wektor3D(odlegloscOdSrodkaPdst/2,-odlegloscOdSrodkaPdst*sqrt(3)/2,-wysokosc/2)+this->pozycjaSrodka);
    this->wierzcholki[0][5] = (macierzObrotu*Wektor3D(-odlegloscOdSrodkaPdst/2,-odlegloscOdSrodkaPdst*sqrt(3)/2,-wysokosc/2)+this->pozycjaSrodka);

    this->wierzcholki[1][0] = (macierzObrotu*Wektor3D(-odlegloscOdSrodkaPdst,0,wysokosc/2)+this->pozycjaSrodka);
    this->wierzcholki[1][1] = (macierzObrotu*Wektor3D(-odlegloscOdSrodkaPdst/2,odlegloscOdSrodkaPdst*sqrt(3)/2,wysokosc/2)+this->pozycjaSrodka);
    this->wierzcholki[1][2] = (macierzObrotu*Wektor3D(odlegloscOdSrodkaPdst/2,odlegloscOdSrodkaPdst*sqrt(3)/2,wysokosc/2)+this->pozycjaSrodka);
    this->wierzcholki[1][3] = (macierzObrotu*Wektor3D(odlegloscOdSrodkaPdst,0,wysokosc/2)+this->pozycjaSrodka);
    this->wierzcholki[1][4] = (macierzObrotu*Wektor3D(odlegloscOdSrodkaPdst/2,-odlegloscOdSrodkaPdst*sqrt(3)/2,wysokosc/2)+this->pozycjaSrodka);
    this->wierzcholki[1][5] = (macierzObrotu*Wektor3D(-odlegloscOdSrodkaPdst/2,-odlegloscOdSrodkaPdst*sqrt(3)/2,wysokosc/2)+this->pozycjaSrodka);

    /*
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<6;j++)
        {
            for(int k=0;k<3;k++)
                std::cout<<wierzcholki[i][j][k]<<" ";
            std::cout<<"\n";
        }
        std::cout<<"TERAZ DOL\n";
    }
    //std::cout<<macierzObrotu;
    */

}

Graniastoslup6::Graniastoslup6()
{
    this->odlegloscOdSrodkaPdst = 0.6;
    this->wysokosc = 0.5;
}

Graniastoslup6::Graniastoslup6(double wysokoscGran, double dlugoscBokuPodstawy)
{
    this->odlegloscOdSrodkaPdst = dlugoscBokuPodstawy;
    this->wysokosc = wysokoscGran;
}
